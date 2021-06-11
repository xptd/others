# if __name__ == "__main__":
# 	print("hello xptd");
# 	
# 	
# print("hello","xptd")
# ------------------
# hello xptd
# 
# print(1024);
# print(1024*1024)
# ---------------------------
# 1024
# 1048576
# 
# print("100+200=",100+200);
# --------------------
# 100+200= 300
# 
# 
# str = input()
# print("the input is:",str)
# -------------------------
# xptd
# the input is: xptd

# 请按任意键继续. . .
# str = input("please input a name:")
# print("hello:",str)
# ---------------------------
# please input a name:xptd
# hello: xptd

# 请按任意键继续. . .
# 

# str = 'i \' am \"xptd\"'
# str1 = r'i \' am \"xptd\"'
# print(str, str1)

# ----------------
# i ' am "xptd" i \' am \"xptd\"
# 

# print('''123
# 	456
# 	789454545''')
# --------------------------
# 123
# 	456
# 	789454545

# print(True+True)
# 2


# a = "ABC";
# b = a;
# a.replace('A','D')
# a = "XYZ"
# print(a,b)


# --------------
# XYZ ABC

# 请按任意键继续. . .
# 
# 
# #

# print(ord("我"))
# print(chr(65))
# ------------------
# 25105
# A
# 
# print(hex(ord("我")))
# print('\u6211')
# --------------------
# 0x6211
# 我

# print("ABC",b"ABC")
# print("ABC".encode('ascii'))
# print("小跑堂的".encode("utf-8"))
# print(b'\xe5\xb0\x8f\xe8\xb7\x91\xe5\xa0\x82\xe7\x9a\x84'.decode("utf-8"))
# ---------------------------------
# ABC b'ABC'
# b'ABC'
# b'\xe5\xb0\x8f\xe8\xb7\x91\xe5\xa0\x82\xe7\x9a\x84'
# 小跑堂的
# 

# print(len("小跑堂的"))

# print(len("小跑堂的".encode('utf-8')))
# ----------------
# 4
# 12

# print("num is %d%%" % 7)
# print("name is %s age is:%d" % ("xptd",18))
# print("name is {0} age is {1}".format("xptd",18))
# ------------------------------
# num is 7%
# name is xptd age is:18
# name is xptd age is 18
# 
# 


# name = ["xptd","gao","yun","jie"];
# print("list len:%d" %(len(name)),name)
# ------------------------------------
# list len:4 ['xptd', 'gao', 'yun', 'jie']
# name = list()
# name.insert(1,"xptd")
# name.insert(2,"gyj")
# print(name)
# name.insert(2,18)
# print(name)
# ----------------------------
# ['xptd', 'gyj']
# ['xptd', 'gyj', 18]
# [Finished in 0.1s]
# 

# name = list();
# name.insert(13,"xptd");
# print("list len:",len(name),name)
# print(name[0])
# ----------------------
# list len: 1 ['xptd']
# xptd
# 
# name = list();
# name.insert(0,"xptd");
# print(name);
# name.insert(0,"gyj");
# print(name);
# name[0] ="yunjie"
# print(name)
# ------------------------
# ['xptd']
# ['gyj', 'xptd']
# ['yunjie', 'xptd']

# name = (1);
# name_1 = (1,)
# print(type(name),type(name_1))
# print(name,name_1)
# -----------------------
# <class 'int'> <class 'tuple'>
# 1 (1,)
# 

# name = ("xptd","gao",["yun","jie"])
# print(len(name),name)
# name[-1][0] = "y"
# print(len(name),name)
# --------------------------
# 3 ('xptd', 'gao', ['yun', 'jie'])
# 3 ('xptd', 'gao', ['y', 'jie'])
# 
# record =int(input("please inp a num:"))

# if record > 90:
# 	print("A");
# elif record > 80:
# 	print('B');
# elif record > 70:
# 	print('C');
# else:
# 	print('D');
# 	
# 	

# for x in ("xptd","gyj"):
# 	print(x)
# -----------------
# xptd
# gyj

# for x in range(0,10):
# 	print(x,end=" ")
# ------------------------
# 0 1 2 3 4 5 6 7 8 9 [Finished in 0.1s]
# 
# for x in list(range(10)):
# 	print(x,end="-")
# -------------------------
# 0-1-2-3-4-5-6-7-8-9-[Finished in 0.1s]


# sum = 0;
# n = 99;
# while n > 0:
# 	sum = sum + n;
# 	n -= 2;

# print(sum)
# --------------
# 2500
# 



# dic = {"name":"xptd","age":18};
# print(len(dic),dic)

# dic["name"] = "yunjie"
# print(len(dic),dic)

# if "name" in dic:
# 	print(dic["name"])
# else:
# 	print("key not  exist")

# print(dic.get("age"))
# print(dic.get("sex","no elem"))

