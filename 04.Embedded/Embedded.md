# 基本知识

## 交叉编译

1. 交叉编译：在一种平台上能够编译出在另一种体系结构不同的平台上运行的程序：
   - 比如在PC机上编译出能够在ARM上运行的程序，编译得到的程序在X86 CPU平台上是不能运行的，必须放到ARM CPU上才能运行（即使两个平台都是Linux系统）；
   - 即在宿主机上编译得到目标程序、然后将目标程序运行在目标机上；

2. 交叉编译工具链：一个由编译器、链接器、解释器组成的综合开发环境，主要由glibc、gcc、binutils组成；

   - 出于裁剪的目的可能会有所不同；

3. 命名规则：**arch [-vendor] [-os] [-(gnu)eabi]**

   - arch:体系架构哦；
   - vendor:工具链提供商；
   - os:目标操作系统：
     - 不支持操作系统：arm-none-eabi
     - 支持操作系统：arm-none-linux-eabli:
   - eabi:(Embedded Application Binary Interface)嵌入式应用二进制接口；
     - ABI：在计算机中，应用二进制接口描述了应用程序（或者其他类型）和操作系统之间或其他应用程序的低级接口。
     - EABI:嵌入式ABI:嵌入式应用二级制接口指定了文件格式、数据类型、寄存器使用、堆积组织优化、嵌入式软件中的参数标准约定；

4. 交叉编译器的分类：

   -  目前免费的工具有三个厂商提供：
     - GNU:
       - arm-nono-eabi-gcc:GNU推出的ARM交叉编译工具，可用于编译ARM MCU(32)芯片，如ARM7\ARM9\Cortex-M\R芯片程序；
         - 下载地址：<http://www.veryarm.com/arm-none-eabi-gcc>
     - Codesourcery:
       - arm-none-linux-gnueabi-gcc:基于GCC推出的ARM教程编译工具，用于交叉编译ARM（32）位系统中的所有环节代码，包括裸机程序、u-boot、kernel、filesystem、app;
         - 下载地址：<http://www.veryarm.com/arm-none-linux-gnueabi-gcc>
       - arm-none-elf-gcc:可用于编译ARM MCU(32)芯片，如ARM7\ARM9\Cortex-M\R芯片程序；
         - 下载地址：<http://www.veryarm.com/arm-none-elf-gcc>
     - Linora:
       - arm-linux-gnueabihf-gcc:基于gcc的Arm交叉编译器可以用于交叉编译ARM（32位）系统中的所有环节代码；
         - 下载地址：<http://www.veryarm.com/arm-linux-gnueabihf-gcc>
       - aarch64-linux-gnu-gcc:可用于交叉编译ARMv8 64为目标机中国的所有程序；
         - 下载地址：<http://www.veryarm.com/aarch64-linux-gnu-gcc>
     - 
   -  收费的有：
     - armcc
     - IAR:

5. 交叉编译工具链选择：

   - 通常在各个SOC厂商会在标准的交叉编译工具链中做修改以适应自己的厂商的SOC（TI、SAMSUN等），然后将修改后的编译工具链发布；
   - 开发板厂商在soc厂商的基础上再进行修改、调优，所以在购买到开发板的时候就会有适应开发板的交叉编译工具链；
   - 一般开发中都是使用开发板产商提供的交叉编译工具链；
   - 在开发中uboot、kernel等编译的时候可能使用到不同的交叉编译工具链（大多时候是不同的）

6. 交叉编译工具链在实际开发中的使用方式：

   - 获取对应的交叉编译工具链压缩包,并解压到合适的目录：

     - 一般是放到**/opt**目录；

   - 在编译脚本中修改：

     - ```shell
       function env_setup()
       {
       	export PATH=/opt/arm-2009q3/bin/:$PATH
       	export ARCH=arm
       	export CROSS_COMPILE=arm-none-linux-gnueabi-
       	
       	TOP_DIR=`pwd`
       	OUT_DIR=$TOP_DIR/build/out
       	#TARGET=am335x_evm_config #am335x_boneblack_config
       	#TARGET=am335x_nk105_config  #am335x_evm_config #am335x_boneblack_config
       
       	# 打印当前环境参数
       	echo ""
       	echo ""
       	echo -e "\033[1m   Welcome to uboot \033[0m"
       	echo "========echo variables start========"
       	echo "ARCH=${ARCH}"
       	echo "CROSS_COMPILE=${CROSS_COMPILE}"
       	echo "TOP_DIR=${TOP_DIR}"
       	echo "TARGET=${TARGET}"
       	echo "OUT_DIR=${OUT_DIR}"
       	echo "========echo variables end=========="
       	echo ""
       	echo ""
       }
       ```

   - 在环境变量中固定：

     - 将对应的执行文件路径导出到环境变量PATH中（临时修改）；

     - export PATH=/opt/ arm-2009q3/bin:$PATH;

     - 为命令制作软链接：（输入arm-none-linux-gnueabi-xx 命令太麻烦）：

     - ```
       ln arm-none-linux-gnueabi-addr2line -s arm-linux-addr2line
        ln arm-none-linux-gnueabi-ar -s arm-linux-ar
        ln arm-none-linux-gnueabi-as -s arm-linux-as
        ln arm-none-linux-gnueabi-c++ -s arm-linux-c++
        ln arm-none-linux-gnueabi-c++filt -s arm-linux-c++filt
        ln arm-none-linux-gnueabi-cpp -s arm-linux-cpp
        ln arm-none-linux-gnueabi-g++ -s arm-linux-g++
        ln arm-none-linux-gnueabi-gcc -s arm-linux-gcc
        ln arm-none-linux-gnueabi-gcc-4.4.1 -s arm-linux-gcc-4.4.1
        ln arm-none-linux-gnueabi-gcov -s arm-linux-gcov
        ln arm-none-linux-gnueabi-gdb -s arm-linux-gdb
        ln arm-none-linux-gnueabi-gdbtui -s arm-linux-gdbtui
        ln arm-none-linux-gnueabi-gprof -s arm-linux-gprof
        ln arm-none-linux-gnueabi-ld -s arm-linux-ld
        ln arm-none-linux-gnueabi-nm -s arm-linux-nm
        ln arm-none-linux-gnueabi-objcopy -s arm-linux-objcopy
        ln arm-none-linux-gnueabi-objdump -s arm-linux-objdump
        ln arm-none-linux-gnueabi-ranlib -s arm-linux-ranlib
        ln arm-none-linux-gnueabi-readelf -s arm-linux-readelf
        ln arm-none-linux-gnueabi-size -s arm-linux-size
        ln arm-none-linux-gnueabi-sprite -s arm-linux-sprite
        ln arm-none-linux-gnueabi-strings -s arm-linux-strings
        ln arm-none-linux-gnueabi-strip -s arm-linux-strip
       ```

       

7. 制作交叉编译工具链：

# ARM

# UBOOT

# KERNEL

# 根文件系统



# Linux 系统使用记录

1. secureCRT配色之后，如果之后vim打开的文件内容显示颜色，而ls列出的文件列表没有颜色显示：
   - 执行命令“alias ls='ls --color'，只针对本次连接有效；
   - 永久修改：在/home/xptd/.base_profile 中添加
     - “alias ls='ls --color'命令
2. 在secureCRT中用vim编辑文件，经常出现“卡死”：
   - 程序员的编程习惯，随便写写就是ctrl+s,但是这个组合按键是一个shell控制键，这个时候只要ctrl+q即可恢复；



