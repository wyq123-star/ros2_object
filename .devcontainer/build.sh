docker build -t yutou/ros2_container:part1 .

docker image prune -f  # 强制清理none镜像

# docker build -t yutou/ros2_container:latest . --no-cache  #  无缓存构建镜像