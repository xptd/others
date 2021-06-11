#!/bin/bash
echo `date`" :                                " >> /var/log/5glog 
echo `date`" : [0] Start to Connect 5G Module " >> /var/log/5glog 

#0.hotplug eth2 ,but 5G hasn't ready ,kill it
ps -ef | grep "serrw.py" | awk '{print $2}'| xargs kill -9
###parse ip and gw
hextoip()
{
    hex=$1
        printf "%d." 0x${hex:6:2}
    printf "%d." 0x${hex:4:2}
    printf "%d." 0x${hex:2:2}
    printf "%d" 0x${hex:0:2}
}
#1.make sure cdc_ether 
#n表示查询cdc_ether,默认查询次数10次，超出限制则表示默认没有该5G设备
n=0
netd=`lsusb -t | grep -E "cdc_ether" | head -n1 | cut -d "," -f4 | cut -d "=" -f2`
while [ "$netd" != "cdc_ether" ]
do 
    let n++
    if [ "$n" == 20 ];then
        echo `date`" : [1] 5G Module Device isn't founded " >> /var/log/5glog 
        exit 1
    fi
    sleep 1
    netd=`lsusb -t |grep -E "cdc_ether" |head -n1 |cut -d "," -f4 |cut -d "=" -f2`
done

DID=`lsusb | grep "2cb7:0105" | cut -d " " -f6`
if [ "$DID" = "2cb7:0105" ];then
    echo `date`" : [1] FM150 5G Module Device is founded " >> /var/log/5glog 
    #2.get dhcp ip and gw from ttyUSB
    dh=`cat /var/log/5gip  | grep -E "GTRNDIS:"`
    m=0 
    while ((1)) 
    do  
        let m++
        if [ "$m" == 100 ];then
            echo `date`" : [2] FM150  Have try "$m"th connect,exit" >> /var/log/5glog
            exit 1
        fi
        /home/dahua/agv_workspace/install/install_sys/share/agv_usystem/common/5GModule/serrw_G.py &
        sleep 10
        echo `date`" : [2] FM150 Have try "$m"th connect,try one more" >> /var/log/5glog
        dh=`cat /var/log/5gip | grep -E "GTRNDIS:"`
        if [ "$dh" != "" ];then
			ndisvalue=`echo $dh |cut -d ":" -f2`
            if [ "$ndisvalue" != "0" ];then
                echo `date`" : [2] FM150  Have Get ip and gw,start to resolve" >>/var/log/5glog
                break
            fi
        fi
        ps -ef | grep "serrw_G.py" | awk '{print $2}'| xargs kill -9
    done 
    #3.get ip and gw,dec change to ip address,attention high and low bit is against
    ipgwarg=`cat /var/log/5gip  | grep GTRNDIS: | cut -d "," -f3 |awk '{gsub(/"/,"");print $0}'`
    ip=$ipgwarg
    ip1=`echo $ipgwarg | cut -d "." -f1`
    ip2=`echo $ipgwarg | cut -d "." -f2`
    ip3=`echo $ipgwarg | cut -d "." -f3`
    ip4=`echo $ipgwarg | cut -d "." -f4`
    MASK="255.255.255.0"
    ipn=`expr $ip4 + 1`
    gw=$ip1"."$ip2"."$ip3"."$ipn
    echo `date`" : [3] FM150  Have resovle ip : $ip , gw : $gw" >>/var/log/5glog
fi

DID=`lsusb | grep "12d1:15c3" | cut -d " " -f6`
if  [ "$DID" = "12d1:15c3" ];then
    echo `date`" : [1] Panda 5G Module Device is founded " >> /var/log/5glog 
    sleep 1
    #2.get dhcp ip and gw from ttyUSB
    dh=`cat /var/log/5gip | grep -E "DHCP:"`
    m=0 
    while ((1)) 
    do  
        let m++
        if [ "$m" == 100 ];then
            echo `date`" : [2] Panda-5G Have try "$m"th connect,exit" >> /var/log/5glog
            exit 1
        fi
        /home/dahua/agv_workspace/install/install_sys/share/agv_usystem/common/5GModule/serrw_X.py &
        sleep 0.5
        echo `date`" : [2] Panda-5G Have try "$m"th connect,try one more" >> /var/log/5glog
        dh=`cat /var/log/5gip | grep -E "DHCP:"`
        if [ "$dh" != "" ];then
            echo `date`" : [2] Panda-5G Have Get ip and gw,start to resolve" >>/var/log/5glog
            break
        fi
        ps -ef | grep "serrw_X.py" | awk '{print $2}'| xargs kill -9
    done 
    #3.get ip and gw,dec change to ip address,attention high and low bit is against
    ipgwarg=`cat /var/log/5gip | grep -E "DHCP:" |cut -d ":" -f2 `
    IP=`echo $ipgwarg | cut -d "," -f1 | sed -e 's/^[ ]*//g' |sed -e 's/[ ]*$//g'`
    Mask=`echo $ipgwarg | cut -d "," -f2 | sed -e 's/^[ ]*//g' |sed -e 's/[ ]*$//g'`
    GW=`echo $ipgwarg | cut -d "," -f3 | sed -e 's/^[ ]*//g' |sed -e 's/[ ]*$//g'`
    ip=`hextoip $IP`
    MASK=`hextoip $Mask`
    gw=`hextoip $GW`
    echo `date`" : [3] Panda-5G  Have resovle ip : $ip , gw : $gw" >>/var/log/5glog
