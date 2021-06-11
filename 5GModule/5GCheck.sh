#!/bin/bash

# 对比源文件和目标文件不一致，或者目标文件不存在则拷贝
# $1 : 源文件，不校验源文件存在，需要确保源文件存在
# $2 : 目标文件
cmp_copy()
{
    cmp -s $1 $2
    if [ $? -ne 0 ];then
        cp -f $1 $2
    fi
}

###1. 拷贝5G udev监测
com_dir=/home/dahua/agv_workspace/install/install_sys/share/agv_usystem/common
cmp_copy $com_dir/5GModule/5Gudev.sh  /etc/5Gudev.sh
#解决重启时检查网络耗时问题
cmp_copy $com_dir/5GModule/networking.service /lib/systemd/system/networking.service 

###2. 等待5G模组本身启动
sleep 3
echo on > /sys/bus/usb/devices/usb1/power/level
echo on > /sys/bus/usb/devices/usb2/power/level
sleep 2

###3. 确定是5G设备ID,则设备udev文件拷贝
###3. cdcnum表示读取次数限制读取15次，15次内读取不到表示读取失败
cdcnum=0
deviceid="12d1:1506"
deviceid1="2cb7:0105"
deviceid2="12d1:15c3"
while((1))
do
    netd=`lsusb | grep -E "$deviceid" | cut -d " " -f6`
    netd1=`lsusb | grep -E "$deviceid1" | cut -d " " -f6`
    netd2=`lsusb | grep -E "$deviceid2" | cut -d " " -f6`
    if [ "$netd" = "$deviceid" ] || [ "$netd1" = "$deviced1" ] || [ "$netd2" = "$deviced2" ];then
        cmp_copy  $com_dir/DefaultNetSet/cdc-NetSet.sh /etc/NetSet.sh
        cmp_copy  $com_dir/DefaultNetSet/cdc-75-usb-net.rules /etc/udev/rules.d/75-usb-net.rules
        chmod 755  /etc/NetSet.sh
        chmod 755  /etc/udev/rules.d/75-usb-net.rules
        exit 1  
    fi
    cdcnum=`expr $cdcnum + 1`
    if [ "$cdcnum" = "15" ];then
        echo  `date`" : [e] 5GCheck.sh  5G Module Device is not exists!" >> /var/log/5glog
        exit 1
    fi
    sleep 1
done

