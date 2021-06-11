import os;

#save info to file
def save_info(file_name,tmp_dict_sorted,tmp_dict):
	index_file = file_name.split(".")[0]+"_index."+file_name.split(".")[1];
	value_file = file_name.split(".")[0]+"_value."+file_name.split(".")[1];
	if not isinstance(tmp_dict_sorted,list):
		print("context err")
		return False;
	if not isinstance(tmp_dict,dict):
		print("context err")
		return False;
			
	with open(index_file,"w+") as file:
		for index in tmp_dict_sorted:
			#file.write("%d,%d\n" % (index,tmp_dict.get(index)));
			file.write("%d\n"% index);
	with open(value_file,"w+") as file:
		for index in tmp_dict_sorted:
			file.write("%d\n" % (tmp_dict.get(index)));
	return True;

#anlyze time
def cal_time(time_info):
	
	if not isinstance (time_info,dict):
		print("info dict err");
		return False;
	for time_item,time_list in time_info.items():

		if not isinstance(time_list,list):
			print("context err")
			return False;

		tmp_dict = dict();
		sum_time = 0;
		average_time = 0;
		max_time = max(time_list);
		min_time = min(time_list);

		for item in time_list:
			if item in tmp_dict:
				tmp_dict[item] = tmp_dict.get(item)+1;
			else:
				tmp_dict[item] = 1;
			sum_time += int(item);

		average_time = sum_time // int(len(time_list));
		print("time info:%s"%(time_item))
		print("max:{0},min:{1},average:{2},len:{3}".format(max_time,min_time,average_time
			,int(len(time_list))));
		tmp_dict_sorted = sorted(tmp_dict);
		save_info(str(time_item)+".txt",tmp_dict_sorted,tmp_dict)
	
	
#extract raw time
def split_time():
	delete =list();
	copy = list();
	compare = list();
	try:
		file = open("test_log.txt","r");
		for line in file:
			if line:
				if line.startswith("delete"):
					delete.append(int(str(line.split(":")[1]).strip()));
				elif line.startswith("copy file"):
					copy.append(int(str(line.split(":")[1].strip())));
				elif line.startswith("Compare"):
					compare.append(int(str(line.split(":")[1].strip())));

		time_info={"delete":delete,
		"copy":copy,
		"compare":compare
		}

		cal_time(time_info);
	finally:
		file.close();


if __name__ == '__main__':
	print("split time start!");
	split_time();
	print("split time over!")