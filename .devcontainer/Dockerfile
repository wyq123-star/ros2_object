FROM osrf/ros:humble-desktop-full

ARG USERNAME=yutou
ARG USER_UID=1000
ARG USER_GID=$USER_UID

# 安装基础工具（包括 wget）
RUN apt-get update && \
    apt-get install -y wget ros-humble-nav2-bringup ros-humble-gazebo-ros-pkgs ros-humble-cartographer && \
    apt-get install gazebo libgazebo-dev ros-$ROS_DISTRO-joint-state-publisher-gui ros-$ROS_DISTRO-robot-state-publisher&& \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*
# sudo apt install ros-humble-cartographer-ros
#克隆元马
#git clone https://ghproxy.com/https://github.com/ros2/cartographer.git -b ros2
#git clone https://ghproxy.com/https://github.com/ros2/cartographer_ros.git -b ros2

###

# 安装 Fish Shell 和 Nautilus
RUN apt-get update && \
    apt-get install -y fish nautilus && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# 创建用户并设置主目录
RUN groupadd --gid $USER_GID $USERNAME && \
    useradd --uid $USER_UID --gid $USER_GID -m $USERNAME && \
    apt-get update && apt-get install -y sudo && \
    echo "$USERNAME ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers

# 设置 ROS 环境变量
ENV ROS_DISTRO=humble
ENV ROS_SETUP_BASH="/opt/ros/humble/setup.bash"

# 自动 source ROS 环境（仅 bash）
RUN echo "source $ROS_SETUP_BASH" >> /home/$USERNAME/.bashrc


# 切换用户并设置工作目录
USER $USERNAME
WORKDIR /home/$USERNAME

# 默认入口
CMD ["/bin/bash"]