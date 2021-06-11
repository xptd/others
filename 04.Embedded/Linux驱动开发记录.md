---
typora-root-url: 01.images
typora-copy-images-to: 01.images
---

# Linux驱动开发记录

## LED驱动开发

### 开发前准备

1. 可以正常使用开发板（forlinx ok335xS-V2）;
2. Linux开发环境（Windows7(64bits)+Vmware10.0+Ubuntu14.04（32bits））;
3. 能正常引导kernel启动的Uboot(uboot 2014 自己移植)+正常编译且能生成可启动的kernel镜像文件（zImage）;
4. 开发板与Windows、Ubuntu可以ping通，开发板可以通过TFTPf方式启动kernel（参考附录1：tftp环境搭建），开发板通过nfs方式挂载nfs根文件系统或者可以从nandflash或者其它启动介质挂载根文件系统在kernel启动之后可以mount到Ubuntu端的nfs共享文件夹（参考附录2：nfs环境搭建）；
5. Windows与Ubuntu可以通过Samba等方式实习文件共享，在Windows环境下编辑，借助Linux环境编译（参考附录3：Samba服务器搭建）；

### 简单字符设备驱动点亮LED

#### Linux驱动分类

一个常规的ARM核心板通常包括，CPU、存储器（内存和外存）、外设（片内外设、片上外设）等，内核要使用（管理）这些对象，所以有就了对应的驱动程序，驱动是针对外设、存储器等对象而不是针对内核，所以从内核的管理角度来看见这些设备区分为块设备、字符设备、网络设备，对应的就有了：

1. 字符设备驱动：数据的交互以字节为单位（必须以串行顺序依次进行访问的设备），led、触摸屏等

2. 块设备驱动：数据交互可以是以数据块为单位（按任意顺序进行访问），nandflash、emmc等

   字符设备、块设备使用文件系统的操作接口open（）、close（）、read（）、write（）等进行访问

3. 网络设备驱动：数据交互以数据包为单位，数据交互主要还是使用套接字接口



#### Linux驱动整体框架

最上层是APPc层，最下层是hardware层。对于应用程序开发人员来说只需要调用相应的库函数(系统API、系统调用接口)即可实现操作需求。在“一切皆文件”伟大精神领导下设备驱动也是一个文件，所以可以以操作文件的形式操作一个硬件设备，然而文件必然要依赖文件系统的存在，文件系统又各种乱七八糟的存在着，对于用户程序开发来说必然是混乱的，所以在“简单就是美”的原则下，在用户程序和内核驱动程序中间加了一个VFS（virtual file system虚拟文件系统--既然是虚拟的那就是不存在的不是依赖具体存储实体的文件系统）。

VFS向上提供统一的编程接口，对下有要管理各种挂载的文件、文件系统（设备驱动文件、文件系统等）。用户层与内核层的接口就是系统调用，而统一系统掉用的就是VFS给出的系统调用接口。

file_operations结构体是VFS与其所管理的各种乱七八糟文件、文件系统接口，这个结构体包含对文件进行打开、关闭、读写、控制的一系列成员函数，不同的设备驱动有不同的读、写操作函数xxx_open,xxx_write但是在注册驱动时必须要将这些接口填充到file_operations对于的成员函数中，这些从VFS端来看看到的就只有open/write（具体的映射过程 后续再研究）。

块设备有两种访问方法，一种是类似于字符设备驱动一样以设备文件的形式进行访问、直接访问裸的块设备，另外一种是通过文件系统方式访问块设备上层通过调用文件系统的API间接操作块设备，存储设备底层操作由文件系统来维护完成。



![文件系统与驱动](/文件系统与驱动.jpg)

#### 字符设备驱动



#### 代码实践

##### 驱动代码实现

```c
//*************************************************
//@FileName:first_cdev.c
//@Author: xiaopaotangde
//@For:
//@Created Time:Fri 28 Jun 2019 11:36:39 AM CST
//************************************************
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/module.h>
static int first_cdev_open(struct inode* inodep, struct file* filep)
{
	printk("first_cdev_open\n");
 	return 0;

}
static ssize_t first_cdev_write(struct file *filep, const char __user * buf, size_t len, loff_t *ppos)
{
	printk("first_cdev_write\n");
	return 0;
}
static const struct file_opration first_cdev_file_opration=
{
	.owner=THIS_MODULE,
	.open=first_cdev_open,
	.write=first_cdev_write,

};

static int __init first_cdev_init()
{
	register_chrdev(125,"first_cdev",&first_cdev_file_opration);
	printk("first_cdev_init\n");
	return 0;
}

static void __exit first_cdev_exit()
{
	unregister_chrdev(125,"first_cdev");
	printk("first_cdev_exit\n");
}
module_init(first_cdev_init);
module_exit(first_cdev_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("xptd");MODULE_DESCRIPTION("first char driver test!\n");



```

##### 应用代码实现

~~~c
##### 

```
//*************************************************
//@FileName:first_cdev_app.c
//@Author: xiaopaotangde
//@For:
//@Created Time:Fri 28 Jun 2019 02:54:17 PM CST
//************************************************

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	

```
char buf[10];
int fd = open("/dev/first_cdev",O_RDWR);
if(fd < 0)
{
	
	printf("open file failed\n");
	return -1;
}

write(fd,buf,5);
return 0;
}


```

##### 

~~~

##### 使用方法

1. 加载模块 :insmod first_cdev.ko (或者使用全路径的方式加载 比如ismod /home/xptd/linux/05.rootfs/drivers_test/01.led_driver_test/01.first_cdev/first_cdev.ko),加载完成之后使用lsmod 命令即可查看到刚刚加载的模块；

2. mknod /dev/first_cdev  c 125 0:在/dev下创建first_cdev 设备文件（一切皆文件）；

3. gcc 编译first_cdev_app.c 生成可执行文件app（arm gcc)

4. 执行应用程序./app ，按照预期结果 驱动代码中设定的打印消息

5. dmesg 查看消息缓存区中的消息记录：

   ​	![first_cdev](/first_cdev.jpg)

   

6. 删除设备文件：rm -rf /dev/first_cdev /卸载模块:rmmod first_cdev.ko





##### 实现效果

1. 驱动模块的加载、卸载；
2. 应用程序使用的open/write()函数已经被映射到驱动代码提供的xxx_open()、xxx_write()函数；

### 简单方式驱动LED

#### 驱动代码：

```c
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/io.h>
#include <asm/uaccess.h>

//ok335xs 板子上只有一个LED(GPIO3_16,低电平有效)
#define GPIO_OE  0x134
#define GPIO_DATAOUT 0x13C
#define GPIO3_BASE 0x481AE000

#define LED_OE       (GPIO3_BASE + GPIO_OE) 
#define LED_DATAOUT  (GPIO3_BASE + GPIO_DATAOUT)

typedef struct {
	unsigned int REVISION;             		// 0x0000
    unsigned int zzzReserved01[3];
    unsigned int SYSCONFIG;              // 0x0010
    unsigned int zzzReserved02[4];
    unsigned int IRQSTATUS_RAW_0;         // 0x0024
    unsigned int IRQSTATUS_RAW_1;         // 0x0028
    unsigned int IRQSTATUS_0;            // 0x002C
    unsigned int IRQSTATUS_1;             // 0x0030
    unsigned int IRQSTATUS_SET_0;         // 0x0034
    unsigned int IRQSTATUS_SET_1;         // 0x0038
    unsigned int IRQSTATUS_CLR_0;         // 0x003C
    unsigned int IRQSTATUS_CLR_1;         // 0x0040
	unsigned int zzzReserved03[52];
    unsigned int SYSSTATUS;				// 0x0114
    unsigned int zzzReserved04[6];   		//118-12F
    unsigned int CTRL;						// 0x0130
    unsigned int OE;                      	// 0x0134
    unsigned int DATAIN;                	// 0x0138
    unsigned int DATAOUT;                 // 0x013C
    unsigned int LEVELDETECT0;            // 0x0140
    unsigned int LEVELDETECT1;            // 0x0144
    unsigned int RISINGDETECT;            // 0x0148
    unsigned int FALLINGDETECT;           // 0x014C
    unsigned int DEBOUNCENABLE;           // 0x0150
    unsigned int DEBOUNCINGTIME;          // 0x0154
    unsigned int zzzReserved05[14];
    unsigned int CLEARDATAOUT;            // 0x0190
    unsigned int SETDATAOUT;              // 0x0194
    unsigned int zzzReserved09[2];
}AM3XX_GPIO_REGS;