# print(dic.pop("age"))
# for tmp in dic:
# 	print(tmp)	
# ----------------------------------
# 2 {'name': 'xptd', 'age': 18}
# 2 {'name': 'yunjie', 'age': 18}
# yunjie
# 18
# no elem
# 18
# name

# s = set([1,2,2,2,3,3,3])
# print(s)
# -----------------
# {1, 2, 3}

# s1 = set([1,2,3,4,5])
# s2 = set([2,3,4,7,9,5,1])
# s3 = s1 | s2;
# print(s3);
# s4 = s1 & s2;
# print(s4)

# s1.add("xptd")
# s2.remove(1)
# print(s1)
# print(s2)
# ---------------------
# {1, 2, 3, 4, 5, 7, 9}
# {1, 2, 3, 4, 5}
# {1, 2, 3, 4, 5, 'xptd'}
# {2, 3, 4, 5, 7, 9}
# [Finished in 0.1s]
# man = help
# man(list.append)
# --------------------
# Help on method_descriptor:

# append(self, object, /)
#     Append object to the end of the list.

# def say_hello(name):
# 	return name+" hello!"

# print(say_hello("xptd"))
# --------------------
# xptd hello!


# def hello():
# 	pass
# value = int(input())

# if value > 100:
# 	pass;


# def say_hello(name):
# 	if not isinstance(name,str):
# 		raise TypeError("bad param type")
# 	else:
# 		return(name+"hello!")
# print(say_hello("gyj"))
# print(say_hello(123))
# ------------------
# gyjhello!
# Traceback (most recent call last):
#     raise TypeError("bad param type")


# def swap_data(a,b):
# 	tmp = a;
# 	a = b;
# 	b = tmp;
# 	return a,b;

# a,b = (10,20);
# print(a,b)
# a,b = swap_data(a,b);
# print("swap data:%d,%d," % (a,b));
# --------------------------
# 10 20
# swap data:20,10,

# def power(x,n=2):
# 	sum  = 1;
# 	for i in range(0,n):
# 		sum *=x;
# 	return sum;

# print(power(2));
# print(power(2,2));

# -----------------
# 4
# 4


# def add_end(L=[]):
# 	L.append("END");
# 	return L;
# print(add_end(list(range(5))))
# print(add_end())
# print(add_end())
# print(add_end())
# ----------------------------
# [0, 1, 2, 3, 4, 'END']
# ['END']
# ['END', 'END']
# ['END', 'END', 'END']


# def test_fun(a = 10,b=20):
# 	return a,b;
# print(test_fun())

# def cal(nums):
# 	sum = 0;
# 	for x in nums:
# 		sum +=x;
# 	return sum;

# l = list(range(5));
# print(cal(l)) 

# def cal_1(*nums):
# 	sum = 0;
# 	for x in nums:
# 		sum += x;
# 	return sum;

# print(cal_1(0,1,2,3,4));
# print(cal_1(*l));
# -------------------
# 10
# 10
# 10


# def print_info(name,age,**info):
# 	#print("name:%s,age:%d,other:" % (name,age,info))
# 	print("name:",name,"age:",age,"other:",info)

# print_info(name="xptd",age=18,gender = 'M',job = "coder")

# dic = {"gender":'M',
# 	 "job":"coder"}

# print_info("xptd",18,**dic)
# -------------------------------
# name: xptd age: 18 other: {'gender': 'M', 'job': 'coder'}
# name: xptd age: 18 other: {'gender': 'M', 'job': 'coder'}

# def print_info(name,age,*,gender,job):
# 	print(name,age,gender,job)

# print_info("xptd",18,gender='M',job="coder")
# -----------------
# xptd 18 M coder


# def fun():
# 	pass;
# def fun_1(a,b):
# 	pass;
# def fun_2(a,b,c = 1):
# 	pass;
# def fun_3(a,b,c=1,*nums):
# 	pass;
# def fun_4(a,b,c=1,**kw):
# 	pass;
# def fun_5(a,b,c=1,*,gender='M',job):
# 	pass;


# lan=["lua","html"];
# lan.append('C');
# lan.insert(0,'python'.title())
# lan.append("C++");

# print(lan)

# for i in range(0,2):
# 	print(lan[i]);
# print(lan[0:2])
# print(lan[:2])
# print(lan[-2:-1])
# print(lan[-2:])
# ---------------------------
# ['Python', 'lua', 'html', 'C', 'C++']
# Python
# lua
# ['Python', 'lua']
# ['Python', 'lua']
# ['C']
# ['C', 'C++']
# [Finished in 0.1s]

# str1 = "xptd"
# print(type(str1[0:2]));
# ------------
# <class 'str'>
# num = list(range(100))
# #print(num)
# #print(num[:])
# #print(num[::])
# print(num[::10])
# --------------------------------------
# [0, 10, 20, 30, 40, 50, 60, 70, 80, 90]


