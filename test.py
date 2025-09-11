import cv2

def main():
    # 初始化摄像头，0 代表系统默认摄像头
    # 如果有多个摄像头，可以尝试将 0 替换为 1, 2 等
    cap = cv2.VideoCapture('/dev/video0')
    
    # 检查摄像头是否成功打开
    if not cap.isOpened():
        print("❌ 错误：无法打开摄像头。请检查：")
        print("   - 摄像头是否连接正确")
        print("   - 是否有其他程序占用了摄像头")
        print("   - 系统是否授予了摄像头访问权限")
        return

    # 可选：设置摄像头参数（分辨率等）
    cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)   # 设置帧宽度
    cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)  # 设置帧高度
    
    print("🎥 摄像头已成功开启！")
    print("📌 操作提示：")
    print("   - 按 'q' 键：退出程序")
    print("   - 按 's' 键：保存当前帧为图片")
    print("   - 按 'g' 键：切换灰度显示模式")
    
    is_grayscale = False  # 灰度模式状态标识

    try:
        while True:
            # 逐帧捕获
            ret, frame = cap.read()
            
            # 如果读取帧失败，退出循环
            if not ret:
                print("❌ 无法从摄像头接收帧（流结束？）。程序退出...")
                break

            # 根据模式决定显示原图还是灰度图
            if is_grayscale:
                display_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
                window_name = 'Camera - Grayscale Mode'
            else:
                display_frame = frame
                window_name = 'Camera - Normal Mode'

            # 显示结果帧
            cv2.imshow(window_name, display_frame)

            # 键盘输入处理
            key = cv2.waitKey(1) & 0xFF  # 获取按键值
            
            if key == ord('q'):  # 按 'q' 退出
                print("👋 程序退出。")
                break
            elif key == ord('s'):  # 按 's' 保存截图
                cv2.imwrite('captured_image.jpg', frame)
                print("📸 当前帧已保存为 'captured_image.jpg'")
            elif key == ord('g'):  # 按 'g' 切换灰度模式
                is_grayscale = not is_grayscale
                mode = "灰度" if is_grayscale else "彩色"
                print(f"🔁 已切换至 {mode} 显示模式")

    finally:
        # 释放摄像头资源并关闭所有 OpenCV 窗口
        cap.release()
        cv2.destroyAllWindows()
        print("✅ 摄像头资源已释放。")

if __name__ == "__main__":
    main()