AM3XX_GPIO_REGS* pgpio_led = NULL;

static int first_cdev_led_open(struct inode* inodep, struct file* filep)
{
	printk("first_cdev_led_open\n");
	pgpio_led->OE = 0xffffffff & ~(1<<16);//config gpio3_16 ouput mode
	pgpio_led->DATAOUT = 0xffffffff;     //default led off
	return 0;
}
static ssize_t first_cdev_led_write(struct file* filep,const char __user * buf, size_t len, loff_t *ppos)
{
	char buff[10];
	char ret;
	
	printk("first_cdev_led_write\n");
	memset(buff,0,sizeof(buff)/sizeof(*buff));
	ret = copy_from_user(buff,buf,1);

	if(ret)
	{
		printk("copy from usr error.\n");
	}
	if('0' == buff[0])
	{
		pgpio_led->DATAOUT |= (1 << 16);
		
	}else if('1' == buff[0])
	{
		pgpio_led->DATAOUT  &= ~(1 << 16);
	}
	else
	{
		printk("input 1--led on,0--led off\n");
	}
	
	return 0;
}

static const struct file_operations first_cdev_led_file_operation=
{
	.owner = THIS_MODULE,
	.open  = first_cdev_led_open,
	.write = first_cdev_led_write,
};

static int __init first_cdev_led_init(void)
{
	printk("first_cdev_led_init\n");
	pgpio_led = ioremap(GPIO3_BASE,0x68);//phy to vm
	if(!pgpio_led)
	{
		printk("ioremap error\n");
		return -1;
	}
	register_chrdev(125,"first_cdev_led",&first_cdev_led_file_operation);
	return 0;
}

static void __exit first_cdev_led_exit(void)
{
	printk("first_cdev_led_exit\n");
	unregister_chrdev(125,"first_cdev_led");
	iounmap(pgpio_led);
}