# str1 = "xptd";
# for tmp in str1:
# 	print(tmp,end=" ");

# print();

# l = list(range(5));
# for tmp in l:
# 	print(tmp ,end =",")
# print()

# for i,value in enumerate(l):
# 	print("index:%d,value:%d"%(i,value));


# t = (1,2,"xptd");

# for x in t:
# 	print(x,end = " ");
# print()

# dic = {
# 	"name":"xptd",
# 	"age":18
# 	};

# for tmp in dic:
# 	print(tmp,end = " ")
# print()

# for tmp in dic.values():
# 	print(tmp,end="")
# print();

# for key,value in dic.items():
# 	print("key:{0}-value:{1}".format(key,value));
# print()


# ---------------------------------
# x p t d 
# 0,1,2,3,4,
# index:0,value:0
# index:1,value:1
# index:2,value:2
# index:3,value:3
# index:4,value:4
# 1 2 xptd 
# name age 
# xptd18
# key:name-value:xptd
# key:age-value:18

# from collections import Iterable

# print(isinstance(123,Iterable))
# print(isinstance("xptd",Iterable))
# ------------------
# False
# True

# print([x for x in range(5)])

# print([x*x for x in range(5)])

# print([x for x in range(10) if x % 2 == 0])

# print([x+n for x in "abc" for n in "ABC" ])
# -------------------------------
# [0, 1, 2, 3, 4]
# [0, 1, 4, 9, 16]
# [0, 2, 4, 6, 8]
# ['aA', 'aB', 'aC', 'bA', 'bB', 'bC', 'cA', 'cB', 'cC']


# lan = ["C","C++","Java","Python"];
# print([x.lower() for x in lan])
# -----------------------
# ['c', 'c++', 'java', 'python']

# lan = ["C","C++","Java","Python",18,20];

# print([x.lower() for x in lan if isinstance(x,str)])
# ------------------------------
# ['c', 'c++', 'java', 'python']

# l = (x for x in range(10))
# print(l);

# print(next(l));
# print(type(l));
# for x in l:
# 	print(x,end = ",");
# print(l);
# -----------------------------
# <generator object <genexpr> at 0x000001CC7AE8F430>
# 0
# <class 'generator'>
# 1,2,3,4,5,6,7,8,9,
# <generator object <genexpr> at 0x000001CC7AE8F430>

# 
# def fib(max):
# 	n,a,b = 0,0,1;
# 	while n < max:
# 		print(b);
# 		a,b = b,a+b;
# 		n += 1;
# 	return "done";
# fib(39);
# ---------------------
# [Finished in 0.1s]
#


# def fib(max):
# 	n,a,b = 0,0,1;
# 	while n < max:
# 		yield b;
# 		a,b = b,a+b;
# 		n += 1;
# 	return "done";

# f = fib(39);

# for x in f:
# 	print(x);

# def fib(max):
# 	n,a,b = 0,0,1;
# 	while  n < max:
# 		yield b;
# 		a,b = b,a+b
# 		n += 1;
# 	return "done";

# f = fib(5);
# while True:
# 	try:
# 		x = next(f);
# 		print("f:",x);
# 	except StopIteration as e:
# 		print("generator return value:",e.value)
# 		break;
# ---------------------------
# f: 1
# f: 1
# f: 2
# f: 3
# f: 5
# generator return value: done

# def trangles(max):
# 	n = 1;
# 	l = [1];
# 	while n <= max:
# 		yield l;

# 		l = [1]+[l[k]+l[k+1] for k in range (len(l)-1) ]+[1];
# 		n+=1;
# for t in trangles(10):
# 	print(t);
	

		
# from collections import Iterable
# print(isinstance(str,Iterable))
# print(isinstance("xptd",Iterable))
# print(isinstance(list,Iterable))
# print(isinstance((x for x in range(10)),Iterable))

# -----------------
# False
# True
# False
# True


# from collections import Iterable 
# from collections import Iterator 
# print(isinstance("xptd",Iterable))
# print(isinstance("xptd",Iterator))
# print(isinstance(iter("xptd"),Iterator))
# -----------------------
# True
# False
# True

# for x in range(5):
# 	pass

# it  = iter([x for x in range(5)])
# while True:
# 	try:
# 		x = next(it);
# 	except StopIteration:
# 		break;
# def add_data(x,y,f):
# 	return f(x)+f(y);
# print(add_data(-5,6,abs))
# -------------
# 11

# from collections import Iterator;

# L =[x for x in range(10)];
# print(L);
# def fun(x):
# 	return x*x;

# ret = map(fun,L);
# print(type(ret));
# print(isinstance(ret,Iterator));
# print(list(ret));
# -----------------------------
# [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
# <class 'map'>
# True
# [0, 1, 4, 9, 16, 25, 36, 49, 64, 81]

