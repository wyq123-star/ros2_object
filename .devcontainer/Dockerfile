FROM osrf/ros:humble-desktop-full

ARG USERNAME=yutou
ARG USER_UID=1000
ARG USER_GID=$USER_UID

RUN apt-get update && apt-get install -y ros-humble-nav2-bringup

# 安装 Fish Shell 和 Nautilus
RUN apt-get update && \
    apt-get install -y fish nautilus && \
    # 清理缓存以减小镜像体积
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# 创建用户并设置主目录
RUN groupadd --gid $USER_GID $USERNAME && \
    useradd --uid $USER_UID --gid $USER_GID -m $USERNAME && \
    # 可选：赋予 sudo 权限
    apt-get update && apt-get install -y sudo && \
    echo "$USERNAME ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers

# 设置 ROS 环境变量
ENV ROS_DISTRO=humble
ENV ROS_SETUP_BASH="/opt/ros/humble/setup.bash"

# 让 bash 在每次启动时自动 source ROS 环境
RUN echo "source $ROS_SETUP_BASH" >> /home/$USERNAME/.bashrc

# 切换用户并设置工作目录
USER $USERNAME
WORKDIR /home/$USERNAME

RUN fish -c 'curl -sL https://git.io/fisher | source && fisher install jorgebucaran/fisher && fisher install edc/bass' && \
    mkdir -p /home/$USERNAME/.config/fish && \
    echo 'bass source /opt/ros/humble/setup.bash' >> /home/$USERNAME/.config/fish/config.fish && \
    echo 'bass source ~/ros2_ws/install/setup.bash' >> /home/$USERNAME/.config/fish/config.fish && \
    chown -R $USERNAME:$USERNAME /home/$USERNAME/.config/fish

# 默认入口
CMD ["/bin/bash"]