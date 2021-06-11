# import socket;

# server_ip = r"172.16.40.140";
# server_port = 6666;
# if __name__ == "__main__":
# 	server_obj = socket.socket(socket.AF_INET,socket.SOCK_STREAM);
# 	server_obj.bind((server_ip,server_port));
# 	server_obj.listen();
# 	while True:
# 		socket_obj,cilent_addr = server_obj.accept();
# 		print(socket_obj);
# 		print("client ip:",cilent_addr);
# 		socket_obj.send("hello 服务端已经接收到你请求！".encode("utf-8"));
# 		socket_obj.close()


# ----------------------------------
# <socket.socket fd=224, family=AddressFamily.AF_INET, type=SocketKind.SOCK_STREAM
# , proto=0, laddr=('172.16.40.140', 6666), raddr=('172.16.40.140', 49995)>
# client ip: ('172.16.40.140', 49995)
# <socket.socket fd=136, family=AddressFamily.AF_INET, type=SocketKind.SOCK_STREAM
# , proto=0, laddr=('172.16.40.140', 6666), raddr=('172.16.40.140', 49996)>
# client ip: ('172.16.40.140', 49996)



import socket;
import threading;
server_ip = r'172.16.40.140';
server_port = 6666;

class Server:
	def __init__(self,ip,port):
		self.client_list = list();
		self.ip =ip;
		self.port = port;
		self.server_obj = socket.socket(socket.AF_INET,socket.SOCK_STREAM);

	def server_bind(self):
		self.server_obj.bind((self.ip,self.port));
	def read_from_client(self,req_socket,count):
		try:
			return req_socket.recv(count).decode("utf-8");
		except:
			self.client_list.remove(req_socket);


	def server_wroker(self,req_socket):
		try:
			while True:
				recv_text = self.read_from_client(req_socket,2048);
				print("receive text:",recv_text);
				if recv_text is None:
					break;
				for item in self.client_list:
					item.send(recv_text.encode("utf-8"));
		except e:
			print(e.strerror);
	def server_run(self):
		self.server_bind();
		self.server_obj.listen();
		while True:
			req_socket,req_addr = self.server_obj.accept();
			print("connect to server:",req_addr);
			self.client_list.append(req_socket);
			threading.Thread(target = self.server_wroker,args=(req_socket,)).start();

if __name__ == "__main__":
	server = Server(server_ip,server_port);
	server.server_run();