# from functools import reduce;

# def  add(x,y):
# 	return x+y;

# print(reduce(add,[1,3,5,7,9]));
# ------------------
# 25


# from functools import reduce;

# def list2int(x,y):
# 	return x*10 +y;

# print(reduce(list2int,[1,2,3,4,5]))
# -----------------------------
# 12345

# from functools import reduce;
# num_str = "12345678";

# print(type(num_str));
# print(num_str);

# def list2num(x,y):
# 	return x*10 +y;

# def char2num(x):
# 	return ord(x)-ord('0');

# num_tmp = list(map(char2num,num_str));
# print(num_tmp);
# num_int = reduce(list2num,num_tmp)
# print(type(num_int))
# print(num_int)

# -------------------------------
# <class 'str'>
# 12345678
# [1, 2, 3, 4, 5, 6, 7, 8]
# <class 'int'>
# 12345678
# [Finished in 0.1s]


# def is_odd(num):
# 	return num % 2 ==1;

# l = [x for x in range(11)];

# print(list(filter(is_odd,l)))
# ---------------------
# [1, 3, 5, 7, 9]

# def not_emprty(s):
# 	return s and s.strip();

# l = ["xpdt","","C"," ","C++"];
# print(len(l),l);
# tmp = list(filter(not_emprty,l));
# print(len(tmp),tmp);
# --------------------
# 5 ['xpdt', '', 'C', ' ', 'C++']
# 3 ['xpdt', 'C', 'C++']


# def _odd_iter():
# 	n = 1;
# 	while True:
# 		n = n+2;
# 		yield n;

# def _not_divisible(n):
# 	return lambda x: x % n > 0;

# def primes(): 
# 	yield 2;
# 	it = _odd_iter();
# 	while True:
# 		n = next(it)
# 		yield n;
# 		it = filter(_not_divisible(n),it);

# for n in primes():
# 	if n < 1000:
# 		print(n);
# 	else:
# 		break;

# l = [-10,10,1,4,7,-20];
# print(sorted(l));
# print(sorted(l,key=abs))

# --------------------------
# [-20, -10, 1, 4, 7, 10]
# [1, 4, 7, -10, 10, -20]

# l = ['a','b','D','E']
# print(sorted(l));
# print(sorted(l,key = str.lower))
# print(sorted(l,key= str.upper,reverse = True))
# ----------------------
# ['D', 'E', 'a', 'b']
# ['a', 'b', 'D', 'E']
# ['E', 'D', 'b', 'a']


# def lazy_sum(*args):
# 	def sum():
# 		s = 0;
# 		for tmp in args:
# 			s += tmp;
# 		return s;
# 	return sum;

# l = list(range(10));
# print(l);

# fun = lazy_sum(*l);

# print(fun);
# print(fun())
# --------------------------
# [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
# <function lazy_sum.<locals>.sum at 0x000002CBCA5EC1F0>
# 45
# [Finished in 0.1s]


# def count():
# 	fl= [];
# 	for i in range(1,4):
# 		def f():
# 			print("in inner function:i = %d"%(i));
# 			return i*i;
		
# 		fl.append(f);
# 	return fl;

# f1,f2,f3 = count();

# print(f1());
# print(f2());
# print(f3());

# --------------------------
# in inner function:i = 3
# 9
# in inner function:i = 3
# 9
# in inner function:i = 3
# 9


# def count():

# 	def f(j):
# 		def g():
# 			return j*j;
# 		return g;
# 	fl = [];
# 	for x in range(1,4):
# 		fl.append(f(x));

# 	return fl;

# f1,f2,f3 = count()
# print(f1())
# print(f2())
# print(f3())

# --------------------
# 1
# 4
# 9


# def f(x):
# 	return x*x;
# print(list(map(f,[1,2,3,5])));
# print(list(map(lambda x:x*x,[1,2,3,5])));
# -------------------------------------
# [1, 4, 9, 25]
# [1, 4, 9, 25]


# def add_data(x,y):
# 	return lambda :x+y;

# f = add_data(1,2);
# print(f)
# print(add_data(1,2)())
# -----------------
# <function add_data.<locals>.<lambda> at 0x00000295D060C1F0>
# 3

# def log(fun):
# 	def wrapper(*arg,**kw):
# 		print("call %s:"% fun.__name__);
# 		return fun(*arg,**kw);
# 	return wrapper;

# @log
# def now():
# 	print("2020-03-08");

# now()
# ------------------
# call now:
# 2020-03-08


# def log(text):
# 	def decorator(fun):
# 		def wrapper(*args,**kw):
# 			print("%s %s()"%(text,fun.__name__))
# 			return fun(*args,**kw)
# 		return wrapper;
# 	return decorator;
# @log("xptd test")
# def now():
# 	print("2020-03-08")

