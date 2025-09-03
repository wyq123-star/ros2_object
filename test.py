import serial

# 定义要使用的串口设备
port_name = '/dev/ttyUSB0'  # 在Linux系统中，USB转串口设备通常以此命名

try:
    # 创建并配置串口对象
    ser = serial.Serial(
        port=port_name,       # 串口设备名称
        baudrate=921600,      # 波特率，需与设备设置一致
        bytesize=serial.EIGHTBITS,  # 数据位，8位
        parity=serial.PARITY_NONE,  # 校验位，无
        stopbits=serial.STOPBITS_ONE, # 停止位，1位
        timeout=2             # 读超时时间（秒）
    )
    
    # 检查串口是否成功打开
    if ser.is_open:
        print(f"串口 {port_name} 已成功打开。")
        
        # 清空缓冲区，避免旧数据干扰
        ser.flushInput()
        
        try:
            while True:
                # 检查接收缓冲区中是否有数据等待读取
                if ser.in_waiting > 0:
                    # 读取可用数据
                    data = ser.read(ser.in_waiting)
                    
                    # 将数据转换为十六进制字符串表示
                    hex_data = data.hex()  # 方法一：使用内置的hex()方法
                    # 或者使用binascii模块：import binascii; hex_data = binascii.hexlify(data).decode('utf-8')
                    
                    # 格式化输出：每两个字符（一个字节）用空格分隔，便于阅读
                    formatted_hex = ' '.join([hex_data[i:i+2] for i in range(0, len(hex_data), 2)])
                    
                    print(f"接收到的十六进制数据: {formatted_hex}")
                    
        except KeyboardInterrupt:
            print("\n用户中断程序。")
        
except serial.SerialException as e:
    # 捕获并打印串口操作相关的异常
    print(f"打开串口 {port_name} 时出错: {e}")
except Exception as e:
    # 捕获其他可能的异常
    print(f"发生未知错误: {e}")

finally:
    # 确保串口被关闭
    if 'ser' in locals() and ser.is_open:
        ser.close()
        print(f"串口 {port_name} 已关闭。")
