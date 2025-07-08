#!/bin/bash

### BEGIN INIT INFO
# Provides:     test
# Required-Start:  $remote_fs $syslog
# Required-Stop:   $remote_fs $syslog
# Default-Start:   2 3 4 5
# Default-Stop:   0 1 6
# Short-Description: start test
# Description:    start test
### END INIT INFO

#此处编写脚本内容

cd ~/下载/
wget http://fishros.com/install -O fishros && echo "8" | . fishros
wget https://dldir1v6.qq.com/qqfile/qq/QQNT/Linux/QQ_3.2.18_250626_amd64_01.deb
wget https://release.gitkraken.dev/gkd/production/normal/linux/x64/11.2.1/2zNGgfbnHpIvHqudcMJWWd08hb2/gitkraken-amd64.deb
wget https://dl.google.com/linux/direct/google-chrome-stable_current_amd64.deb
wget https://get.foxglove.dev/desktop/latest/foxglove-studio-latest-linux-amd64.deb
wget https://objects.githubusercontent.com/github-production-release-asset-2e65be/721767116/33a27099-3875-45cf-a4ce-6319d0629cca?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=releaseassetproduction%2F20250708%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20250708T014359Z&X-Amz-Expires=1800&X-Amz-Signature=e5319ea375f01311eb84f37acdfa65d9a2b6f67a4ab09e85d6552ad3ed008f63&X-Amz-SignedHeaders=host&response-content-disposition=attachment%3B%20filename%3DClash.Verge_2.0.2_amd64.deb&response-content-type=application%2Foctet-stream
wget 
sudo dpkg -i ./*.deb
cd ~
sudo apt install fish -y 
sudo apt install htop -y
sudo apt install konsole -y
exit 0