# now()
# -------------------
# xptd test now()
# 2020-03-08
# [Finished in 0.1s]

# import functools

# def print_info(fun):
# 	@functools.wraps(fun)
# 	def wrapper(*args,**kw):
# 		print("xptd test");
# 		return fun(*args,**kw);
# 	return wrapper;

# @print_info
# def test():
# 	print("test func");
# print(test.__name__);
# ----------------------

# test

  
#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# import functools 

# def log(fun):
# 	@functools.wraps(fun)
# 	def wrapper(*args,**kw):
# 		print("%s begin call"%fun.__name__);
# 		ret = fun(*args,**kw);
# 		print("%s end call"%fun.__name__);
# 		return ret;
# 	return wrapper;
# @log
# def now():
# 	print("xptd test");

# now()`
# ------------------------
# now begin call
# xptd test
# now end call

# num_str = "123456"
# print(num_str);
# print(int(num_str));
# print(int(num_str,base = 8));

# def int8(num_s,base = 8):
# 	return int(num_s,base);

# print(int8(num_str))

# import functools 

# int8_p = functools.partial(int,base = 8);
# print(int8_p(num_str))

# ----------------------------
# 123456
# 123456
# 42798
# 42798
# 42798



# import sys
# print(sys.path)
# print(type(sys.path))
# ------------------------
# <class 'list'>
# 
# 

# class Student(object):
# 	pass;

# if __name__ == "__main__":
# 	stu = Student();
# 	print(stu);
# 	stu.name = "xptd";
# 	stu_1 = Student();
# 	print(stu_1.name);
# ------------------------------------------
# AttributeError: 'Student' object has no attribute 'name'




# class Student:
# 	def __init__(self,name,score):
# 		self.name = name;
# 		self.score =score;
# 	def info(self):
# 		print("name:{0},score:{1}".format(self.name,self.score));

# if __name__ == '__main__':
# 	stu = Student(name = "xptd",score = 18);
# 	stu.info();

# ------------------
# name:xptd,score:18
# 
# 

# class Student:

# 	def __init__(self,name,score):
# 		self.__name = name;
# 		self.__score = score;
# 	def get_name(self):
# 		return self.__name;
# 	def set_name(self,name):
# 		self.__name = name;

# 	def info(self):
# 		print("%s,%s"%(self.__name,self.__score));

# if __name__ == '__main__':
# 	stu = Student("xptd",18);
# 	stu.info();
# 	#stu.__name
# 	stu.set_name("gyj");
# 	print(stu.get_name())


# -----------------------
# Student' object has no attribute '__name'
# xptd,18
# gyj



# class Animal:
# 	def run(self):
# 		print("Animal run");

# class Dog(Animal):
# 	def run(self):
# 		print("Dog run");
# class Cat(Animal):
# 	pass;

# if __name__ == "__main__":
# 	dog = Dog();
# 	cat = Cat();
# 	ani = Animal();
# 	print(dog);
# 	print(cat);
# 	print(isinstance(dog,Dog));
# 	print(isinstance(cat,Cat));
# 	print(isinstance(dog,Animal));
# 	print(isinstance(ani,Animal));
# 	print(isinstance(ani,Dog));
# 	dog.run();
# 	cat.run();
# ----------------------------
# <__main__.Dog object at 0x00000000021E0548>
# <__main__.Cat object at 0x00000000021E0588>
# True
# True
# True
# True
# False
# Dog run
# Animal run
# 
# 
# 

# import types;

# class Dog():
# 	pass;

# def fun():
# 	pass;

# b = fun;
# a = abs;
# dog = Dog()
# print(type(dog));
# print(a(-1));
# print(type(b));
# print(type(a));
# print(type(123) == type(456));
# print(type(123) == type("456"));
# print(type(123) == str);

# print(type(a) == types.BuiltinFunctionType)
# print(type(b) == types.FunctionType)
# print(type(lambda x: x*x) == types.LambdaType)
# ---------------------------
# <class '__main__.Dog'>
# 1
# <class 'function'>
# <class 'builtin_function_or_method'>
# True
# False
# False
# True
# True
# True
# 



# class Number():
# 	def __init__(self):
# 		self.x = 10;

# if __name__ == "__main__":
# 	num = Number();

# 	print(hasattr(num,'x'));
# 	print(hasattr(num,'y'));
# 	print(getattr(num,'x'));
# 	print(getattr(num,'y',"get err"));
# 	print(setattr(num,'y',20));
# 	print(setattr(num,'x',30));
# 	print(num.x)
# 	print(num.y)
# 	# print(dir(num))
# -------------------------------
# True
# False
# 10
# get err
# None
# None
# 30
# 20
# [Finished in 0.1s]

# import types;

# def set_age(self,age):
# 	self.age =age;

# class Person:
# 	pass;

