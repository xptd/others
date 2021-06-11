# 模块

- 如果将所有的的功能组件都编译进内核会带来两个问题：
  - 生成 的内核会很大；
    - vmlinux是直接编译生成的没有压缩的内核文件；
    - zImage是将没有压缩的的解压算法以及压缩后的内核文件的组合文件，BootLoader在启动会见zImage加载到内存并是有zImag中没有压缩的解压算法对压缩的内核文件进行解压；
  - 如果需要在现有内核中新增或删除功能，将不得不重新编译内核；

- Linux提供了模块机制：

  - 模块本身不被编译进内核，所以可以控制内核的大小;
  - 模块一旦被加载，它就和内核中的其它部分一致;

- Linux2.6之前模块的后缀名是“*.o”，Linux2.6之后模块的后缀名变成了“*。ko”;

- 相关头文件包含

  - ```c
    #include<linux/module.j>
    #include <linux/init.h>
    ```

- 模块必须包含：

  - 模块加载函数；
  - 模块卸载函数；
  - 模块许可声明；

- printk函数输出消息在/var/log/syslog或者/var/log/messages文件中查看

  - ```
    tail -n 10 /var/log/syslog
    ```

    

## 模块查看

- 在shell 命令行模式下可以通过“lsmode” 命令参看当前系统已经加载的模块；
- lsmode命令其实是读取“/proc/modules”文件；
  - 所以直接查看该文件可以获取到与lsmode命令相同的信息；
- 内核中已经加载的模块会在"/sys/module/"目录下新增一个同名目录；
- **modinfo**<模块名> 命令可以获取模块的信息：
  - 模块作者：
  - 模块说明：
  - 模块所支持的参数：
  - vermagic：
  - ...
  - 

## 模块加载

- 在shell命令行模式下可以通过一下命令加载模块：

  - insmod pathname
  - modprobe pathname
    - modprobe 命令除了加载指定的模块之外还将该模块的依赖模块一起加载。

- 模块的依赖关系：

  - 在内核整体编译过程时有**depmod**工具生成；

  - 依赖文件存放在：

    - ```c
      /lib/modules/<kernel-version>/modules.dep
      ```

- 模块加载函数：模块被加载时，模块的加载函数会自动被内核执行，完成本模块的相关初始化工作

  - ```
    static int __init init_function(void);
    module_init(init_function);
    ```

  - module_init

    - 返回值:
      - 成功：0
      - 失败：负数，错误码（-ENOMEM）；

- 在驱动代码中加载其它模块：

  ```
  request_module(const char*fmt,...);
  ```

- __init 标识符：

  - 在Linux中，所有标识为**__init**的函数如果直接编译进内核，成为内核的一部分，在链接的时候都会放在**.init.text**段内；

    - ```
      #define __init __attribute__((__section__(".init.text")))
      ```

  - 所有__init函数在区段**.initcall.init**中还保存了一份函数指针，在初始化的时候内核会通过调用浙西函数指针调用\_\_init函数，并在初始化完成之后，释放\_\_init区段（.init.text以及.initcall.init等）的内存；

- __initdata标识符：

  - 对于只是在初始化阶段需要的数据，内核在初始化完成之后可以释放他们的内存；

  - ```
    static int var __initdata = 1;
    ```

- 

## 模块卸载

- 在shell 命令行模式下可以通过以下命令卸载模块：

  - rmmod pathname
  - modprobe-r pathname
    - modprobe-r 在卸载时同时会把依赖的模块一同卸载

- 模块卸载函数：卸载模块时，模块卸载函数会被自动执行，完成与模块加载函数相反符功能；

  - ```
    static void __exit exit_function(void);
    module_exit(exit_function);
    ```

  - 模块卸载时执行模块卸载函数，不返回任何值；

    - 类似exit()函数与atexit()函数的功能，且atexit()注册的函数类型为：

      - ```
        void exit_function(void )
        ```

      - 没有返回值，不接受任何参数（都退出了接收参数有也没有什么必要了）

  - 加载函数一般以“__exit”标识声明

- __exit标识符：

  - 通知内核如果相关的模块被直接编译进内核（build-in）则__exit修饰的函数会被忽略，**直接不链接进最后的镜像**；
    - 既然都模块内置了，就不可能卸载它了，卸载函数也就没有存在的必要了。

- __exitdata标识符：

  - 修饰只在退出阶段使用的数据；
  - 

## 模块参数（可选）

- 模块被加载的使用可以传递给它的值，它本身对应**模块内部的全局变量**；

- 定义参数：

  - module_param(参数名，参数类型，参数读\写权限)

  - ```
    static char* book_name = "xptd";
    module_param(book_name,charp,S_IRUGO);
    
    ```

- 模块传参：模块编译时会将module_param中声明的类型与变量定义的类型进行比较，判断是否一致

  - 手动装载模块：
    - insmod（modprobe） 模块名称 参数名=参数值
  - 内置模块传参：
    - bootloader可以通过在**bootargs**里设置“模块名.参数名=值”；

- 参数类型：

  - byte
  - short
  - ushort
  - int
  - uint
  - long
  - ulong
  - **charp**：字符指针
  - bool
  - invbool

- 参数**数组**：

  - module_param_array(数组名，数组类型，数组长，参数读、写权限)；

