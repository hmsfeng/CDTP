# 中容量数传协议

[English](https://github.com/ZhuYanzhen1/CDTP/blob/master/Mid%20Capacity/README.md) / 中文

### 适用场景:

+ 传输数据总量小于128字节
+ 基于全双工传输协议
+ 从机向主机进行小容量数据传输
+ 主机向从机进行小容量数据传输
+ 无需十分稳定的校验机制
+ 需要支持突发传输

***

### 说明：

&nbsp;&nbsp;&nbsp;&nbsp;这是一个固定长度的传输协议，每个包（数据传输最小单位）的长度均为12字节，每个包的有效数据长度均为8字节（即一个包最多装载8字节的数据）。基本的包元素含有起始帧，包标识符，结束帧。通信时直接将数据包发出，无需进行握手等操作，每帧数据占用一字节（八个二进制位）。

***

### 包内容：

![Package_Contents](https://raw.githubusercontent.com/ZhuYanzhen1/CDTP/master/image/Package%20Contents_cn.jpg)

##### 帧说明:

+ 帧头：值为0xA5的帧。
+ 帧尾：值为0xA5的帧。
+ 包标识符：占用四个位，该值可取0到15，低四位与高四位位反。自我校验方式在以下图中说明：
  ![PID_Frame](https://raw.githubusercontent.com/ZhuYanzhen1/CDTP/master/image/PID%20Frame_cn.jpg)

+ 调整帧：调整数据区以确保数据帧中不含有0xA5。如果含有，就会设置相对应的位用于调整帧节，最后清除该数据帧为0x00。调整方式在下图中说明：
  ![Adjust_Frame](https://raw.githubusercontent.com/ZhuYanzhen1/CDTP/master/image/Adjust%20Frame_cn.jpg)