# if __name__ == "__main__":
# 	p = Person();
# 	print(hasattr(p,'xptd'));
# 	print(hasattr(p,'age'));
# 	p.name = "xptd";
# 	print(p.name);
# 	p.set_age = types.MethodType(set_age,p);
# 	print(hasattr(p,'age'));
# 	p.set_age(20);
# 	print(p.age);
# --------------------------
# False
# False
# xptd
# False
# 20




# from types import *;

# def set_age(self,age):
# 	self.age = age;

# class Person:
# 	pass;

# if __name__ == "__main__":
# 	p = Person();
# 	print(hasattr(p,'age'));
# 	Person.set_age = MethodType(set_age,Person);
# 	p.set_age(18);
# 	print(hasattr(p,"age"));
# 	p1 =Person();
# 	print(p1.age);

# -----------------------
# False
# True
# 18


# class Student:
# 	__slots__ = ("name","age");

# class SubStudent(Student):
# 	__slots__ = ("other");

# if __name__ == "__main__":
# 	xptd = Student();
# 	print(hasattr(xptd,'name'));
# 	print(hasattr(xptd,'age'));
# 	xptd.name = "xptd";
# 	print(xptd.name);
# 	#xptd.score = 90;
# 	#AttributeError: 'Student' object has no attribute 'score'
# 	print(xptd.__slots__);
# 	sub_xptd = SubStudent();

# 	print(hasattr(sub_xptd,'name'));
# 	sub_xptd.name = "sub_xptd";
# 	print(sub_xptd.__slots__);
# 	#sub_xptd.score = 90;
# 	#AttributeError: 'SubStudent' object has no attribute 'score'
# ----------------------
# False
# False
# xptd
# ('name', 'age')
# False
# other
# [Finished in 0.1s]

# class Student:

# 	def get_score(self):
# 		return self.score;
# 	def set_score(self,score):
# 		if not isinstance(score,int):
# 			raise ValueError("score must be an integer")
# 		if score < 0 or score > 100:
# 			raise ValueError("score must between 0 and 100");
# 		self.score = score;

# if __name__ == "__main__":
# 	stu = Student();
# 	#print(stu.get_score());
# 	#AttributeError: 'Student' object has no attribute 'score'
# 	stu.set_score(18);
# 	print(stu.get_score())
# 	#sud.set_score('18')
# 	#NameError: name 'sud' is not defined
# 	


# class Student:
# 	@property
# 	def score(self):
# 		return self._score;

# 	@score.setter
# 	def score(self,score):
# 		if not isinstance(score,int):
# 			raise ValueError("score must be int type ");
# 		if score < 0 or score > 100:
# 			raise ValueError("score must between 0 and 100");
# 		self._score = score;

# if __name__ == "__main__":
# 	stu = Student();
# 	stu.score = 50;
# 	print(stu.score);
# 	


# class Student:
# 	def __init__(self,name):
# 		self.name = name;
# 	def __len__(self):
# 		return 100;
# 	def __str__(self):
# 		return "Student object (name %s)"% self.name;
# 	__repr__ = __str__;

# if __name__ == "__main__":
# 	stu = Student("xptd");
# 	print(len(stu));
# 	print(stu)
# 	#<__main__.Student object at 0x0000000001EA10C8>
# 	#Student object (name xptd)


# class Fib:
# 	def __init__(self):
# 		self.a,self.b = 0,1;
# 	def __iter__(self):
# 		return self;
# 	def __next__(self):
# 		self.a ,self.b = self.b ,self.a+self.b;
# 		if self.a > 10000:
# 			raise StopIteration();
# 		return self.a;

# if __name__ == "__main__":

# 	for n in Fib():
# 		print(n);
# 		


# class Fib:
# 	def __getitem__(self,n):
# 		a,b = 1,1;
# 		for x in range(n):
# 			a,b = b,a+b;
# 		return a;

# if __name__ == "__main__":
# 	f = Fib();
# 	print(f[0]);
# 	print(f[100]);
# 	

# class Fib:

# 	def __getitem__(self,n):
# 		if isinstance(n,int):
# 			a,b = 1,1;
# 			for x in  range(n):
# 				a,b = b,a+b;
# 			return a;
# 		elif isinstance(n,slice):
# 			start = n.start;
# 			stop  = n.stop;
			
# 			if start is None:
# 			 	start = 0;

# 			a,b = 1,1;
# 			L = [];
# 			for x in range(stop):
# 				if x >= start:
# 					L.append(a);
# 					a,b = b,a+b;
# 			return L;
		
# if __name__ == "__main__":
# 	f = Fib();
# 	print(f[10000000])



# class Student:
# 	def __init__(self):
# 		self.name = "xptd";
# 	def __getattr__(self,attr):
# 		if attr == "score":
# 			return 100;

