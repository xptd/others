import socket;
import re;
import codecs;
import os;

ip_format = r"((?:(?:25[0-5]|2[0-4]\d|[01]?\d?\d)\.){3}(?:25[0-5]|2[0-4]\d|[01]?\d?\d))";
def check_ip(ip_address):
	compile_ip = re.compile(ip_format);
	if compile_ip.match(ip_address):
		return True;
	else:
		return False;

class PortScan:
	def __init__(self,ip_address):
		self.ip_address = ip_address;

	def port_scan(self):
		self.port_list=list();
		
       
		for port in range(65535):
			soc_obj = socket.socket(socket.AF_INET,socket.SOCK_STREAM);
			result = soc_obj.connect_ex((self.ip_address,port));
			if not result:
				print("%s:%d open"%(self.ip_address,port));
				self.port_list.append(str(port));
		soc_obj.close();
        
			     
		if len(self.port_list):
			#self.log_port();
			print("record vaild port over");
		else:
			print("not port vaild")

	def log_port(self):
		with codecs.open("D:\port_log.log","wb+","utf-8") as log:
			for item in self.port_list:
				log.write(item+os.linesep);
                
			log.write("record vaild port over");


	def run(self):
		print("scan prot start!");
		self.port_scan();
		print("scan prot over!");
	

if __name__ == '__main__':
	ip = input("please input a vaild IPv4 address:");
	#print(ip);
	if check_ip(ip):
		print("address vaild");
		scanner = PortScan(ip);
		scanner.run();
	else:
		print("ip address invaild");