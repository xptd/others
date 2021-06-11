#!/bin/bash
#########################################################################
# File Name: ./common/5GModule/5GCP.sh
# Author: xu hangnan
# mail: xuhangnan@dahuatech.com
# Created Time: Thursday, July 30, 2020 PM03:14:00 CST
#########################################################################
com_dir=/home/dahua/agv_workspace/install/install_sys/share/agv_usystem/common
if [ -f $com_dir/5GModule/5Gudev.sh ];then
	if [ ! -f /etc/5Gudev.sh ];then
		cp  $com_dir/5GModule/5Gudev.sh  /etc/
		chmod 777  /etc/5Gudev.sh
	else
		diff $com_dir/5GModule/5Gudev.sh  /etc/5Gudev.sh
		if [ $? -ne 0 ];then
			cp  $com_dir/5GModule/5Gudev.sh  /etc/
			chmod 777  /etc/5Gudev.sh
		fi
	fi
fi
if [ -f $com_dir/5GModule/hosts ];then
	cp $com_dir/5GModule/hosts  /etc
fi
if [ -f $com_dir/5GModule/resolv.conf ];then
	cp $com_dir/5GModule/resolv.conf /etc
fi

#解决重启时检查网络耗时问题
cp  $com_dir/5GModule/networking.service  /lib/systemd/system/networking.service 