# if __name__ == "__main__":
# 	stu = Student();
# 	print(stu.score)
# ---------------------------
# 100
# 


# class Student:
# 	def __init__(self,name):
# 		self.name = name;
# 	def __call__(self):
# 		print("My name is %s."%self.name);


# if __name__ == "__main__":
# 	stu = Student("xptd");
# 	stu();
# 	print(callable(stu));
# 	print(callable(Student))
# ---------------------------
# My name is xptd.
# True
# True
# 
# from enum  import Enum;

# Month  = Enum('Month',("Jan","Feb","Mar"));

# for name ,member in Month.__members__.items():
# 	print(name,"=>",member,',',member.value)
# --------------------------
# Jan => Month.Jan , 1
# Feb => Month.Feb , 2
# Mar => Month.Mar , 3
# 

# from enum import Enum,unique;
# @unique
# class WeekDay(Enum):
# 	Sun = 0;
# 	Mon = 1;
# 	Tue = 2;
# 	Wed = 3;
# 	Thu = 4;
# 	Fri = 5;

# for x, y in WeekDay.__members__.items():
# 	print(x,y,y.value)
# -----------------------------
# Sun WeekDay.Sun 0
# Mon WeekDay.Mon 1
# Tue WeekDay.Tue 2
# Wed WeekDay.Wed 3
# Thu WeekDay.Thu 4
# Fri WeekDay.Fri 5
# [Finished in 0.1s]
# 
# 
# 
# if __name__ == "__main__":
# 	file = open("write_log.c");
# 	print(file.closed);
# 	print(file.name);
# 	print(file.mode);
# 	print(file.encoding);
# -----------------------------
# False
# write_log.c
# r
# cp936



# if __name__ == "__main__":
	
# 	f = open("write_log.c","rb",True);
# 	try:	
# 		while True:
# 			ch  = f.read();
# 			if not ch:break;
# 			print(ch.decode('utf-8'),end="");
# 	finally:
# 		f.close();


# import codecs;
# f = codecs.open("write_log.c",'r','utf-8');
# while True:
# 	ch = f.read(1);
# 	if not ch:break;
# 	print(ch ,end='');
# f.close();
# 
# 
# 

# import codecs;

# file = codecs.open("test.txt","r","utf-8");
# while True:
# 	line = file.readline();
# 	if not line :break;
# 	print(line,end="");
# 	

# import codecs;

# file = codecs.open("test.txt","r","utf-8");
# for line in file.readlines():
# 	print(line,end="");
# 	
# 	
# 	

# import codecs;
# file = codecs.open("test.txt","r","utf-8",buffering = True);
# for line in file:
# 	print(line,end="");
# 	
# import sys;

# for line in sys.stdin:
# 	print(line);
# 	

# import codecs;
# import os;
# if __name__ =="__main__":

# 	f = open("1.txt","wb+");
# 	f.write("情海情天幻情身\r".encode("utf-8"));
# 	f.writelines((("情"+os.linesep).encode("utf-8"),
# 		("海"+os.linesep).encode("utf-8")));
# 	f.close()
# 	

# import os;

# if __name__ == '__main__':
# 	print("Process(%s),start...."%os.getpid());
# 	pid = os.fork();
# 	if pid == 0:
# 		print("child process(%s)and my parent is %s"%(
# 			os.getpid(),os.getppid()));
# 	else:
# 		print("I(%s) just created a child process(%s)"%
# 			(os.getpid(),pid)));
# 			

# import socket;
# if __name__ == "__main__":
# 	server = socket.socket();
# 	server.bind(("172.16.10.179",30000));
# 	server.listen();
# 	while True:
# 	 	c addr = server.accept();
# 	 	.....
# 	 	


# import re;

# re_str = r"ABC\_001";

# if __name__ == "__main__":
# 	if re.match(re_str,r"ABC_001"):
# 		print("match");
# 	else:
# 		print("not match");

# -------------------------
# match
# 

# import re;

# re_ip_str = r"^\d[0-9]{1,2}.[0-9]{1,3}.[0-9]{1,3}.[0-9]{0,2}\d$";

# if __name__ == "__main__":
# 	ip_address =input("please input a vaild IPv4 address:")

# 	ip_re =re.match(re_ip_str,ip_address);
# 	if ip_re:
# 		print("ip macth");
# 	else:
# 		print("ip not match");
# 		

# import re;
# target_str = "a b   c";

# print(target_str.split(" "))

# print(re.split(r"\s+",target_str));
# print(re.split(r"[\s\,]+",target_str));
# ---------------------------------
# ['a', 'b', '', '', 'c']
# ['a', 'b', 'c']
# ['a', 'b', 'c']
# 
# 

# import re;