module_init(first_cdev_led_init);
module_exit(first_cdev_led_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("xptd");
MODULE_DESCRIPTION("first_cdev_led_v0.1");
```



#### 应用层代码：

~~~c
#### 

```
#include <stdio.h>
```

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
	char buf[10]="0";
	int fd = open("/dev/led",O_RDWR);
	if(fd < 0)
	{
		printf("can not open file:/dev/led\n");
		return -1;
	}
	while('q' != buf[0])
	{
		scanf("%s",buf);
		write(fd,buf,1);
		printf("\n");
	}
	return 0;
}
~~~



#### 编译脚本：

```C
KERN_DIR = /home/xptd/linux/04.kernel-ok335x/
obj-m	+= first_cdev_led.o
all:
	make -C $(KERN_DIR) M=`pwd` -j4 O=/home/xptd/linux/04.kernel-ok335x/build/out modules 

.PHONY: clean	
clean:
	make -C $(KERN_DIR) M=`pwd` -j4 O=/home/xptd/linux/04.kernel-ok335x/build/out modules clean
```



#### 使用方法：

1. 开发板可以通过nfs方式挂载Ubuntu中的文件(可以是直接挂载nfs根文件系统也可以是使用nandflash中的根文件系统、带内核启动之后再挂载nfs文件夹:在开发板上-mount -t nfs 192.168.1.30:/home/xptd/linux/05.rootfs/drivers_test/01.led_driver_test/03.first_cdev -o  nolock /mnt 将共享文件夹挂载到/mnt 目录下就可以看到Ubuntu中编写、编译的文件)；

2. 在开发板端键入“insmod first_cdev_led.ko”加载该模块，加载成功后可以键入lsmod”命令查看是否挂载；

   ![lsmod](/lsmod-1562064220120.jpg)

   

   

3. 创建设备文件：mknod /dev/led c 125 0:设备文件：/dev/led  设备类型：字符设备 主设备号125、次设备号0

4. 打开应用层app 输入数字1 led亮 数字0 led灭；

   

#### 实现效果：

​	![点亮led](/点亮led.jpg)



###  对于指定设备号的方式修改 　

  上一版本中主设备号、次设备号都是在驱动代码中写死的，在写驱动是就需要提前知道当前系统没有注册的设备号是什么，这样很不方便，所以将分配主设备号的任务交个操作系统，由操作系统自己去查询当前系统未被使用且可以被当前驱动使用的设备号。

#### 驱动代码：

~~~c
//1.解决手动分配设备号的问题
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/io.h>
#include <asm/uaccess.h>

//ok335xs 板子上只有一个LED(GPIO3_16,低电平有效)
#define GPIO_OE  0x134
#define GPIO_DATAOUT 0x13C
#define GPIO3_BASE 0x481AE000

#define LED_OE       (GPIO3_BASE + GPIO_OE) 
#define LED_DATAOUT  (GPIO3_BASE + GPIO_DATAOUT)

typedef struct {
	unsigned int REVISION;             		// 0x0000
    unsigned int zzzReserved01[3];
    unsigned int SYSCONFIG;              // 0x0010
    unsigned int zzzReserved02[4];
    unsigned int IRQSTATUS_RAW_0;         // 0x0024
    unsigned int IRQSTATUS_RAW_1;         // 0x0028
    unsigned int IRQSTATUS_0;            // 0x002C
    unsigned int IRQSTATUS_1;             // 0x0030
    unsigned int IRQSTATUS_SET_0;         // 0x0034
    unsigned int IRQSTATUS_SET_1;         // 0x0038
    unsigned int IRQSTATUS_CLR_0;         // 0x003C
    unsigned int IRQSTATUS_CLR_1;         // 0x0040
	unsigned int zzzReserved03[52];
    unsigned int SYSSTATUS;				// 0x0114
    unsigned int zzzReserved04[6];   		//118-12F
    unsigned int CTRL;						// 0x0130
    unsigned int OE;                      	// 0x0134
    unsigned int DATAIN;                	// 0x0138
    unsigned int DATAOUT;                 // 0x013C
    unsigned int LEVELDETECT0;            // 0x0140
    unsigned int LEVELDETECT1;            // 0x0144
    unsigned int RISINGDETECT;            // 0x0148
    unsigned int FALLINGDETECT;           // 0x014C
    unsigned int DEBOUNCENABLE;           // 0x0150
    unsigned int DEBOUNCINGTIME;          // 0x0154
    unsigned int zzzReserved05[14];
    unsigned int CLEARDATAOUT;            // 0x0190
    unsigned int SETDATAOUT;              // 0x0194
    unsigned int zzzReserved09[2];
}AM3XX_GPIO_REGS;

AM3XX_GPIO_REGS* pgpio_led = NULL;
static unsigned int major;

static int first_cdev_led_open(struct inode* inodep, struct file* filep)
{
	printk("first_cdev_led_open\n");
	pgpio_led->OE = 0xffffffff & ~(1<<16);//config gpio3_16 ouput mode
	pgpio_led->DATAOUT = 0xffffffff;     //default led off
	return 0;
}
static ssize_t first_cdev_led_write(struct file* filep,const char __user * buf, size_t len, loff_t *ppos)
{
	char buff[10];
	char ret;
	

```
printk("first_cdev_led_write\n");
memset(buff,0,sizeof(buff)/sizeof(*buff));
ret = copy_from_user(buff,buf,1);

if(ret)
{
	printk("copy from usr error.\n");
}
if('0' == buff[0])
{
	pgpio_led->DATAOUT |= (1 << 16);
	
}else if('1' == buff[0])
{
	pgpio_led->DATAOUT  &= ~(1 << 16);
}
else
{
	printk("input 1--led on,0--led off\n");
}

return 0;
```

}

static const struct file_operations first_cdev_led_file_operation=
{
	.owner = THIS_MODULE,
	.open  = first_cdev_led_open,
	.write = first_cdev_led_write,
};

static int __init first_cdev_led_init(void)
{
	printk("first_cdev_led_init\n");
	pgpio_led = ioremap(GPIO3_BASE,0x68);//phy to vm
	if(!pgpio_led)
	{
		printk("ioremap error\n");
		return -1;
	}
	//注册时将 主设备号改为0 系统自动分配未使用的设备号
	major = register_chrdev(0,"first_cdev_led",&first_cdev_led_file_operation);
	return 0;
}

static void __exit first_cdev_led_exit(void)
{
	printk("first_cdev_led_exit\n");
	unregister_chrdev(major,"first_cdev_led");
	iounmap(pgpio_led);
}

module_init(first_cdev_led_init);
module_exit(first_cdev_led_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("xptd");
MODULE_DESCRIPTION("first_cdev_led_v0.1");
~~~



#### 应用层代码：

​	应用层代码于上一版本一致。

#### 使用方法：

​	使用方法与上一版本一致，在insmod之后可以查看到系统自动分配的设备号：cat /proc/devices

​	![cat](/cat.jpg)

#### 实现效果：

​	系统自动分配版本号。

### 对于mknod手动创建、注销设备文件方式修改　

​	上一版本解决了手动分配设备号的问题，但是要想使用驱动代码必须要手动创建设备文件：mknod /dev/led c 244 0,使用完之后还要及时删除掉当前分配的设备文件，否则再次mknod时就会提示文件已经存在（如果不重启只是重新加载驱动），如果只是设备文件名相同，设备号，驱动不一样的话会造成应用层调用驱动时出错。

![mknod](/../../../mknod.jpg)



#### 驱动代码

~~~c
//2.解决手动创建/删除设备文件的问题
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/io.h>
#include <asm/uaccess.h>
#include <linux/device.h>

//ok335xs 板子上只有一个LED(GPIO3_16,低电平有效)

#define GPIO_OE  0x134
#define GPIO_DATAOUT 0x13C
#define GPIO3_BASE 0x481AE000

#define LED_OE       (GPIO3_BASE + GPIO_OE) 
#define LED_DATAOUT  (GPIO3_BASE + GPIO_DATAOUT)

typedef struct {
	unsigned int REVISION;             		// 0x0000
    unsigned int zzzReserved01[3];
    unsigned int SYSCONFIG;              // 0x0010
    unsigned int zzzReserved02[4];
    unsigned int IRQSTATUS_RAW_0;         // 0x0024
    unsigned int IRQSTATUS_RAW_1;         // 0x0028
    unsigned int IRQSTATUS_0;            // 0x002C
    unsigned int IRQSTATUS_1;             // 0x0030
    unsigned int IRQSTATUS_SET_0;         // 0x0034
    unsigned int IRQSTATUS_SET_1;         // 0x0038
    unsigned int IRQSTATUS_CLR_0;         // 0x003C
    unsigned int IRQSTATUS_CLR_1;         // 0x0040
	unsigned int zzzReserved03[52];
    unsigned int SYSSTATUS;				// 0x0114
    unsigned int zzzReserved04[6];   		//118-12F
    unsigned int CTRL;						// 0x0130
    unsigned int OE;                      	// 0x0134
    unsigned int DATAIN;                	// 0x0138
    unsigned int DATAOUT;                 // 0x013C
    unsigned int LEVELDETECT0;            // 0x0140
    unsigned int LEVELDETECT1;            // 0x0144
    unsigned int RISINGDETECT;            // 0x0148
    unsigned int FALLINGDETECT;           // 0x014C
    unsigned int DEBOUNCENABLE;           // 0x0150
    unsigned int DEBOUNCINGTIME;          // 0x0154
    unsigned int zzzReserved05[14];
    unsigned int CLEARDATAOUT;            // 0x0190
    unsigned int SETDATAOUT;              // 0x0194
    unsigned int zzzReserved09[2];
}AM3XX_GPIO_REGS;

AM3XX_GPIO_REGS* pgpio_led = NULL;
static unsigned int major;
static struct class *first_cdev_class;
static struct device *first_cdev_device;

static int first_cdev_led_open(struct inode* inodep, struct file* filep)
{
	printk("first_cdev_led_open\n");
	pgpio_led->OE = 0xffffffff & ~(1<<16);//config gpio3_16 ouput mode
	pgpio_led->DATAOUT = 0xffffffff;     //default led off
	return 0;
}
static ssize_t first_cdev_led_write(struct file* filep,const char __user * buf, size_t len, loff_t *ppos)
{
	char buff[10];
	char ret;
	

```
printk("first_cdev_led_write\n");
memset(buff,0,sizeof(buff)/sizeof(*buff));
ret = copy_from_user(buff,buf,1);

if(ret)
{
	printk("copy from usr error.\n");
}
if('0' == buff[0])
{
	pgpio_led->DATAOUT |= (1 << 16);
	
}else if('1' == buff[0])
{
	pgpio_led->DATAOUT  &= ~(1 << 16);
}
else
{
	printk("input 1--led on,0--led off\n");
}

return 0;
```

}

static const struct file_operations first_cdev_led_file_operation=
{
	.owner = THIS_MODULE,
	.open  = first_cdev_led_open,
	.write = first_cdev_led_write,
};

static int __init first_cdev_led_init(void)
{
	printk("first_cdev_led_init\n");
	pgpio_led = ioremap(GPIO3_BASE,0x68);//phy to vm
	if(!pgpio_led)
	{
		printk("ioremap error\n");
		return -1;
	}
	//注册时将 主设备号改为0 系统自动分配未使用的设备号
	major = register_chrdev(0,"first_cdev_led",&first_cdev_led_file_operation);
	first_cdev_class = class_create(THIS_MODULE,"led_class");
	if(!first_cdev_class)
	{
		if(IS_ERR(first_cdev_class))
			return PTR_ERR(first_cdev_class);
	}
	first_cdev_device = device_create(first_cdev_class,NULL,MKDEV(major, 0), NULL, "led");
	

```
if(IS_ERR(first_cdev_device))
{	
	return PTR_ERR(first_cdev_device);
}

return 0;
```

}

static void __exit first_cdev_led_exit(void)
{
	printk("first_cdev_led_exit\n");
	unregister_chrdev(major,"first_cdev_led");
	iounmap(pgpio_led);
	device_unregister(first_cdev_device);
	class_destroy(first_cdev_class);
}

module_init(first_cdev_led_init);
module_exit(first_cdev_led_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("xptd");
MODULE_DESCRIPTION("first_cdev_led_v0.1");
~~~



#### 应用层代码

 与上一版本相同。

#### 编译脚本

与上一版本相同。

#### 使用方法

1. insmod 即可正常使用无需mknod

#### 实现效果

1. insmod之后在/dev下即可看到注册的设备文件“led”；

   ​	![1](/1.jpg)

2. rmmod之后/dev下的设备文件“led”被自动删除；

   ​	![2](/2.jpg)

### 对于insmod、rmmod手工挂载、卸载驱动方式修改

​	对于上一版来说虽然实现了设备文件的自动创建、删除，但是仍需要手动加载(insmod)、卸载(rmmod)驱动模块，如果将将驱动编译到kernel中，在kernel启动时就会自动加载该模块，不过该实验留在最后一个版本的时候再做

### 新、老接口的对比、新接口的使用

​	在当前内核版本中对于字符设备驱动，及存在新接口（cdev相关）驱动代码，也存在老接口驱动代码（没有引入cdev），为此新、老接口的使用都需要掌握。

#### 代码实现

##### 驱动代码：

~~~c
/*
1.使用新接口 改版代码;
2.cdev结构体的引入
3.int register_chrdev_region(dev_t from, unsigned count, const char *name); 
4.int alloc_chrdev_region(dev_t *dev, unsigned baseminor, unsigned count,const char *name);
5.unregister_chrdev_region()
6.void cdev_init(struct cdev *, struct file_operations *);
7.struct cdev *cdev_alloc(void);
8.void cdev_del(struct cdev *);
9.int cdev_add(struct cdev *, dev_t, unsigned);
*/

#include <linux/fs.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/io.h>
#include <asm/uaccess.h>
#include <linux/device.h>
#include <linux/cdev.h>

//ok335xs 板子上只有一个LED(GPIO3_16,低电平有效)
#define GPIO_OE  0x134
#define GPIO_DATAOUT 0x13C
#define GPIO3_BASE 0x481AE000

#define LED_OE       (GPIO3_BASE + GPIO_OE) 
#define LED_DATAOUT  (GPIO3_BASE + GPIO_DATAOUT)

#define LED_MAJOR 125
#define LED_MINOR 0
#define LED_COUNT 1

#define LED_DEVICE_NAME "first_led_device"

#define CLASS_NAME "led_class"
#define LED_DEVICE_FILE_NAME "/dev/led"
typedef struct {
	unsigned int REVISION;             		// 0x0000
    unsigned int zzzReserved01[3];
    unsigned int SYSCONFIG;             	 // 0x0010
    unsigned int zzzReserved02[4];
    unsigned int IRQSTATUS_RAW_0;         // 0x0024
    unsigned int IRQSTATUS_RAW_1;         // 0x0028
    unsigned int IRQSTATUS_0;            	// 0x002C
    unsigned int IRQSTATUS_1;             // 0x0030
    unsigned int IRQSTATUS_SET_0;         // 0x0034
    unsigned int IRQSTATUS_SET_1;         // 0x0038
    unsigned int IRQSTATUS_CLR_0;         // 0x003C
    unsigned int IRQSTATUS_CLR_1;         // 0x0040
	unsigned int zzzReserved03[52];
    unsigned int SYSSTATUS;					// 0x0114
    unsigned int zzzReserved04[6];   		//118-12F
    unsigned int CTRL;						// 0x0130
    unsigned int OE;                      	// 0x0134
    unsigned int DATAIN;                	// 0x0138
    unsigned int DATAOUT;                 // 0x013C
    unsigned int LEVELDETECT0;            // 0x0140
    unsigned int LEVELDETECT1;            // 0x0144
    unsigned int RISINGDETECT;            // 0x0148
    unsigned int FALLINGDETECT;           // 0x014C
    unsigned int DEBOUNCENABLE;           // 0x0150
    unsigned int DEBOUNCINGTIME;          // 0x0154
    unsigned int zzzReserved05[14];
    unsigned int CLEARDATAOUT;            // 0x0190
    unsigned int SETDATAOUT;              // 0x0194
    unsigned int zzzReserved09[2];
}AM3XX_GPIO_REGS;

AM3XX_GPIO_REGS* pgpio_led = NULL;
static struct cdev* pled_cdev;
static dev_t device_num;
static struct class* first_cdev_class;
static struct device* first_cdev_device;

static int first_cdev_led_open(struct inode* inodep, struct file* filep)
{
	printk("first_cdev_led_open\n");
	pgpio_led->OE = 0xffffffff & ~(1<<16);//config gpio3_16 ouput mode
	pgpio_led->DATAOUT = 0xffffffff;     //default led off
	return 0;
}
static ssize_t first_cdev_led_write(struct file* filep,const char __user * buf, size_t len, loff_t *ppos)
{
	char buff[10];
	char ret;
	

```
printk("first_cdev_led_write\n");
memset(buff,0,sizeof(buff)/sizeof(*buff));
ret = copy_from_user(buff,buf,1);

if(ret)
{
	printk("copy from usr error.\n");
}
if('0' == buff[0])
{
	pgpio_led->DATAOUT |= (1 << 16);
	
}else if('1' == buff[0])
{
	pgpio_led->DATAOUT  &= ~(1 << 16);
}
else
{
	printk("input 1--led on,0--led off\n");
}

return 0;
```

}

static const struct file_operations first_cdev_led_file_operation=
{
	.owner = THIS_MODULE,
	.open  = first_cdev_led_open,
	.write = first_cdev_led_write,
};

static int __init first_cdev_led_init(void)
{
	int ret;
	printk("first_cdev_led_init\n");
	

```
pgpio_led = ioremap(GPIO3_BASE,0x68);//phy to vm
if(!pgpio_led)
{
	printk("ioremap error\n");
	return -1;
}

/*
	1.使用新街口 注册设备号register_chedev_alloc()
	2.该函数用于向kernel注册设备号，但是前提是需要已知系统未使用的设备号
	3.在注册前需要先 cat /proc/devices 查看当前系统未分配的设备号(选取125)
	4.第一个参数dev_t from 用于指定起始设备号（主版本号+次版本号）,该函数可以连续注册设备号(region)
	5.第二个参数unsigned count用于指定需要注册的个数,比如指定起始版本号(125+0) 需要申请(125+0 1 2 3)则需要指定count的个数为4
	  比如板载上有4颗led 如果为每一个led都申请一个主设备号,这样是很浪费系统资源,比较字符设备的设备号是有限的，这种情况下就可以
	  指定一个主版本号，其他的依次分配次版本号即可（没有详细看过内核源码的实现，不过猜测实现应该是类似数组+链表的形式
	  一个主设备号就是数组(数组元素是链表)中的一个索引值，相同主设备号的在放入同一个链表中）;
	6.第三个参数const char *name 指定设备名称，与之前register_chrdev()注册函数中指定的设备名作用一致
	7.注册失败返回：-1
	8.此处有一个坑....如果LED_COUNT为0 程序编译、模块加载、mknod 创建设备文件等等都不会出错，
	但是在执行应用程序时 已知会提醒 无法打开设备文件,cat /proc/devices 看不到注册的设备号;
	
	device_num = MKDEV(LED_MAJOR,LED_MINOR);
	ret = register_chrdev_region(device_num,LED_COUNT,LED_DEVICE_NAME);
*/

/*
	1.使用register_chrdev_region()可以向kernel注册设备号，但是该方法不太灵活，需要在申请前查看设备号是否被占用
	2.使用alloc_chrdev_region()可以自动查询当前未被使用的设备号，然后自动申请并注册；
	3.第一个参数为dev_t 指针类型，很明显这是一个输出型参数,如果申请成功通过该参数返回已申请到的设备号(毕竟其它地方还要
	  使用设备号)
	4.第二个参数baseminor 起始次设备号
	5.需要申请的设备号个数
	6.设备名称(cat /proc/devices 下看到的与设备号对应的名称)
	7.申请、注册失败返回-1
	8.此处有一个坑....如果LED_COUNT为0 程序编译、模块加载、mknod 创建设备文件等等都不会出错，
	  但是在执行应用程序时 已知会提醒 无法打开设备文件,cat /proc/devices 可以看到 设备号以及设备名称
	  在/dev目录下也可以看到设备文件;

*/

ret = alloc_chrdev_region(&device_num, 0, LED_COUNT, LED_DEVICE_NAME);
```

​	

```
if(ret < 0)
{
	printk(KERN_ERR "Unable to register_chrdev_region for %s\n", LED_DEVICE_NAME);
	return -1;
}
printk(KERN_INFO "alloc device num: major: %d.....minor:%d",MAJOR(device_num),MINOR(device_num));
/*
	1.该函数无返回值
	2.第一个参数为cdev结构体指针
	3.第二个参数为file_operations结构体指针
	4.很明显需要 在cdev_init()函数调用之前就已经初始化完毕file_opreations结构体,cdev结构体在声明时最好声明为实体变变量，
	   如果声明为结构体指针的形成则在cdev_init()函数之前必须为其kalloc()开辟空间并初始化；
	   struct cdev *p = kzalloc(sizeof(struct cdev), GFP_KERNEL);
	5.该函数主要作用：初始化cdev结构体变量，并且将file_operations结构体与之关联;
	cdev_init(&led_cdev,&first_cdev_led_file_operation);
	led_cdev.owner = THIS_MODULE;
*/

/*
	1.cdev的初始化有两种方式，一是调用cdev_init()，一种是调用cdev_alloc()分配并初始化一块内存给cdev
	  然后手动初始化cdev的成员变量;
	2.对于第一种方式cdev 变量需要声明为实体变量（即在声明时就为其分配了内存空间），对于第二种方式声明cdev变量时
	  只需要声明为指针变量即可（当时只占用4个字节的指针大小空间）,在使用时为其申请内存空间并初始化（cdev_alloc中调用kzallc）
	3.第二种方式相对第一种方式来说比较灵活（使用时分配内存）
	4.个人比较偏向于使用第二种方式
*/
pled_cdev = cdev_alloc();

pled_cdev->owner = THIS_MODULE;
pled_cdev->ops = &first_cdev_led_file_operation;

ret = cdev_add(pled_cdev,device_num,LED_COUNT);

if(ret < 0)
{
	printk(KERN_ERR "cdev_add err fro %s\n",LED_DEVICE_NAME);
}
printk(KERN_INFO "cdev_add success\n");

first_cdev_class = class_create(THIS_MODULE,CLASS_NAME);
if (IS_ERR(first_cdev_class))
	return -1;
first_cdev_device = device_create(first_cdev_class,NULL,device_num,NULL,LED_DEVICE_FILE_NAME);
if (IS_ERR(first_cdev_class))
	return -1;
return 0;
```

}

static void __exit first_cdev_led_exit(void)
{
	printk("first_cdev_led_exit\n");
	iounmap(pgpio_led);
	cdev_del(pled_cdev);
	unregister_chrdev_region(device_num,LED_COUNT);
	device_unregister(first_cdev_device);
	class_destroy(first_cdev_class);
}

module_init(first_cdev_led_init);
module_exit(first_cdev_led_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("xptd");
MODULE_DESCRIPTION("first_cdev_led_v0.1");
~~~

##### 应用层代码：

​	与上以版本一致。

##### 编译脚本：

​	与上一版本一致。

##### 使用方法：

​	与上一版本一致。

##### 实现效果：

​	与上一版本一致。

![1](/1-1562482581718.jpg)



![alloc](/alloc.jpg)

### LED驱动框架的使用

​	使用内核提供的led驱动框架进行led驱动开发。当目前为止一直都是使用内核提供的操作接口进行驱动开发，其实在内核中内核开发工程师已经做好了一套完整的led驱动框架，驱动框架由内核开发工程师进行开发维护。其实当前主流的Linux设备驱动开发分为三个阶段：

1. 内核开发者对驱动框架进行开发和维护、升级；
2. SoC厂商的驱动工程师基于驱动框架（或者不基于驱动框架）以及所开发设备的设备制造商提供的设备驱动源码进匹配当前SOC的设备驱动开发、调试，最终提供基于该SOC的驱动参考版本；
3. 做产品的厂商的驱动工程师以SoC厂商提供的驱动源码为基础，再做移植和调试，以满足产品需求。

比如触摸屏驱动的开发：内核驱动工程师提供一套完整的匹配当前内核的触摸屏驱动框架，TI原厂工程师基于该驱动框架开发一套匹配自己产商芯片的驱动框架，某开发板公司使用了TI的芯片并且为使用了xx公司的一块触摸面板，该开发板公司基于TI提供的驱动+触摸屏产商提供的触摸屏驱动自己再编写、调试出一版匹配当前开发板的驱动，某产品公司在进行产品开的时候借用了该开发板的设计，所该公司的就会在开发板提供的触摸屏驱动上进行修改匹配自己的产品要求。

​	所以对于产品级的开发工程师来说真正的第一手写驱动的情况是不存在的（0-1）基本上都是在做驱动的移植、修改（不知道该理解为一种悲哀，还是该理解为“术业有专攻”）。

#### 代码实现

##### 驱动代码：

~~~c
/*
	使用内核提供的LED驱动框架重写LED驱动程序
*/
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/leds.h>
#include <linux/io.h>

#define LED_NAME "forlinx_led"
#define GPIO3_REG_BASE 0x481AE000

typedef volatile struct {
	unsigned int REVISION;          		// 0x0000
    unsigned int zzzReserved01[3];
    unsigned int SYSCONFIG;             	 // 0x0010
    unsigned int zzzReserved02[4];
    unsigned int IRQSTATUS_RAW_0;         // 0x0024
    unsigned int IRQSTATUS_RAW_1;         // 0x0028
    unsigned int IRQSTATUS_0;            	// 0x002C
    unsigned int IRQSTATUS_1;             // 0x0030
    unsigned int IRQSTATUS_SET_0;         // 0x0034
    unsigned int IRQSTATUS_SET_1;         // 0x0038
    unsigned int IRQSTATUS_CLR_0;         // 0x003C
    unsigned int IRQSTATUS_CLR_1;         // 0x0040
	unsigned int zzzReserved03[52];
    unsigned int SYSSTATUS;					// 0x0114
    unsigned int zzzReserved04[6];   		//118-12F
    unsigned int CTRL;						// 0x0130
    unsigned int OE;                      	// 0x0134
    unsigned int DATAIN;                	// 0x0138
    unsigned int DATAOUT;                 // 0x013C
    unsigned int LEVELDETECT0;            // 0x0140
    unsigned int LEVELDETECT1;            // 0x0144
    unsigned int RISINGDETECT;            // 0x0148
    unsigned int FALLINGDETECT;           // 0x014C
    unsigned int DEBOUNCENABLE;           // 0x0150
    unsigned int DEBOUNCINGTIME;          // 0x0154
    unsigned int zzzReserved05[14];
    unsigned int CLEARDATAOUT;            // 0x0190
    unsigned int SETDATAOUT;              // 0x0194
    unsigned int zzzReserved09[2];
}AM3XX_GPIO_REGS;

static AM3XX_GPIO_REGS* pgpio_led;

static struct led_classdev forlinx_led_classdev;

static void forlinx_led_brightness_set(struct led_classdev *led_cdev,enum led_brightness brightness)
{
	printk(KERN_INFO "forlinx_led_brightness_set\n");
	if(0 == brightness)
	{
		pgpio_led->DATAOUT |= (1 << 16);
		

```
}else 
{
	pgpio_led->DATAOUT  &= ~(1 << 16);
}
```

}

static int __init led_forlinx_init(void)
{
	

```
	pgpio_led = ioremap(GPIO3_REG_BASE,0x19c);
	
	if(!pgpio_led)
	{
		printk("ioremap for led error\n");
		return -1;
	}
	pgpio_led->OE = 0XFFFFFFFF & ~(1 << 16);
	pgpio_led->DATAOUT = 0xffffffff;
	
	forlinx_led_classdev.name = LED_NAME;
	forlinx_led_classdev.brightness = 0;
	forlinx_led_classdev.max_brightness = 1;
	forlinx_led_classdev.brightness_set = forlinx_led_brightness_set;
	led_classdev_register(NULL,&forlinx_led_classdev);
	
	return 0;
