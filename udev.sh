#!/bin/bash

# USB Camera Udev Rule Auto-Setup Script
# 此脚本将自动为两个特定的USB相机创建udev规则，提供固定的设备名称

# 检查脚本是否以root权限运行
if [ "$EUID" -ne 0 ]; then
    echo "❌ 请使用 sudo 运行此脚本（需要root权限来修改udev规则）"
    exit 1
fi

# 定义规则文件路径
RULES_FILE="/etc/udev/rules.d/usb-cameras.rules"

# 提示信息
echo "🔧 开始为USB相机创建udev规则..."
echo "📝 规则文件将创建在: $RULES_FILE"
echo ""

# 备份现有的规则文件（如果存在）
if [ -f "$RULES_FILE" ]; then
    BACKUP_FILE="$RULES_FILE.bak.$(date +%Y%m%d_%H%M%S)"
    cp "$RULES_FILE" "$BACKUP_FILE"
    echo "📦 已备份现有规则文件: $BACKUP_FILE"
fi

# 创建udev规则内容
echo "📝 写入udev规则到 $RULES_FILE ..."
cat > "$RULES_FILE" << 'EOL'
# 自动生成的USB相机udev规则
# ARC International Camera (ID 05a3:9230)
SUBSYSTEM=="video4linux", ATTRS{idVendor}=="05a3", ATTRS{idProduct}=="9230", SYMLINK+="usb_cam_arc", GROUP="video", MODE="0666"
# icSpring camera (ID 2993:0858)
SUBSYSTEM=="video4linux", ATTRS{idVendor}=="2993", ATTRS{idProduct}=="0858", SYMLINK+="usb_cam_icspring", GROUP="video", MODE="0666"
EOL

# 重新加载udev规则
echo "🔄 重新加载udev规则..."
udevadm control --reload-rules
udevadm trigger

echo "✅ 完成！udev规则已设置并重新加载。"
echo ""
echo "📋 规则详情:"
echo "   - ARC International Camera (05a3:9230) 将固定为: /dev/usb_cam_arc"
echo "   - icSpring camera (2993:0858) 将固定为: /dev/usb_cam_icspring"
echo ""
echo "💡 提示: 重新插拔USB相机后，新的符号链接将会生效。"
echo "   您可以使用 'ls -l /dev/usb_cam_*' 来检查设备链接。"