# re_str= r"^(\d{3})\s*\-\s*(\d{3,8})$";
# test_str = r"021  - 123456";
# if __name__ == "__main__":
# 	re_obj = re.match(re_str,test_str);
# 	if re_obj:
# 		print("str match");
# 		print(re_obj.group(0));
# 		print(re_obj.group(1));
# 		print(re_obj.group(2));
# 	else:
# 		print("str not macth")
# --------------------------------
# str match
# 021  - 123456
# 021
# 123456
# 

# import re;
# re_str = r"^(\d+)(0*)$";
# re_str_1 = r"^(\d+?)(0*)$";

# test_str = r"10230000";
# print(re.match(re_str,test_str).groups())
# print(re.match(re_str_1,test_str).groups())
# ---------------------
# ('10230000', '')
# ('1023', '0000')
# 

# import re;
# re_str = r"^(\d{3}-(\d{3,8})$)";

# if __name__ =="__main__":
# 	re_compile = re.compile(re_str);
# 	re_obj = re_compile.match(r"010-12345");
# 	if re_obj:
# 		print("str match")
# 		print(re_obj.groups());
# 	else:
# 		print("str not ,match")
# -----------------------
# str match
# ('010-12345', '12345')
# 

# import codecs;
# import os;
# l = [str(x) for x in range(6)];
# print(l);

# with codecs.open("test.txt","wb+",) as file:
# 	for tmp in l:
# 		file.write((tmp+os.linesep).encode("utf-8"));

# from tkinter import *
# from tkinter import ttk;


# class App:
# 	def __init__(self,master):
# 		self.master = master;
# 		self.init_widgets();
# 		self.layout();
# 	def init_widgets(self):
# 		self.top_frame = Frame(master = self.master,bg = "red");
# 		self.bottom_frame = Frame(master = self.master,bg ="green");
# 		self.left_frame = Frame(master = self.master,bg = "black");
# 		self.right_frame = Frame(master = self.master,bg = "blue");
# 		self.center_frame = Frame(master = self.master,bg = "yellow");
# 	def layout(self):
# 		self.top_frame.pack(side = TOP,fill = BOTH,expand = YES);
# 		self.bottom_frame.pack(side = BOTTOM,fill = BOTH,expand = YES);
# 		self.left_frame.pack(side = LEFT,fill = BOTH,expand = YES);
# 		self.center_frame.pack(side = LEFT,fill = BOTH,expand = YES);
# 		self.right_frame.pack(side = LEFT,fill = BOTH,expand = YES);
# 		Label(master =self.top_frame,text = "上",bg = "red").pack(side = TOP,fill = BOTH,expand = YES);
# 		Label(master =self.bottom_frame,text = "下",bg = "green").pack(side = TOP,fill = BOTH,expand = YES);
# 		Label(master =self.left_frame,text = "左",bg = "cyan").pack(side = TOP,fill = BOTH,expand = YES);
# 		Label(master =self.right_frame,text = "右",bg = "blue").pack(side = TOP,fill = BOTH,expand = YES);
# 		Label(master =self.center_frame,text = "中",bg = "yellow").pack(side = TOP,fill = BOTH,expand = YES)
# if __name__ == "__main__":
# 	root = Tk();
# 	root.title("test gui");
# 	App(root);
# 	root.mainloop();
# 	


# from tkinter import *;
# from tkinter import ttk;

# class App:
# 	def __init__(self,master):
# 		self.master = master;
# 		self.init_widgets();

	

# 	def init_widgets(self):
# 		self.top_frame = Frame(master = self.master);
# 		self.bottom_frame = Frame(master = self.master);
# 		self.top_frame.pack(side = TOP,fill = BOTH,expand =YES);
# 		self.bottom_frame.pack(side  = TOP,fill = BOTH,expand = YES);
# 		self.init_top();
# 		self.init_bottom();
# 	def init_top(self):
# 		self.cal_resesult=IntVar();
# 		self.result = Label(master = self.top_frame,justify=RIGHT,anchor = E,textvariable=self.cal_resesult,bg = "red");
	
# 		self.result.pack(side = TOP,fill = BOTH,expand = YES,);
# 		self.cal_resesult.set(0);
# 	def init_bottom(self):
# 		names = ("0","1","2","3","4","5","6"
# 			,"7", "8","9","+","-","*","/",".","=");
# 		for tmp in range(len(names)):
# 			Button(master=self.bottom_frame,text=names[tmp],width = 6).grid(row = (tmp // 4),column =(tmp % 4));

		
# if __name__ == "__main__":
# 	root = Tk();
# 	root.title("grid test");
# 	App(root);
# 	root.mainloop();
# 	
# def print_info(name,age,info={},**kw):
# 	print("name:",name,"age:",age,"other:",info,kw)



# dic = {"gender":'M',
# 	 "job":"coder"}

# print_info("xptd",18,**dic)


import os;
print(os.name);
print(os.environ);
print(os.environ.get("PATH"))