fi

DID=`lsusb | grep "12d1:1506" | cut -d " " -f6`
if  [ "$DID" = "12d1:1506" ];then
    echo `date`" : [1] NR-10 5G Module Device is founded " >> /var/log/5glog 
    sleep 1
    #2.get dhcp ip and gw from ttyUSB
    dh=`cat /var/log/5gip | grep -E "DHCP:"`
    m=0 
    while ((1)) 
    do  
        let m++
        if [ "$m" == 100 ];then
            echo `date`" : [2] NR-10 Have try "$m"th connect,exit" >> /var/log/5glog
            exit 1
        fi
        /home/dahua/agv_workspace/install/install_sys/share/agv_usystem/common/5GModule/serrw.py &
        sleep 0.5
        echo `date`" : [2] NR-10 Have try "$m"th connect,try one more" >> /var/log/5glog
        dh=`cat /var/log/5gip | grep -E "DHCP:"`
        if [ "$dh" != "" ];then
            echo `date`" : [2] NR-10 Have Get ip and gw,start to resolve" >>/var/log/5glog
            break
        fi
        ps -ef | grep "serrw.py" | awk '{print $2}'| xargs kill -9
    done 
    #3.get ip and gw,dec change to ip address,attention high and low bit is against
    ipgwarg=`cat /var/log/5gip | grep -E "DHCP:" |cut -d ":" -f2 `
    IP=`echo $ipgwarg | cut -d "," -f1 | sed -e 's/^[ ]*//g' |sed -e 's/[ ]*$//g'`
    Mask=`echo $ipgwarg | cut -d "," -f2 | sed -e 's/^[ ]*//g' |sed -e 's/[ ]*$//g'`
    GW=`echo $ipgwarg | cut -d "," -f3 | sed -e 's/^[ ]*//g' |sed -e 's/[ ]*$//g'`
    ip=`hextoip $IP`
    MASK=`hextoip $Mask`
    gw=`hextoip $GW`
    echo `date`" : [3] NR-10 Have resovle ip : $ip , gw : $gw" >>/var/log/5glog
fi

#4.write to CustomConfig
cpath=/mnt/mtd/Config
rpath=/home/dahua/agv_workspace/install/install_com/share/agv_config/resource
ddtype=`jq ".DeviceType" /var/robot/Product/Device.json | sed 's/\"//g'`
if [ "$ddtype" = "DH-RTA-C060-LC" ];then
   rpath=$rpath/project/agv_600kg_2258	
fi
if [ -e "$cpath/networketh2" ];then
    sed -i 's/\(HOSTIP = \).*/\1'$ip'/g' $cpath/networketh2
    sed -i 's/\(SUBMASK = \).*/\1'$MASK'/g' $cpath/networketh2
    sed -i 's/\(GATEWAYIP = \).*/\1'$gw'/g' $cpath/networketh2
    cat $rpath/CustomConfig |jq ".Network.DefaultInterface=\"eth2\""  |jq ".Network.eth2.IPAddress=\"$ip\"" | jq ".Network.eth2.SubnetMask=\"$MASK\"" | jq ".Network.eth2.DefaultGateway=\"$gw\"" > $rpath/CustomConfig_xbak
    sync
    mv $rpath/CustomConfig_xbak $rpath/CustomConfig
else
    cat $rpath/CustomConfig | jq ".Network.DefaultInterface=\"eth2\"" | jq ".Network.eth2.IPAddress=\"$ip\"" | jq ".Network.eth2.SubnetMask=\"$MASK\"" | jq ".Network.eth2.DefaultGateway=\"$gw\"" > $rpath/CustomConfig_xbak
    sync
    mv $rpath/CustomConfig_xbak $rpath/CustomConfig
fi
echo `date`" : [4] Have set ip in CustomConfig and networketh2 End" >>/var/log/5glog

#5.reset log
rm -rf /var/log/5gip
