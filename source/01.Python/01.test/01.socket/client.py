# import socket;

# if __name__ == "__main__":
# 	client_obj = socket.socket(socket.AF_INET,socket.SOCK_STREAM);
# 	result = client_obj.connect_ex(("172.16.40.140",6666));

# 	if not result:
# 		print("--%s--"% client_obj.recv(1024).decode("utf-8"));
# 	else:
# 		print("connect failed");
# --------------------------------------------
# --hello 服务端已经接收到你请求！--
# [Finished in 0.1s]
# 


import socket;
import threading;
server_ip = r'172.16.40.140';
server_port = 6666;
class Cilent:
	def __init__(self,ip,port):
		self.server_ip = ip;
		self.server_port = port;
		self.client = socket.socket(socket.AF_INET,socket.SOCK_STREAM);
	def connect_server(self):
		self.client.connect_ex((self.server_ip,self.server_port));
	def send_msg(self,msg):
		self.client.send(msg);
	def recv_msg(self):
		while True:
			print("server msg:",self.client.recv(2048).decode("utf-8"));
	def run(self):
		self.connect_server();
		threading.Thread(target = self.recv_msg).start();
		while True:
			text = input("input msg:");
			if text is None or text == "exit":
				break;
			self.send_msg(text.encode("utf-8"));


if __name__== "__main__":
	cilent = Cilent(server_ip,server_port);
	cilent.run();