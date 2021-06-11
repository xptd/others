#!/usr/bin/python
#encoding:utf-8
import serial 
import sys,os,stat
from time import sleep
#定义串口，接收数据，文件fd等变量
global ser
global recdata
global fd

#定义接收函数，用于缓存接收串口数据
def recv():
	global ser
	flag=True
	if ser.isOpen():
		while flag:
			count = ser.inWaiting()
			if count != 0:
				data=ser.read(ser.in_waiting)
				ldata=data.split('\r\n')
				print(data)		
				if "OK" in ldata:
					flag = False
				if "ERROR" in ldata:
					flag = False
		return data
	else:
		return None		

#串口发送函数
def send(send_data):
	global ser
	if ser.isOpen():
		ser.write(send_data.encode('utf-8'))
		return 0	
	else: 
		print ("send failed!")
		rerurn -1 

#串口打开函数，信息保存文件指定
def port_open():
	global ser
	global fd
	ser=serial.Serial('/dev/ttyUSB2',115200,rtscts=True,dsrdtr=True,timeout=5)
	ser.flushInput()
	if ser.isOpen():
		fd=open('/var/log/5gip','wr')
		os.chmod("/var/log/5gip",stat.S_IRWXU | stat.S_IRWXG | stat.S_IRWXO )		
	else:
		print("open  /dev/ttyUSB2 failed!\n")
        os.system('echo `date`" serrw.py: [*] serial open failed" >>/var/log/5glog')

#主函数，实现发送串口命令并保存dhcp信息到文件
if __name__ == '__main__':
    #定义全部变量
        global ser
        global recdata
        global fd
        #设置发送次数
        sendcurc_count = 0
        sendcops_count = 0
        sendcgd_count = 0
        sendds_count = 0
        senddhcp_count =0 
        #串口打开
        port_open()
        print("start send")
        #尝试发送，限制发送次数
        try:
            while True:
                    while True:
                        sendicurc_count=sendcurc_count + 1
                        if sendcurc_count == 50:
                            os.system('echo `date`" : [*] serial send curc error">>/var/log/5glog')
                            sys.exit(1)
                        send("at+cops?\r\n")
                        recdata=recv()
                        if recdata is None:
                            continue
                        if "OK" in recdata:
                            print("send 1 next")
                            break	
                        else:
                            continue
                    fd.write(recdata.decode('utf-8'))
                    fd.write('\n')
                    while True:
                            sendcops_count=sendcops_count + 1
                            if sendcops_count == 50:
                                os.system('echo `date`" : [*] serial send cops error">>/var/log/5glog')
                                sys.exit(1)
                            send("at+cgdcont=1,\"ip\",\"fsmidea.gd5gmec\"\r\n")
                            recdata=recv()
                            if recdata is None:
                                continue
                            if "OK" in recdata:
                                print("send 2 next")
                                break
                            else:
                                continue
                    fd.write(recdata.decode('utf-8'))
                    fd.write('\n')	
                    while True:
                            sendcgd_count=sendcgd_count + 1
                            if sendcgd_count == 50:
                                os.system('echo `date`" : [*] serial send cgd error">>/var/log/5glog')
                                sys.exit(1)
                            send("at+gtippass=1\r\n")
                            recdata=recv()
			    if recdata is None:
                                continue
			    if "ERROR" in recdata:
				continue
                            if "OK" in recdata:
                                print("send 3 next")
                                break
                            else:
                                continue
                    fd.write(recdata.decode('utf-8'))
                    fd.write('\n')
                    while True:
                            sendds_count=sendds_count + 1
			    if sendds_count == 50:
                                print(sendds_count)
                                os.system('echo `date`" : [*] serial send re-tel error">>/var/log/5glog')
                                sys.exit(1)
                            send("at+gtrndis=1,1\r\n")
                            recdata=recv()
                            sleep(1)
                            if recdata is None:
                                continue
                            if "OK" in recdata:
                                print("send 4 next")
                                break
                            else:
                                continue
                    fd.write(recdata.decode('utf-8'))
                    fd.write('\n')
                    while True:
                            senddhcp_count=senddhcp_count + 1
                            if senddhcp_count == 50:
                                os.system('echo `date`" : [*] serial send dhcp error">>/var/log/5glog')
                                sys.exit(1)
                            send("at+gtrndis?\r\n")
                            recdata=recv()
			    sleep(1)
                            if recdata is None:
                                continue
                            if "OK" in recdata:
                                print("get ip succcess")
                                break
                            else:
                                continue
                    fd.write(recdata.decode('utf-8'))
                    fd.write('\n')
                    fd.close()
                    break
        except:
            fd.close()
            ser.close()

