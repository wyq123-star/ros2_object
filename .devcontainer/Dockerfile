# 基础镜像（ROS Humble 桌面完整版）
FROM osrf/ros:humble-desktop-full

# 用户参数
ARG USERNAME=yutou
ARG USER_UID=1000
ARG USER_GID=$USER_UID

# ------------------------------
# 安装核心工具和ROS包
# ------------------------------
RUN apt-get update && \
    apt-get install -y \
        wget \
        ros-humble-nav2-bringup \
        ros-humble-gazebo-ros-pkgs \
        ros-humble-cartographer \
        ros-humble-cartographer-ros \
        gazebo \
        libgazebo-dev \
        ros-$ROS_DISTRO-joint-state-publisher-gui \
        ros-$ROS_DISTRO-robot-state-publisher && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# ------------------------------
# 安装Fish Shell和文件管理器
# ------------------------------
RUN apt-get update && \
    apt-get install -y \
        fish \
        gedit \
        ros-humble-rqt-tf-tree \
        ros-humble-foxglove-bridge \
        nautilus && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*
#sudo apt install ros-${ROS_DISTRO}-rqt-tf
# ------------------------------
# 创建用户并配置权限
# ------------------------------
RUN groupadd --gid $USER_GID $USERNAME && \
    useradd --uid $USER_UID --gid $USER_GID -m $USERNAME && \
    apt-get update && \
    apt-get install -y sudo && \
    echo "$USERNAME ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers

# ------------------------------
# 配置ROS环境
# ------------------------------
ENV ROS_DISTRO=humble
ENV ROS_SETUP_BASH="/opt/ros/humble/setup.bash"

# 为bash用户自动加载ROS环境
RUN echo "source $ROS_SETUP_BASH" >> /home/$USERNAME/.bashrc
RUN echo "source ${HOME}/ros2_ws/install/setup.bash" >> ~/.bashrc
# ------------------------------
# 切换用户和工作目录
# ------------------------------
USER $USERNAME
WORKDIR /home/$USERNAME

# 默认启动命令
CMD ["/bin/bash"]