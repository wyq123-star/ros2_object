# ~/.config/fish/completions/ros2.fish

# 补全 ros2 的常见子命令
complete -c ros2 -n "__fish_use_subcommand" -a "run topic node action service bag pkg launch param component"

# ---------------------------
# ros2 run 补全
# ---------------------------
# 补全 ros2 run 后面的包名
complete -c ros2 -n "__fish_seen_subcommand_from run" -a "(ros2 pkg list)"
# 补全 ros2 run 后面的可执行文件
complete -c ros2 -n "__fish_seen_subcommand_from run" -a "(ros2 pkg executables (ros2 pkg list))"

# ---------------------------
# ros2 topic 补全
# ---------------------------
complete -c ros2 -n "__fish_seen_subcommand_from topic" -a "list echo pub info hz delay type"
complete -c ros2 -n "__fish_seen_subcommand_from topic" -a "(ros2 topic list)"

# ---------------------------
# ros2 node 补全
# ---------------------------
complete -c ros2 -n "__fish_seen_subcommand_from node" -a "list info"
complete -c ros2 -n "__fish_seen_subcommand_from node" -a "(ros2 node list)"

# ---------------------------
# ros2 action 补全
# ---------------------------
complete -c ros2 -n "__fish_seen_subcommand_from action" -a "list server info"
complete -c ros2 -n "__fish_seen_subcommand_from action" -a "(ros2 action list)"

# ---------------------------
# ros2 service 补全
# ---------------------------
complete -c ros2 -n "__fish_seen_subcommand_from service" -a "list call type info"
complete -c ros2 -n "__fish_seen_subcommand_from service" -a "(ros2 service list)"

# ---------------------------
# ros2 launch 补全
# ---------------------------
complete -c ros2 -n "__fish_seen_subcommand_from launch" -a "(ros2 launch --help)"

# ---------------------------
# ros2 param 补全
# ---------------------------
complete -c ros2 -n "__fish_seen_subcommand_from param" -a "get set list describe"
complete -c ros2 -n "__fish_seen_subcommand_from param" -a "(ros2 param list)"

# ---------------------------
# ros2 pkg 补全
# ---------------------------
complete -c ros2 -n "__fish_seen_subcommand_from pkg" -a "list create info"
# create 后面补全包名（可选，根据自己习惯）
complete -c ros2 -n "__fish_seen_subcommand_from pkg" -a "(ros2 pkg list)"
# info 后面补全包名
complete -c ros2 -n "__fish_seen_subcommand_from pkg" -a "(ros2 pkg list)"

