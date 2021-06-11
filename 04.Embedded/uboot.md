# 2020-4-13
1. 官网下载uboot源码；

2. make clean \make distclean;清理之前的编译结果；

3. 在根目录下的Makefile中添加交叉编译工具：

   - ```c
     CROSS_COMPILE := /opt/arm-2009q3/bin/arm-none-linux-gnueabi-
     ```

4. make origen_defconfig ;测试编译；

5. 复制、修改xxx_defconfig 文件：

   - cp origen_defconfig xptd_defconfig 
   - 替换文件中所有的ORIGEN为XPTD

6. 赋值、修改xxx.h文件：

   - ./include/configs:cp origen.h xptd.h

   - 替换所有的origen 为xptd.h

   - ```
     #define CONFIG_SPL_TEXT_BASE  0x02023400	//0x02021410
     ```

   - ```
     #define MACH_TYPE_XPTD  5115 //add by xptd
     ```

     

7. 修改board 文件：

   -  cd board/samsung/

   -  cp -rf origen/ xptd:拷贝一份origen 文件

   - mv origen.c xptd.c

   - 修改kconfig文件:origen 替换为xptd

   - 修改MAINTAINERS文件：origen 替换为xpdt

   - 修改Makefile 文件：origen 替换为xpdt

     - ```
       hostprogs-y := tools/mkxptdspl
       ```

       

   - 修改tools/mkorigenspl.c 为mkxptdspl.c

     - ```c
       #define IMG_SIZE		(14*1024)//(16*1024)
       #define SPL_HEADER_SIZE	0	//16
       ```

8. 修改arch/arm/mach-exynos/Kconfig文件：

   - ```c
     config TARGET_XPTD
     	bool "Exynos4412 xptd board"
     	select SUPPORT_SPL
     ```

   - ```
     source "board/samsung/xptd/Kconfig"
     ```

     

9. 设备树修改：

   - cd /arch/arm/dts
   - cp exynos4412-odroid.dts exynos4412-xptd.dts
   - 关键字替换；

10. init:

    - arch/arm/mach-exynos
    - 修改Makefile:
      - obj-$(CONFIG_EXYNOS4412)+= dmc_init_exynos4412.o clock_init_exynos4412.o
    - 创建对应文件：
      - cp -rf dmc_init_exynos4.c dmc_init_exynos4412.c  
      - cp clock_init_exynos4.c clock_init_exynos4412.c
      - cp exynos4_setup.h exynos4412_setup.h

11. 

