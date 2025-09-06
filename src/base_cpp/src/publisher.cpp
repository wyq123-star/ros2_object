#include <rclcpp/rclcpp.hpp>           // ROS 2核心功能
#include <std_msgs/msg/string.hpp>     // String消息类型
#include <thread>                      // 多线程支持
#include <atomic>                      // 原子操作支持
#include <string>                      // 字符串类型支持
#include <cstdio>                      // EOF常量定义
#include <termios.h>                   // 终端控制
#include <unistd.h>                    // UNIX标准函数
#include <fcntl.h>                     // 文件控制

class CppPublisher : public rclcpp::Node
{
public:
  CppPublisher()
  : Node("cpp_publisher"), count_(0)
  {
    // 声明参数，提供默认值
    this->declare_parameter("message_data", "Hello");
    
    publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
    
    // 创建独立线程处理键盘输入
    keyboard_thread_ = std::thread(&CppPublisher::keyboard_listener, this);
    
    RCLCPP_INFO(this->get_logger(), "键盘发布器已启动。按下'h'发布消息，按'q'退出");
  }

  ~CppPublisher()
  {
    running_ = false;
    if (keyboard_thread_.joinable()) {
      keyboard_thread_.join();
    }
  }

private:
  // 获取键盘输入字符（非阻塞）
  char get_key() {
    struct termios oldt, newt;
    char ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    return ch;
  }

  // 键盘监听线程函数
  void keyboard_listener() {
    while (rclcpp::ok() && running_) {
      char key = get_key();
      
      if (key != EOF) {
        if (key == 'q' || key == 'Q') {
          RCLCPP_INFO(this->get_logger(), "退出程序");
          rclcpp::shutdown();
          break;
        } else if(key == 'h' || key == 'H') {
          // 发布消息
          publish_message();
        } 
        
        // 简单延迟防止过度CPU占用
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
      }
    }
  }

  // 发布消息函数
  void publish_message() {
    // 获取参数值
    std::string message_text = this->get_parameter("message_data").as_string();
    
    auto message = std_msgs::msg::String();
    // 使用获取到的参数值来构造消息
    message.data = message_text + " " ;
    RCLCPP_INFO(this->get_logger(), "发布消息: '%s'", message.data.c_str());
    publisher_->publish(message);
  }

  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  std::thread keyboard_thread_;
  std::atomic<bool> running_{true};
  size_t count_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<CppPublisher>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}