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
        pip \
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
        nautilus \
        curl && \  
    pip install pyserial && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# ------------------------------
# 创建用户并配置权限
# ------------------------------
RUN groupadd --gid $USER_GID $USERNAME && \
    useradd --uid $USER_UID --gid $USER_GID -m $USERNAME && \
    apt-get update && \
    apt-get install -y sudo && \
    echo "$USERNAME ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers && \
    usermod -a -G dialout $USERNAME
    # usermod -a -G dialout $USERNAME
# ------------------------------
# 安装 Fisher 和 bass（在用户目录下）
# ------------------------------
# 切换到用户目录安装
USER $USERNAME
WORKDIR /home/$USERNAME

# 创建 Fish 配置目录
RUN mkdir -p .config/fish/functions && \
    curl -sL https://git.io/fisher > .config/fish/functions/fisher.fish
    
# 安装 bass 插件
RUN /usr/bin/fish -c "fisher install edc/bass"

# ------------------------------
# 配置ROS环境
# ------------------------------
ENV ROS_DISTRO=humble
ENV ROS_SETUP_BASH="/opt/ros/humble/setup.bash"

# 为bash用户自动加载ROS环境
RUN echo "source $ROS_SETUP_BASH" >> /home/$USERNAME/.bashrc && \
    echo "source /home/yutou/ros2_ws/install/setup.bash" >> /home/$USERNAME/.bashrc

# # 为fish用户配置ROS环境（可选）
RUN echo 'bass source /opt/ros/humble/setup.bash' >> /home/$USERNAME/.config/fish/config.fish && \
    echo 'bass source ~/ros2_ws/install/setup.bash' >> /home/$USERNAME/.config/fish/config.fish && \
    echo 'source ~/ros2_ws/.config/fish/completions/ros2.fish' >> /home/$USERNAME/.config/fish/config.fish

# ------------------------------
# 设置工作目录和默认命令
# ------------------------------
WORKDIR /home/$USERNAME

# 默认启动命令
CMD ["/usr/bin/fish"]