```

}

static void __exit led_forlinx_exit(void)
{
	

```
led_classdev_unregister(&forlinx_led_classdev);
iounmap(pgpio_led);
```

}

module_init(led_forlinx_init);
module_exit(led_forlinx_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("xptd");
MODULE_DESCRIPTION("led_forlinx dirver");
~~~

 1. led驱动框架提供了不同于之前的驱动方法，之前是将设备驱动以设备文件的形式挂载（创建）到用户可见目录下，通过对设备文件的访问实现对驱动的访问；

 2. led设备驱动框架提供了以sysfs方式访问设备驱动的方式:

    - sysfs在Linux2.6内核开始引入，用来导出内核对象（kobject）的数据、属性到用户空间，以文件目录结构的形式为用户提供访问这些数据、属性的支持；

    - 之前的驱动开发中三个比较重要的参数：

      - 设备号：挂载设备文件时，挂载的设备文件与驱动程序通过设备（主设备号+次设备号）进行匹配；
      - 设备名：int register_chrdev(unsigned int major, const char *name  const struct file_operations *fops),注册设备时，将设备号与设备名绑定，最终在cat  /proc/devices下体现出来；
      - 设备文件：用户程序通过该文件访问驱动，内核驱动通过该文件为用户提供操作接口；
      - 刚开始编写驱动带代码的时候，需要手动挂载设备文件mknod /dev/led c 125 0 (设备号与设备文件进行绑定)，后来为了解决该问题引入的class_create()和device_create()机制自动挂载、卸载设备驱动：
        - class_create()最终体现为在/sys/class 文件目录下新建一个“class-name”的文件夹first_cdev_class = class_create(THIS_MODULE,"led_class");；
        - device_create()最终体现为/sys/class 文文件目录下的“device-name”的目录first_cdev_device = device_create(first_cdev_class,NULL,MKDEV(major, 0), NULL, "led");；
        - device_create()在传参时会将自动分配的设备号（主设备号+次设备号）传入，如果检测到给参数不为0，则会在“device-name”目录下新建“dev”文件，该文件的内容就是传入的“主设备号：次设备号”；
        - udev应用程序检测sys/class 文件目录有变动，且在子目录中找到了对应的“dev”目录，就会在/dev下创建同名文件即设备文件（这也是为什么之前只是指定了设备名为led，应用程序open("/dev/lde")仍然可以正常使用的原因；
        - 至于文件是怎么被创建出来的这个涉及到Linux设备驱动模型代码----慢慢来；
        - ![9.48](/9.48.jpg)

     - led驱动框架核心代码集中在deviers/leds/led-class.c led-core.c两个源文件，留给驱动工程师的接口其实主要的就两个接口：

        - int led_classdev_register(struct device *parent, struct led_classdev *led_cdev)注册设备驱动

           -  device_create(leds_class, parent, 0, led_cdev,"%s", led_cdev->name);
              - 该接口主要是调用了device_create函数
                 - leds_class： 该设备所属类
                 - parent：该设备的父设备
                 - 0：设备号（主设备号+次设备号）
                    - 这里指定了设备号为0：
                       - device_create_vargs(class, parent, devt, drvdata, fmt, vargs);
                          - retval = device_register(dev);
                             - int device_add(struct device *dev)
                                - ![9.55](/9.55.jpg)
                    - 从上述代码可以看出，当自定设备号为0的时候不会进行device_create_file(dev, &devt_attr)操作，即不会再device-name目录下创建dev文件，也就是说在/dev找不到同名的设备文件（<u>遗留问题： 在该方式下如何查看已经为该设备分配的设备号？</u>）：
                       - ![9.56](/9.56.jpg)
                       - ![10.33](/10.33.jpg)
                 -  led_cdev->name：设备名称---体现在class-name 下的设备文件

        - void led_classdev_unregister(struct led_classdev *led_cdev)卸载设备驱动

        - 这里直接看到的就是在已有的class中创建device，那class的创建在哪完成？

           - led-class.c 中subsys_initcall(leds_init)

              - static int __init leds_init(void)

                 - leds_class = class_create(THIS_MODULE, "leds");

                    - __class_create(owner, name, &__key);	

                 - leds_class->dev_attrs = led_class_attrs;

                    - ```c
                      static struct device_attribute led_class_attrs[] = {
                      	__ATTR(brightness, 0644, led_brightness_show, led_brightness_store),
                      	__ATTR(max_brightness, 0444, led_max_brightness_show, NULL),
                      #ifdef CONFIG_LEDS_TRIGGERS
                      	__ATTR(trigger, 0644, led_trigger_show, led_trigger_store),
                      #endif
                      	__ATTR_NULL,
                      };
                      ```

                   - 这里的每一个attribute最终都现为class-name/device-name 文件夹的文件,以及对文件的操作方式(对于文件来说操作方式：读、写)

                     - ![10.50](/10.50-1562554337283.jpg)

             - 这些代码在什么时候被执行？驱动代码中并没有显示调用leds_ini()来完成这一系列操作：

               - /dirvers/leds/Kconfig:
                 - ![10.48](/10.48.jpg)
               - menuconfig驱动配置：
                 - ![10.46](/10.46.jpg)
               - 也就是说led-class.c文件其实已经作为内核内置的模块存在，在内核启动时会被自动insmod加载：
                 - 其实驱动开发通常都是在外部先以模块的形式手动加载、卸载进行编写、调试；
                 - 待驱动已经调试完毕，可以发布使用的时候如果有需要放置到内核中就使用上述的方式将驱动模块内置到内核中；
                 - 后续led驱动最终定型之后会进行该操作。

    - 再回到lint led_classdev_register(struct device *parent, struct led_classdev *led_cdev)

      - parent：父设备；

      - led_classdev ：

        - ~~~C
          struct led_classdev {
          	const char	*name;
          	int			 brightness;
          	int			 max_brightness;
          	int			 flags;
          
          ```
          /* Lower 16 bits reflect status */
          ```
          
          #define LED_SUSPENDED		(1 << 0)
          	/* Upper 16 bits reflect control information */
          #define LED_CORE_SUSPENDRESUME	(1 << 16)
          #define LED_BLINK_ONESHOT	(1 << 17)
          #define LED_BLINK_ONESHOT_STOP	(1 << 18)
          #define LED_BLINK_INVERT	(1 << 19)
          
          ```
          /* Set LED brightness level */
          /* Must not sleep, use a workqueue if needed */
          void		(*brightness_set)(struct led_classdev *led_cdev,
          				  enum led_brightness brightness);
          /* Get LED brightness level */
          enum led_brightness (*brightness_get)(struct led_classdev *led_cdev);
          
          /*
           * Activate hardware accelerated blink, delays are in milliseconds
           * and if both are zero then a sensible default should be chosen.
           * The call should adjust the timings in that case and if it can't
           * match the values specified exactly.
           * Deactivate blinking again when the brightness is set to a fixed
           * value via the brightness_set() callback.
           */
          int		(*blink_set)(struct led_classdev *led_cdev,
          			     unsigned long *delay_on,
          			     unsigned long *delay_off);
          
          struct device		*dev;
          struct list_head	 node;			/* LED Device list */
          const char		*default_trigger;	/* Trigger to use */
          
          unsigned long		 blink_delay_on, blink_delay_off;
          struct timer_list	 blink_timer;
          int			 blink_brightness;
          
          struct work_struct	set_brightness_work;
          int			delayed_set_value;
          ```
          
          #ifdef CONFIG_LEDS_TRIGGERS
          	/* Protects the trigger data below */
          	struct rw_semaphore	 trigger_lock;
          
          ```
          struct led_trigger	*trigger;
          struct list_head	 trig_list;
          void			*trigger_data;
          /* true if activated - deactivate routine uses it to do cleanup */
          bool			activated;
          ```
          
          #endif
          };
          ~~~

          该驱动代码涉及到的成员：

          - const char	*name:设备名称，forlinx_led_classdev.name = "forlinx_led"，最终体现为/sys/class/leds/forlinux_led文件夹的名称；
          - int		      brightness：设备操作文件，最终体现问/sys/class/leds/forlinux_led/brightness文件中的内容（文件并不是在这里指定），可读、可写，从名称来看可以理解为“亮度”，但是对于一般的LED来说只有亮、灭，并没有中间状态，如果是使用PWM控制的会有亮-灭的渐变过程，forlinx_led_classdev.brightness = 0;默认led灭；

            - 

          - int		      max_brightness：设备操作文件，最终体现问/sys/class/leds/forlinux_led/max_brightness文件中的内容（文件并不是在这里指定），可读、不可写，与上相同，对于一般的LED来讲只有亮灭两个状态，所以iforlinx_led_classdev.max_brightness = 1，而且在brightness的合法性检查中用到了该值：

            - 

          - void		(*brightness_set)(struct led_classdev *led_cdev enum led_brightness brightness):函数指针指向brightness的实际写函数,或者说当向brightness写入一个数据的时候就会调用该函数并且见写入brightness的值作为参数传入到led_cdev->brightness_set(led_cdev, value)中

            - ```C
              static struct device_attribute led_class_attrs[] = {
              	__ATTR(brightness, 0644, led_brightness_show, led_brightness_store),
              	__ATTR(max_brightness, 0444, led_max_brightness_show, NULL),
              #ifdef CONFIG_LEDS_TRIGGERS
              	__ATTR(trigger, 0644, led_trigger_show, led_trigger_store),
              #endif
              	__ATTR_NULL,
              };
              ```

              - led_brightness_store()

                - __led_set_brightness(led_cdev, state);

                  - ```c
                    led_cdev->brightness_set(led_cdev, value);
                    ```

                    

    - 通过以上分析，驱动代码实际要做的就是编写brightness_set()函数，在该函数中实现led的亮、灭：

      ```c
       static void forlinx_led_brightness_set(struct led_classdev *led_cdev,enum led_brightness brightness)
      {
      	printk(KERN_INFO "forlinx_led_brightness_set\n");
      	if(0 == brightness)
      	{
      		pgpio_led->DATAOUT |= (1 << 16);
      		
      
      	}else 
      	{
      		pgpio_led->DATAOUT  &= ~(1 << 1);
      	}
      
      }
      
      
      ```

    3. 对于sys文件系统、以及attribute、文件目录创建 class、device等知识点都是Linux设备驱动模型说明(<u>遗留问题：当前没有完整的时间代码级详细分析，先知道实现了什么功能，怎么使用，至于怎么做到的后续研究，做一定要做什么时候做，怎么做有时候真取决于能力，设备驱动模型代码级分析还是很有难度的，如果一开始就扎入这块内容中可能就淹死在内核代码中了</u>)；

##### 应用层代码：

​	无。

##### 编译脚本：

​	同上一版本。

##### 使用方法：

​	开机正常挂载nfs文件夹：

- 进入设备文件夹;
- 对brightness文件进行读写操作led;
- ![11.34](/11.34.jpg)

​	

##### 实现效果：

​	通过对brightness 文件的读写实现led的亮、灭。

### gpiolib的使用

​	内核驱动工程师提供了统一的gpio编程使用框架，框架只是一种编码的公约并不是强制要求必须使用，至于为什么使用框架，伟大的网友说是为了方便内核统一管理系统gpio资源，防止访问冲突，其实还有一层理由就是能能够看懂别人用gpio框架写的代码，看懂代码的最好方式就是自己也写一遍（有时候我并不排斥，甚至是喜欢重复造轮子的过程，但绝不是单纯的体力劳动）。

1. 使时需要包含头文件#include <linux/gpio.h；
2. gpiolib.c时内核gpio留出的统一接口：
   - int gpio_request(unsigned gpio, const char *label):申请GPIO资源：
     - gpio：需要申请的gpio编号，对于AM335X来说就是bank_num*32+offset
     - label:对应的gpio名称；---在哪里可以体现？
   - void gpio_free(unsigned gpio)：释放之前申请的gpio资源；
   - int gpio_direction_input(unsigned gpio)：设置gpio为输入模式；
   - int gpio_direction_output(unsigned gpio, int value)：设置gpio为输出模式；
   - void __gpio_set_value(unsigned gpio, int value)：设定gpio为value，gpio_get_value的底层实现就是该函数；
   - int __gpio_get_value(unsigned gpio)：获取gpio对应值，gpio_get_value的底层实现就是该函数；

#### 代码实现

##### 驱动代码：

~~~C
/*
	使用gpiolib 框架重写led驱动
*/

#include <linux/fs.h>	  	 /*包含file_operations结构体操作接口*/
#include <linux/init.h>   	 /*包含__init __exit*/
#include <linux/module.h> 	 /*module 操作函数*/
#include <linux/leds.h>  	 /*led驱动框架接口*/
#include <linux/io.h>     	 /*ioremap unioremap 操作*/
#include <linux/gpio.h> 	 /*包含gpio操作接口*/

#define GPIO_TO_PIN(bank, gpio) (32 * (bank) + (gpio))
#define LED_GPIO_NUM   GPIO_TO_PIN(3, 16)  //GPIO3_16

#define LED_ON 0
#define LED_OFF 1

#define LED_NAME "forlinx_led"

#define GPIO3_REG_BASE 0x481AE000

static struct led_classdev forlinx_led_classdev;

static void forlinx_led_brightness_set(struct led_classdev *led_cdev,enum led_brightness brightness)
{
	printk(KERN_INFO "forlinx_led_brightness_set\n");
	if(0 == brightness)
	{
		gpio_set_value(LED_GPIO_NUM, LED_OFF);
		

```
}else 
{
	gpio_set_value(LED_GPIO_NUM, LED_ON);
}
```

}

static int __init led_forlinx_init(void)
{
		if(gpio_request(LED_GPIO_NUM, "forlinx_led")) 
		{
			printk(KERN_ERR "gpio_request failed\n");
		} 
		else 
		{
			gpio_direction_output(LED_GPIO_NUM, 1);
		}
		forlinx_led_classdev.name = LED_NAME;
		forlinx_led_classdev.brightness = 0;
		forlinx_led_classdev.max_brightness = 1;
		forlinx_led_classdev.brightness_set = forlinx_led_brightness_set;
		led_classdev_register(NULL,&forlinx_led_classdev);
		return 0;
}

static void __exit led_forlinx_exit(void)
{
	led_classdev_unregister(&forlinx_led_classdev);
	gpio_free(LED_GPIO_NUM);
}

module_init(led_forlinx_init);
module_exit(led_forlinx_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("xptd");
MODULE_DESCRIPTION("led_forlinx dirver");
~~~

1. insmod led-forlinx.ko:

   - module_init(led_forlinx_init);

     - led_forlinx_init:

       - gpio_request(LED_GPIO_NUM, "forlinx_led"):gpio_request只是内核提供的统一接口，针对不同的平台需要有不同实现函数

         - desc = &gpio_desc[gpio];这是一个比较难找的点:

           - 一个gpio_desc，就代表一个gpio管脚，gpio_desc中又包含了一个gpio_chip，gpio_chip表示一个gpio控制器对于AM335X来说就有GPIO0-GPIO3四个GPIO控制器，每个gpio控制器包含32个gpio：

             - GPIO0:0x44E0_7000~0x44E0_7FFF 
             - GPIO1:0x4804_C000~0x4804_CFFF
             - GPIO2:0x481A_C000~0x481A_CFFF
             - GPIO3:0x481A_E000~0x481A_EFFF 

           - 执行gpio_request()函数申请一个gpio时，就会查询当前的gpio_desc[]结构体数组，如果找到了则执行后续的配置动作，找不到直接返回错误，问题的关键在于数组的初始化动作发生在哪里（具体的硬件平台gpio信息在什么时候记录到内中，此时先不考虑有设备数dtb的情况）？

             - gpiochip_add()函数中有如下代码：

               ```c
               for (id = base; id < base + chip->ngpio; id++) 
               			gpio_desc[id].chip = chip;
               ```

                在gpiochip_add()函数中完成了gpio_desc[]主要填充工作：完整的代码调用层次：

               - postcore_initcall(omap_gpio_drv_reg):内核在启动的时候platform_driver_register()已经注册了该模块，当有device进行注册的时候通过platform bus matc到相应的驱动代码，然后完成gpio_des[]的填充

                 - platform_driver_register(&omap_gpio_driver);

                   - omap_gpio_driver

                     ​	![17.29](/../../../17.29.jpg)

                     - .probe = omap_gpio_probe,

                       - omap_gpio_probe

                         - omap_gpio_chip_init()

                           - gpiochip_add()

                             ![18.21](/18.21.jpg)

                             ![omap](/omap.jpg)

                     ​					

         - status = chip->request(chip, gpio - chip->base);

           - static void omap_gpio_chip_init(struct gpio_bank *bank)
             - bank->chip.request = omap_gpio_request;gpio_request()最终会调用omap_gpio_request函数，

2. echo 1 > brightness

   - forlinx_led_brightness_set
     - gpio_set_value
       - __gpio_set_value(unsigned gpio, int value)

3. gpiolib调用流程：

   - postcore_initcall(omap_gpio_drv_reg);

     -  platform_driver_register(&omap_gpio_driver);

       ```C
       static struct platform_driver omap_gpio_driver = {
       			.probe		= omap_gpio_probe,
       			.driver		= {
       			.name	= "omap_gpio",
       			.pm	= &gpio_pm_ops,
       			.of_match_table = of_match_ptr(omap_gpio_match),
       			},
       		};
       ```
       - static int omap_gpio_probe(struct platform_device *pdev)

         - 应该是"omap_gpio"device在注册的时候触发了platform bus的match函数，两者的name匹配之后就调用了platform dirver的probe函数;

         - 在当前工程目录下搜索“omap_gpio”：arch\arm\mach-omap2\gpio.c

           - static int __init omap2_gpio_dev_init(struct omap_hwmod *oh, void *unused)
             - char *name = "omap_gpio";
             - pdev = omap_device_build(name, id - 1, oh, pdata,sizeof(*pdata),	NULL, 0, false);
               - omap_device_build_ss(pdev_name, pdev_id, ohs, 1, pdata,pdata_len, pm_lats, pm_lats_cnt,is_early_device);
                 - dev_set_name(&pdev->dev, "%s.%d", pdev->name,  pdev->id);
                 - ret = omap_device_register(pdev);
                   - platform_device_add(pdev);
                     - device_add(&pdev->dev)： 也就是说没调用一次omap2_gpio_dev_init()gpio就会触发一次omap_gpio_probe

         - 在同文件下：

           - postcore_initcall(omap2_gpio_init);

             - static int __init omap2_gpio_init(void)(不考虑设备树的情况，如果有设备树不会执行以下操作)

               - return omap_hwmod_for_each_by_class("gpio", omap2_gpio_dev_init, NULL);

                 - ```c
                   list_for_each_entry(temp_oh, &omap_hwmod_list, node) {
                   							if (!strcmp(temp_oh->class->name, classname)) {
                   								ret = (*fn)(temp_oh, user);
                   							}
                   						}
                   ```

                   

                 - 在omap_hwmod_list链表中找到“gpio”匹配的则进行omap2_gpio_dev_init,实质上是执行了device_add(&pdev->dev);

                 - 在omap_hwmod_list中有几个“gpio”就进行几次device_add(),当device_add执行完之后，与“omap-gpio”同名的dirver进行匹配，匹配之后执行omap_gpio_probe函数

           - omap_gpio_chip_init(bank);-----在probe 函数中调用了omap_gpio_chip_init---bank数据从哪来

             - gpiochip_add(&bank->chip);

               - ```C
                 for (id = base; id < base + chip->ngpio; id++)
                 					gpio_desc[id].chip = chip;//填充gpio_desc数组，gpiolib操作全部基于该数组
                 ```

                 

         - 至此只要omap_hwmod_list中存在“gpio”相关数据节点，在kernel启动时就是自动被omap_gpio_probe()填充到gpio_desc[]数组中。

   - omap_hwmod_list怎么来?(/* omap_hwmod_list contains all registered struct omap_hwmods */)

     - __init am33xx_hwmod_init(void)
       - am33xx_hwmod_init()
       - return omap_hwmod_register_links(am33xx_hwmod_ocp_ifs);
         - int __init _register_link(struct omap_hwmod_ocp_if *oi)
           - _register(oi->master);
             - list_add_tail(&oh->node, &omap_hwmod_list);
           - _register(oi->slave);
             - list_add_tail(&oh->node, &omap_hwmod_list);
     - am33xx_hwmod_ocp_ifs:才是所有配置的源头

   - 上述代码流程验证(kernel启动消息)：

     ```C
     omap_hwmod: omap_hwmod_for_each_by_class: looking for modules of class gpio
     omap_hwmod: omap_hwmod_for_each_by_class: gpio1: calling callback fn
     omap2_gpio_dev_init
     omap_device_build
     omap_device: omap_gpio: registering
     Registering platform device 'omap_gpio.0'. Parent at platform
     
     omap_hwmod: omap_hwmod_for_each_by_class: gpio2: calling callback fn
     omap2_gpio_dev_init
     omap_device_build
     omap_device: omap_gpio: registering
     Registering platform device 'omap_gpio.1'. Parent at platform
     omap_hwmod: omap_hwmod_for_each_by_class: gpio3: calling callback fn
     omap2_gpio_dev_init
     omap_device_build
     omap_device: omap_gpio: registering
     Registering platform device 'omap_gpio.2'. Parent at platform
     omap_hwmod: omap_hwmod_for_each_by_class: gpio4: calling callback fn
     omap2_gpio_dev_init
     omap_device_build
     omap_device: omap_gpio: registering
     Registering platform device 'omap_gpio.3'. Parent at platform
     
     omap_gpio_probe
     omap_gpio_chip_init
     gpiochip_add: registered GPIOs 0 to 31 on device: gpio
     OMAP GPIO hardware version 0.1
     omap_gpio_probe
     omap_gpio_chip_init
     gpiochip_add: registered GPIOs 32 to 63 on device: gpio
     omap_gpio_probe
     omap_gpio_chip_init
     gpiochip_add: registered GPIOs 64 to 95 on device: gpio
     omap_gpio_probe
     omap_gpio_chip_init
     gpiochip_add: registered GPIOs 96 to 127 on device: gpio
     
     omap_gpio_probe
     omap_gpio 44e07000.gpio: Region already claimed
     omap_gpio: probe of 44e07000.gpio failed with error -16
     omap_gpio_probe
     omap_gpio 4804c000.gpio: Region already claimed
     omap_gpio: probe of 4804c000.gpio failed with error -16
     omap_gpio_probe
     omap_gpio 481ac000.gpio: Region already claimed
     omap_gpio: probe of 481ac000.gpio failed with error -16
     omap_gpio_probe
     omap_gpio 481ae000.gpio: Region already claimed
     omap_gpio: probe of 481ae000.gpio failed with error -16
     ```

     

   

4. gpio_set_value()函数调用流程：

   - 

   

5. 这一块目前只是把大体的工作流程粗略的了解了一下，具体的代码级实现还没有完全明白

##### 应用层代码：

​	无。

##### 编译脚本：

​	与上一版本相同。

##### 使用方法：

​	与上一版本相同。

##### 实现效果：

​	与上一版本相同。

​	

### platform平台设备总线方式驱动  