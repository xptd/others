#!/bin/bash
echo `date`" : [0] Start hotplug ,maybe in starting up or using hotplug">> /var/log/5glog

#0.set source dir
cpath=/mnt/mtd/Config
rpath=/home/dahua/agv_workspace/install/install_com/share/agv_config/resource

#1.make sure ko have insmod
#n 表示查询cdc_ether 驱动的次数，限制查询10次，查询不到则退出，
n=0
netd=`lsusb -t | grep -E "cdc_ether" | head -n1 | cut -d "," -f4 | cut -d "=" -f2`
while [ "$netd" != "cdc_ether" ]
do
    sleep 1
    let n++
    netd=`lsusb -t | grep -E "cdc_ether" | head -n1 | cut -d "," -f4 | cut -d "=" -f2`
    if [ "$netd" == "cdc_ether" ];then
        echo `date`" : [1] cdc_ether re-insmod success" >> /var/log/5glog
        break
    else
        if [ "$n" == 10 ];then
            echo `date`" : [1] cdc_ether is not insmod ,please check" >> /var/log/5glog
            exit 1
        fi
    fi
done

#2.make sure ttyUSB0
#m表示查询ttyUSB0的次数，限制查询10次。10次查询不到就退出
ser=`ls /dev |grep "ttyUSB0"`
m=0
while [ "$ser" != "ttyUSB0" ]
do
    sleep 1
    let m++
    ser=`ls /dev |grep "ttyUSB0"`
    if [ "$ser" == "ttyUSB0" ];then
        echo `date`": [2] ttyUSB refind success" >> /var/log/5glog
        break
    else
        if [ "$m" == 10 ];then
            echo `date`" : [2] ttyUSB is error,please check" >> /var/log/5glog
            exit 1
        fi
    fi
done

#3.eth2 reay ,set ip and gw
ifconfig eth2 up
/home/dahua/agv_workspace/install/install_sys/share/agv_usystem/common/5GModule/serrw.py &
sleep 1
rm /var/log/5gip
echo `date`" : [3] 5G DHCP have started ,wait for few secs ;if ip is can't be arrive ,check 5G Module-hardware!">> /var/log/5glog