- 如果一个模块有定义的模块参数（以module_param指明的参数）模块加载之后早**/sys/module/**目录下会有多一个**“parameters”**文件夹

  - 当参数的读、写权限为0时，表示不在sysfs文件系统下对应的文件节点；
  - 当参数的读、写权限不为0时在parameters文件夹下会出现一系列**以参数名命名的文件结点**，文件的内容为参数的值；
  - 
  - cat 查看参数值；
  - echo 0 > param 参数赋值；

- 

## 模块符号（可选）

- 内核模块可以导出的符号（symbol），若导出，其它模块则可以使用本模块中的变量或者函数；
- 

## 模块信息

### 许可信息

- MODULE_LICENSE(""):声明该内核模块的许可权限，如果不声明LICENSE，模块被加载时，将手到内核被污染（Kernel Tainted）的**警告**；
- Linux内核所接受的许可证明包括：
  - GPL；
  - GPL v2；
  - Dual BS/GPL；
  - ....
  - 大多数情况下，内核模块应遵从GPL兼容许可权：
    - MODULE_LICENSE("GPL v2"):最常用
- 

### 其它信息（可选）

- 可以通过modinfo <模块名>查看模块信息；

- 作者:
  - MODULE_AUTHOR()
- 描述:
  - MODULE_DESCRIPTION()
- 别名
  - MODULE_ALIAS
- vermagic:版本号
  - MODULE_VERSION
- 

## 导出符号

- Linux 系统下的“/proc/kallsyms”文件对应着内核符号表，它记录了符号所在的内存地址；

- 导出符号方法：

  - ```
    EXPORT_SYMBOL(符号)；
    ```

  - ```
    EXPORT_SYMBOL_GPL(symbol)
    ```

    

- 导出的符号(函数、变量)可以被其它模块使用，只需要在使用前声明一下；

- MODULE_DEVICE_TABLE:**表明该驱动模块所支持的的设备；**

## 模块使用计数

- Linux2.4内核使用MOD_INC_USE_COUNT、MOD_DEC_USE_COUNT宏管理自己的被使用的计数；

- Linux2.6之后的内核使用**try_module_get(&module)**和**module_put(&module)**,取代了Linux2.4的模块管理方式；

  - ```
    int try_module_get(struct module*module);
    ```

  - ```c
    void module_put(struct module *module);
    ```

- Linux2.6之后不同类型的设备定义了struct module *owner域，用来指向管理此设备的模块（设备隶属于某个模块）：

  - 当开始使用某个设备时，内核使用try_module_get(device->owner)去增加管理此设备的owner模块的使用计数；
  - 当不再使用此设备时，内核使用module_put(device->owner)减少对设备的管理的模块的使用计数。
    - 当设备在使用是，管理此设备的模块将不能被卸载，只有当设备不在使用时，模块才允许被卸载；

- <font color = red>Linux2.6之后的内核其实编程人员基本不需要手动调用模块计数函数，基本上这部分交给总线驱动代码取处理</font>；

- 

## 模块编译

- Linux中的源文件的编译由Makefile管理：

  - ```makefile
    KVERS =$(shell uname -r)
    obj-m += hello.o
    #EXTRA_CFLAGS=-g-O0
    build:kernel_modules
    kernel_modules:
    	make -C /lib/modules/$(KVERS)/build M=$(CURDIR) modules
    clean:
    	make -C /lib/modules/$(KVERS)/build M=$(CURDIR) clean
    ```

  - EXTRA_CFLAGS=-g-O0:可以得到包含调试信息的目标模块；

  - 

## 避开GPL许可：

- 内核中使用EXPORT_SYMBOL_GPL()导出的符号是不可以被非GPL模块所引用的
- 改写内核中的EXPORT_SYMBOL_GPL()为EXPORT_SYMBOL(),这种做法可能构成“蓄意侵权”
- 写一个遵循GPL 的wrapper内核模块，把EXPORT_SYMBOL_GPL()导出的符号封装一次再以EXPORT_SYMBOL()的形式导出，而其他模块不直接调用内核而是调用wrapper函数；
- 一般认为、保守的做法是Linux内核不能使用非GPL许可权；

  - 模块加入内核的时候是可以指定为开源、闭源LICENSE,如果模块指定了闭源属性，但是在模块代码中引用了GPL模块中的符号（变量、函数）的话编译会报错；

  - 自己编写的模块代码指定了闭源属性，但是又想（或者是不得不）在闭源代码中引用GPL的符号（变量、函数），这个时候就需要想办法避开GPL

# Linux文件系统与设备文件
- 设备文件：对应应用程序员来讲将一个设备抽象为一个文件，对设备文件的相关操作即是对设备的操作；

  - 在Linux系统中“一切皆文件”的设计思想，一个设备可以虚拟我一个设备文件
  - 驱动最终通过**与文件操作相关**的系统调用接口或C库函数（最终也会指向系统调用接口）被访问，而设备驱动的结构最终也是为了迎合提供给应用程序员的API;
  - 驱动工程师在设备驱动中不可避免地会与设备文件吸引打交道
    - Linux2.4的devfs;	
    - Linux2.6的udev;

##文件操作
### 系统调用接口
### 标准C库操作接口
## Linux文件系统
### Linux文件系统目录结构
- Linux文件系统的入口即**根目录（“/”）**，也是出于最高一级的目录；
  - 