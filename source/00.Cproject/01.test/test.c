//*************************************************
//@FileName:test.c
//@Author: xiaopaotangde
//@For:
//@Created Time:Sat 28 Dec 2019 11:54:02 AM CST
//************************************************

//#include<stdio.h>

// int main(int argc, char const *argv[])
// {
// 	int num = 190;
// 	int *p = &num;
// 	printf("%d\r\n",*p);
// 	*p= 20;
// 	printf("%d\r\n",*p);
// 	return 0;
// }

// int main(int argc, char const *argv[])
// {
	
	// int num = 10;
	// int *p = &num;
	// void *pn = NULL;
	// printf("addr:%p,value:%d\n",p ,*p);
	// printf("size_of void *:%d\r\n",sizeof(void));

	//sprintf("addr:%p,value:%d\n",pn ,*pn); //error:invalid use of void expression
	// pn = p;
	// p = (int *)pn;
	// printf("addr:%p,value:%d\n",p ,*p); 
	// return 0;
// }


// int main(int argc, char const *argv[])
// {
	// int num[] = {1,2,3,4};
	// int *p = num;
	
	// printf("size_of int :%d\r\n",sizeof(int));
	
	// printf("num_addr:%p value: %d\r\n",num, *num);
	// printf("num+1_addr:%p value:%d\r\n",num+1, *(num+1));
	// printf("point_addr:%p,value:%p\r\n",&p,p);
	// printf("addr:%p,value:%d\r\n",p,*p);
	
	// printf("addr:%p,value:%d\r\n",(p+2),*(p+2));
	// p += 2;
	// printf("addr:%p,value:%d\r\n",(p-1),*(p-1));
	// return 0;
// }
// -----------------------------------------------
// size_of int :4
// num_addr:0xbfa82ed0 value: 1
// num+1_addr:0xbfa82ed4 value:2
// point_addr:0xbfa82ecc,value:0xbfa82ed0
// addr:0xbfa82ed0,value:1
// addr:0xbfa82ed8,value:3
// addr:0xbfa82ed4,value:2




// int main(int argc, const char * argv[])
// {
	
	// char num = 5;
	// void *p = &num ;
	// char *pc = &num;
	// printf("addr:%p value:%p \r\n",&pc,pc);
	// printf("addr:%p value:%p \r\n",&p,p);
	// printf("%p\r\n",(p+4));
	//printf("value: %d\r\n",*p);//error: invalid use of void expression
	// return 0;
// }
// --------------------
// addr:0xbfdd425c value:0xbfdd4257 
// addr:0xbfdd4258 value:0xbfdd4257 
// 0xbfdd425b


// int main(int argc, const char *argcv[])
// {
	
	// int nums[] = {1,10,100,1000};
	// int *p = nums+3;
	
	// printf("addr:%p\r\n",nums);
	// printf("addr:%p\r\n",&nums);
	// printf("addr:%p,value:%p\r\n",nums+3,p);
	// p--;
	// printf("addr:%p,value:%d\r\n",p,*p);
	// p -= 1;
	// printf("addr:%p,value:%d\r\n",p,*p);
	// return 0;
// }
// ------------------
// addr:0xbfc1d500
// addr:0xbfc1d500
// addr:0xbfc1d50c,value:0xbfc1d50c
// addr:0xbfc1d508,value:100
// addr:0xbfc1d504,value:10


// int main(int argc , const char* argv[])
// {
	// int nums[] = {1,100,1000,10000};
	// int *p  = nums;
	
	// printf("addr:%p----addr:%p\r\n",(p+1),(p+3));
	
	// printf("%d\r\n",((p+3)-(p+1)));
	
	// return 0;
// }
// ------------------------
// addr:0xbfcfa994----addr:0xbfcfa99c
// 2


// int main(int argc, const char* argv[])
// {
	// char* title[]={
		// "A Tale of Two Cities",
		// "Wuthering Heights",
		// "Don Quixote",
		// "Odyssey",
		// "Moby-Dick",
		// "Hamlet"
	// };
	
	// char** best_book[3];
	// char** englisg_book[4];
	
	// best_book[0] = &title[0];
	// best_book[1] = &title[3];
	// best_book[2] = &title[5];
	
	// englisg_book[0] = &title[0];
	// englisg_book[1] = &title[1];
	// englisg_book[2] = &title[5];
	// englisg_book[3] = &title[6];
	
	// printf("addr:%p,value:%s\r\n",&title[3],title[3]);
	// printf("addr:%p,value:%p,content:%s\r\n", &best_book[1],best_book[1],*best_book[1]);
	
	// title[3] = "xpdt";
	// printf("addr:%p,value:%s\r\n",&title[3],title[3]);
	// printf("addr:%p,value:%p,content:%s\r\n", &best_book[1],best_book[1],*best_book[1]);
	
	// *best_book[1] = "hello coder";
	// printf("addr:%p,value:%s\r\n",&title[3],title[3]);
	// printf("addr:%p,value:%p,content:%s\r\n", &best_book[1],best_book[1],*best_book[1]);
	
	// return 0;
// }
// ----------------------------
// addr:0xbff84094,value:Odyssey
// addr:0xbff84070,value:0xbff84094,content:Odyssey
// addr:0xbff84094,value:xpdt
// addr:0xbff84070,value:0xbff84094,content:xpdt
// addr:0xbff84094,value:hello coder
// addr:0xbff84070,value:0xbff84094,content:hello coder



// int main(int argc, const char* argv[])
// {
	// int num = 5;
	// const int cnum = 100;
	// int *p = &num;
	// const int *cp = &cnum;
	
	// printf("addr:%p,value:%p,content:%d\r\n",&p,p,*p);
	// printf("addr:%p,value:%p,content:%d\r\n",&cp,cp,*cp);
	// printf("addr_num:%p\r\n",&num);
	// printf("addr_cnum:%p\r\n",&cnum);
	
	
	//*cp = 10;error: assignment of read-only location ‘*cp’
	
	// p = &cnum;// warning: assignment discards ‘const’ qualifier from pointer target type [enabled by default]
	// cp = &num;
	
	// printf("%d\r\n",*p);
	// printf("%d\r\n",*cp);
	//*cp = 500;//error: assignment of read-only location ‘*cp’
	// *p = 10;
	
	// printf("%d\r\n",*p);
	// printf("%d\r\n",*cp);
	
	// printf("%d\r\n",num);
	// printf("%d\r\n",cnum);
	
	// return 0;
// }
// ------------------------------------
// addr:0xbfca85a8,value:0xbfca85a0,content:5
// addr:0xbfca85ac,value:0xbfca85a4,content:100
// addr_num:0xbfca85a0
// addr_cnum:0xbfca85a4
// 100
// 5
// 10
// 5
// 5
// 10

//const int num  = 6;//error: assignment of read-only location ‘*p’
// int main(int argc, char* argv[])
// {
	// const int num  = 6;
    // int *p = &num;//arning: initialization discards ‘const’ qualifier from pointer target type [enabled by default]
	// *p = 10;
	// printf("%d\r\n",num);
	// return 0;
// }
// -----
// 10


// int main(int argc, const char *argv[])
// {
	
	// int num = 6;
	// int cnum = 10;
	
	// int *const p = &num;
	// printf("addr:%p,value:%d\r\n",p,*p);
	//p = &cnum;error: assignment of read-only variable ‘p’
	
	// return 0;
// }

// int main(int argc , const char* argv[])
// {
	// int num = 10;
	// const int * const p = &num;
	//*p = 20; error: assignment of read-only location ‘*p’
	// return 0;
// }


// int main()
// {
	
	// const int limit = 500;
	// const int * const p = &limit;
	// const int * const * plimit = &p;
	// printf("%d\r\n",*p);
	// printf("%d\r\n",**plimit);
	// return 0;
// }

// --------------------------------
// xptd@ubuntu:~/Cproject/01.Test/test$ ./test.out 
// 500
// 500


// int main(int argc, const char* argv[])
// {
	// int *p = (int *)malloc(sizeof(int));
	
	// *p = 5;
	
	// printf("addr:%p ,value:%d\r\n",p,*p);
	// free(p);
	// return 0;
// }
// -------------------------------------------------
// xptd@ubuntu:~/Cproject/01.Test/test$ ./test.out 
// addr:0x9767008 ,value:5
// xptd@ubuntu:~/Cproject/01.Test/test$ ./test.out 
// addr:0x9ff1008 ,value:5
// xptd@ubuntu:~/Cproject/01.Test/test$ ./test.out 
// addr:0x8854008 ,value:5
// xptd@ubuntu:~/Cproject/01.Test/test$ ./test.out 
// addr:0x81f0008 ,value:5
// xptd@ubuntu:~/Cproject/01.Test/test$ ./test.out 
// addr:0x8fd7008 ,value:5
// xptd@ubuntu:~/Cproject/01.Test/test$ 

// int main()
// {
	// int *p = NULL;
	// *p = 0;
	// return 0;
// }

// #include<stdio.h>
// #include<string.h>

// #define NAME "coder_xptd"

// int main(int argc, const char *argv[])
// {
	// char *name = (char*)malloc(strlen(NAME)+1);
	
	// strcpy(name,NAME);
	// if(NULL == name)
	// {
		// printf("malloc erro\r\n");
		// return 1;
	// }
	
	// while(*name != '\0')
	// {
		// printf("addr:%p,value:%c\r\n",name,*name);
		// name++;
	// }
	// free(name);
	// return 0;
// }

// ------------------------------------------
// addr:0x8d80008,value:c
// addr:0x8d80009,value:o
// addr:0x8d8000a,value:d
// addr:0x8d8000b,value:e
// addr:0x8d8000c,value:r
// addr:0x8d8000d,value:_
// addr:0x8d8000e,value:x
// addr:0x8d8000f,value:p
// addr:0x8d80010,value:t
// addr:0x8d80011,value:d
// *** Error in `./test.out': free(): invalid pointer: 0x08d80012 ***
// Aborted (core dumped)


// #include <stdio.h>
// #include <stdlib.h>

// int main(int argc, const char *argv[])
// {
// 	int *p = (int *)malloc(0);
	
// 	if(NULL == p)
// 	{
// 		printf("erro\r\n");
// 	}

// 	*p = 10000;
	
// 	printf("addr:%p,value:%d\r\n",p,*p);
// 	return 0;
// }
// -------------------------
// addr:00750F78,value:10000
// 
// 


// #include <stdio.h>
// #include <stdlib.h>

// int main(int argc, const char *argv[])
// {
// 	char *name;
// 	//name = (char *)malloc(50);
// 	printf("please input a name:\r\n");
// 	scanf("%s", name);
// 	printf("addr:%p  %s\r\n",name,name);
// 	//free(name);
// 	return 0;
// }
// 
// 


/* #include <stdio.h>
#include <stdlib.h>

#define LOG "log.txt"

int main(int argc, char const *argv[])
{
	
	FILE log = fopen(LOG,"wb+");

	if(NULL == log )
	{
		printf("open log file error\r\n");
		return 1;
	}

	fprintf(log,"hello xptd\r\n"); 
	fprintf(log,"hello xptd\r\n"); 
	fprintf(log,"hello xptd\r\n"); 
	fclose(log);


	return 0;
} */


// #include <stdio.h>

// int main(int argc, char const *argv[])
// {
// 	perror("test");
// 	printf("test perror\n");
// 	return 0;
// }
// -----------------
// test: No error
// test perror
#include <stdio.h>
#include <stdlib.h>
#define OK 0
#define ERROR 1
// int main(int argc, const char * argv)
// {
	
// 	int *p = calloc(4,sizeof(int));
// 	int test_num[4] = {11,55,66,77};
// 	int i = 0;
// 	if(NULL == p)
// 	{
// 		perror("calloc error\r\n");
// 		return 1;
// 	}		
// 	memcpy(p,test_num,sizeof(test_num));
	
// 	for(i = 0; i < sizeof(test_num)/sizeof(test_num[0]) ; i++)
// 	{
// 		printf("addr:%p value:%d\n", p,*p);
// 		p++;
// 	}
// 	return 0;
// }
// ----------------------
// addr:00AA0FF8 value:11
// addr:00AA0FFC value:55
// addr:00AA1000 value:66
// addr:00AA1004 value:77

// int main(int argc, char const *argv[])
// {
// 	int *p = calloc(0,sizeof(int));
// 	if(NULL == p)
// 	{
// 		perror("calloc error\r\n");
// 	}
// 	printf("addr:%p, value:%d\n", p,*p);
// 	return 0;
// }
// -----------------------
// addr:008F0F78, value:9375488
// 

// int main(int argc, char const *argv[])
// {
// 	int *p = malloc(4*sizeof(int));
// 	int i = 0;
// 	if(NULL == p)
// 	{
// 		perror("malloc error\n");
// 		return 1;
// 	}
// 	memset(p,0,5*sizeof(int));
// 	for(i = 0; i < 5; i++)
// 	{
// 		printf("addr:%p value:%d\n", p,*p);
// 		p++;
// 	}
// 	free(p);
// 	return 0;
// }
// ----------------
// addr:00960FF8 value:0
// addr:00960FFC value:0
// addr:00961000 value:0
// addr:00961004 value:0
// addr:00961008 value:0
// 
// 

// int main(int argc, char const *argv[])
// {
// 	char *str1 = NULL;
// 	char *str2 = NULL;

// 	if(NULL == (str1 = malloc(16)))
// 	{
// 		perror("malloc error");
// 		return 1;
// 	}
// 	strcpy(str1,"123456789AB");
// 	printf("addr:%p value:%s\n", str1,str1);
// 	str2 = realloc(str1,8);
// 	printf("addr:%p value:%s\n", str2,str2);
// 	free(str2);

// 	return 0;
// }
// ----------------------------
// addr:00A30FF8 value:123456789AB
// addr:00A30FF8 value:123456789AB

// int main(int argc, char const *argv[])
// {
// 	int time = 0;
// 	printf("%d\n",(time ? :100));

// 	time = 50;
// 	printf("%d\n",(time ? :100));
// 	return 0;
// }
// --------------
// 100
// 50
// 
// 
// 
// int main(int argc, char const *argv[])
// {
// 	long test = ((long)(~0UL>>1));
// 	printf("%ld\n",test);
// 	return 0;
// }
// 
// 


// int main(int argc, const char *argv[])
// {
// 	char *str1 = malloc(16);
// 	char *str2 = NULL;
// 	char *str3 = NULL;
// 	if(NULL == str1)
// 	{
// 		perror("malloc error\r\n");
// 		return ERROR;
// 	}
// 	strcpy(str1,"0123456789AB");
// 	printf("addr:%p value:%s\n", str1,str1);
// 	str2 = realloc(str1,64);
// 	printf("addr:%p value:%s\n", str2,str2);
// 	str3 = realloc(str2,2048);
// 	printf("addr:%p value:%s\n", str3,str3);
// 	free(str3);
// 	return OK;
// }
// -----------------------------------
// addr:006B0FF8 value:0123456789AB
// addr:006B0FF8 value:0123456789AB
// addr:006B3588 value:0123456789AB
// 
// 

// int main(int argc, char const *argv[])
// {
// 	int a = 10;
// 	int nums[a];
// 	int i = 0;

// 	for (i = 0;i < a; i++)
// 	{
// 		nums[i] = i;
// 		printf("%d\n",nums[i]);
// 	}
// 	return 0;
// }

// -----------------------
// 0
// 1
// 2
// 3
// 4
// 5
// 6
// 7
// 8
// 9
// 
// 

// void fun(int len)
// {
// 	int i = 0;
// 	int nums[len];
	
// 	for(i =0; i < len;i++)
// 	{
// 		nums[i] = i;
// 		printf("%d\n",nums);
// 		//nums++; 不能这样使用，数组名是一个常量不是变量
// 	}

// }
// int main(int argc, char const *argv[])
// {
// 	int len;
// 	printf("please input a len :\n");
// 	scanf("%d",&len);
// 	fun(len);
// 	return 0;
// }

// int main(int argc, char const *argv[])
// {
// 	int *p  = NULL;
// 	free(p);
// 	return 0;
// }
// 
// int main(int argc, char const *argv[])
// {
// 	int num = 10;
// 	int *p = &num;
// 	printf("addr:%p value:%d\n",p,*p );
// 	free(p);
// 	num = 20;
// 	printf("addr:%p value:%d\n",&num,num );
// 	*p = 30;
// 	printf("addr:%p value:%d\n",p,*p );

// 	return 0;
// }
// ---------------------------------
// addr:0028FF44 value:10
// addr:0028FF44 value:20
// addr:0028FF44 value:30
// 
// 

// int main(int argc, char const *argv[])
// {
// 	char *str = malloc(16);
// 	if(NULL == str)
// 	{
// 		perror("malloc Error\r\n");
// 		return ERROR;
// 	}
// 	strcpy(str,"123456789AB");
// 	printf("addr:%p value:%s\r\n" ,str ,str);
// 	free(str);
// 	strcpy(str,"abcd");
// 	printf("addr:%p value:%s\r\n" ,str,str);
// 	return 0;
// }
// ----------------------------------
// addr:006E0FF8 value:123456789AB
// addr:006E0FF8 value:abcd
// 

// int main(int argc, char const *argv[])
// {
// 	char * str = malloc(16);
// 	if(NULL == str)
// 	{
// 		perror("malloc error\r\n");
// 		return ERROR;
// 	}
// 	strcpy(str,"coder xptd");
// 	printf("addr:%p value:%s\n" ,str ,str);

// 	free(str);
// 	free(str);
// 	printf("addr:%p value:%s\n" ,str ,str);
// 	return 0;
// }
// 

// int main(int argc, char const *argv[])
// {
// 	int num = 10;
// 	int *p1 = &num;
// 	int *p2 = p1;
// 	printf("addr:%p value:%d\n", &num, num);
// 	printf("addr:%p value:%d\n", p1, *p1);
// 	printf("addr:%p value:%d\n", p2, *p2);
// 	free(p2);
	
// 	*p1 = 20;
// 	printf("addr:%p value:%d\n", &num, num);
// 	printf("addr:%p value:%d\n", p1, *p1);
// 	printf("addr:%p value:%d\n", p2, *p2);
// 	free(p1);
// 	num = 30;
// 	printf("addr:%p value:%d\n", &num, num);
// 	printf("addr:%p value:%d\n", p1, *p1);
// 	printf("addr:%p value:%d\n", p2, *p2);
// 	return 0;
// }
// ---------------------
// addr:0028FF44 value:10
// addr:0028FF44 value:10
// addr:0028FF44 value:10
// addr:0028FF44 value:20
// addr:0028FF44 value:20
// addr:0028FF44 value:20
// addr:0028FF44 value:30
// addr:0028FF44 value:30
// addr:0028FF44 value:30
// 
// int main(int argc, char const *argv[])
// {
// 	char *str = malloc(16);
// 	char *str1 = NULL;
	
// 	if(NULL == str)
// 	{
// 		perror("malloc error");
// 		return ERROR;
// 	}
// 	strcpy(str,"hello xptd");
// 	str1 = str;
// 	printf("addr:%p value:%s\n",str,str);
// 	printf("addr:%p value:%s\n",str1,str1);
// 	free(str1);
// 	strcpy(str,"gyj");
// 	printf("addr:%p value:%s\n",str,str);
// 	free(str1);
// 	return 0;
// }
// ------------------------------------
// addr:00470FF8 value:hello xptd
// addr:00470FF8 value:hello xptd
// addr:00470FF8 value:gyj 
// 
// 
// int main(int argc, char const *argv[])
// {
// 	int *p = NULL;
// 	{
// 		int temp = 10;
// 		p = &temp;
// 		printf("addr:%p, value:%d\n", &temp, temp);
// 		printf("addr:%p value:%d\n",p,*p );
// 	}

// 	printf("addr:%p value:%d\n" ,p ,*p);
// 	*p = 20;
// 	printf("addr:%p value:%d\n" ,p ,*p);
	
// 	return 0;
// }
// -----------------------------
// addr:0028FF40, value:10
// addr:0028FF40 value:10
// addr:0028FF40 value:10
// addr:0028FF40 value:20
// 
// 

// float average(int *arr, int size)
// {
// 	float sum = 0.0;
// 	int i = 0;

// 	printf("addr:%p value:%p\r\n",&arr,arr);
// 	printf("addr:%p value:%d\r\n",&size,size);
// 	printf("addr:%p value:%d\r\n",&sum,sum);

// 	for( i = 0; i < size;i++,arr++)
// 	{
// 		sum += *arr;
// 	}
// 	return ((sum*1.0) / size);
// }

// int main(int argc, char const *argv[])
// {
// 	int nums[5] = {1,2,3,4,5};
// 	printf("%p\n", nums);
// 	average(nums,sizeof(nums)/sizeof(nums[0]));
// 	return 0;
// }

// void swap_data_p(int *a, int *b)
// {
// 	int tmp =0;
// 	tmp = *a;
// 	*a = *b;
// 	*b = tmp;
// }

// void swap_data(int a, int b)
// {
// 	int tmp =0;
// 	tmp = a;
// 	a = b;
// 	b = tmp;
// }
// int main(int argc, char const *argv[])
// {
// 	int a = 10;
// 	int b = 20;

// 	printf("a:%d,b:%d\n", a ,b);
// 	swap_data(a,b);
// 	printf("a:%d,b:%d\n", a ,b);

// 	swap_data_p(&a, &b);

// 	printf("a:%d,b:%d\n", a ,b);

// 	return 0;
// }

// -----------------------
// a:10,b:20
// a:10,b:20
// a:20,b:10
// 


// void test(int *p)
// {
// 	*p = 20;
// }
// int main(int argc, char const *argv[])
// {
// 	const int a = 10;
// 	int *p = &a; 
// 	test(p);
// 	printf("%d\n", a);
// 	return 0;
// }
// -----------------------
// 20
// 
// 

// int main(int argc, char const *argv[])
// {
// 	int *0 = (int)20;
// 	return 0;
// }
// 


// int *creat_array(int size)
// {
// 	int *addr = malloc(size*sizeof(int));
// 	int index = 0;
// 	if(NULL == addr)
// 	{
// 		perror("malloc error\r\n");	
// 		return NULL;
// 	}
// 	for(index = 0; index < size; index++)
// 	{
// 		//*addr = index;
// 		//addr++;
// 		addr[index] = index;
// 	}
// 	return addr;
// }

// int main(int argc, char const *argv[])
// {
// 	int i = 0;
// 	int *array = creat_array(10);
	
// 	if(NULL == array)
// 	{
// 		perror("creat_array error\r\n");
// 		return ERROR;
// 	}

// 	for (i = 0; i < 10; i++)
// 	{
// 		printf("%d\n", array[i]);
// 	}
// 	free(array);
// 	return 0;
// }
// -----------------------------
// 0
// 1
// 2
// 3
// 4
// 5
// 6
// 7
// 8
// 9




// int *creat_array(int size)
// {
// 	int arr[size];
// 	int index = 0;
	
// 	for(index = 0; index < size; index++)
// 	{
// 		arr[index] = index;
// 	}
// 	return arr;
// }

// int main(int argc, char const *argv[])
// {
// 	int i = 0;
// 	int *array = creat_array(10);
	
// 	for (i = 0; i < 10; i++)
// 	{
// 		printf("%d\n", array[i]);
// 	}
	
// 	return 0;
// }
// ---------------------
// 0
// 1985455170
// 1986069696
// 2686680
// 1985475068
// 17
// 2686744
// 1985529427
// 1
// 1986079008
// 
// 

// char* fun()
// {
// 	char str[] = "hello";
// 	return str;
// }

// char* fun1()
// {
// 	char *str = "hello";
// 	return str;
// }

// int main(int argc, char const *argv[])
// {
	// char *pstr =fun();
	// char *pstr1 =fun1();
	// puts(pstr); 
	// puts(pstr1); 
	// return 0;
// }


// int *creat_array()
// {
// 	static int arr[10];

// 	int index = 0;
	
// 	for(index = 0; index < 10; index++)
// 	{
// 		arr[index] = index;
// 	}
// 	return arr;
// }

// int main(int argc, char const *argv[])
// {
// 	int i = 0;
// 	int *array = creat_array();
	
// 	for (i = 0; i < 10; i++)
// 	{
// 		printf("%d\n", array[i]);
// 	}
	
// 	return 0;
// }
// ---------------------
// 0
// 1
// 2
// 3
// 4
// 5
// 6
// 7
// 8
// 9
// 
// 
// char* fun()
// {
// 	static char str[] = "hello";
// 	return str;
// }

// int main(int argc, char const *argv[])
// {
// 	char *pstr =fun();
	
// 	puts(pstr); 
	 
// 	return 0;
// }
// 
// char *func(void)
// {
//     char s[] = "hello world";
//     return s;
// }

// int main()
// {
//     char str[50];
//     char *p = str;
//     char *s = func();
//     while(*p++=*s++); 
    
//     printf("%s\n", str);
// }
// 
// 

// int creat_array(int **arr, int size, int value)
// {

// 	int i = 0;
// 	*arr = (int *) malloc(size *sizeof(int));

// 	if(NULL == *arr)
// 	{
// 		perror("malloc error \r\n");
// 		return ERROR;
// 	}
	
// 	for(i = 0; i < size;i++)
// 	{
// 		*(*arr+i) = value;
// 	}

// 	return OK;
// }

// int main(int argc, char const *argv[])
// {
// 	int *array = NULL; 
	
// 	int i = 0;
// 	if(!(creat_array(&array,10,10)))
// 	{
// 		for(i = 0; i < 10;i++)
// 			printf("%d\n", array[i]);
// 		free(array);
// 		return OK;
// 	}

// 	return ERROR;
// }
// -------------------------
// 10
// 10
// 10
// 10
// 10
// 10
// 10
// 10
// 10
// 10
// 

// int creat_array(int *arr, int size, int value)
// {
// 	int i = 0;
// 	arr = (int *) malloc(size * sizeof(int));

// 	if(NULL == arr)
// 	{
// 		perror("malloc error \r\n");
// 		return ERROR;
// 	}

// 	for(i = 0; i < size;i++)
// 	{
// 		arr[i] = value;

// 		printf("addr:%p,value:%d\n", &arr[i],arr[i]);
// 	}

// 	return OK;
// }

// int main(int argc, char const *argv[])
// {
// 	int *array = NULL; 
// 	int i = 0;

// 	if(!(creat_array(&array,10,10)))
// 	{
	
// 		printf("%p\n", array);
// 		free(array);
// 		return OK;
// 	}

// 	return ERROR;
// }
// -----------------------------
// addr:00590FF8,value:10
// addr:00590FFC,value:10
// addr:00591000,value:10
// addr:00591004,value:10
// addr:00591008,value:10
// addr:0059100C,value:10
// addr:00591010,value:10
// addr:00591014,value:10
// addr:00591018,value:10
// addr:0059101C,value:10
// 00000000


// #define safeFree(p) safa_free((void**)&(p))
// void safa_free(void **pp)
// {
// 	if(pp != NULL && *pp != NULL )
// 	{
// 		printf("safa_free:addr:%p  value:%s",pp,*pp);
// 		free(*pp);
// 		*pp = NULL;
// 		return;
// 	}
// 	printf("safa_free param error\r\n");
// 	return;

// }
// int main(int argc, char const *argv[])
// {
// 	char *p = malloc(50*sizeof(char));
// 	if(NULL == p)
// 	{
// 		printf("malloc error\r\n");
// 		return ERROR;
// 	}
// 	strcpy(p,"safa_free test\r\n");
// 	printf("before free:addr:%p  value:%s\r\n",&p,p);
// 	safeFree(p);
// 	printf("after free:addr:%p  value:%s\r\n",&p,p);
	
// 	return 0;
// }
// ------------------------------------------------
// before free:addr:0028FF44  value:safa_free test
// safa_free:addr:0028FF44  value:safa_free test
// after free:addr:0028FF44  value:(null)


// int fun(int num)
// {
// 	return num*num;
// }
// int (*fptr)(int) = fun;

// int main(int argc, char const *argv[])
// {
// 	int num = 5;	
// 	printf(" %d result: %d\n",num,fptr(num));
// 	return 0;
// }
// ---------------------
//  5 result: 25
//  
//  

// int main(int argc, char const *argv[])
// {
// 	int buf[100]={0};

// 	printf("%p\n", buf);
// 	printf("%p\n", &buf[0]);
// 	printf("%p\n", &buf);
// 	printf("%d\n", buf[0]);

// 	printf("%d\n", sizeof(buf));
// 	printf("%d\n", sizeof(buf[0]));

// 	printf("%p\n", buf+1);
// 	printf("%p\n", &buf[0]+1);
// 	printf("%p\n", &buf+1);
	
// 	return 0;
// }
// -------------------------------------
// 0028FDB0
// 0028FDB0
// 0028FDB0
// 0
// 400
// 4
// 0028FDB4
// 0028FDB4
// 0028FF40
// 
// 
// typedef int (*fptr)(int, int);

// int add(int num1, int num2)
// {
// 	return num1 + num2;
// }
// int sub(int num1, int num2)
// {
// 	return num1 - num2;
// } 

// int compute(fptr p, int num1 ,int num2)
// {
// 	p(num1, num2);
// }
// int main(int argc, char const *argv[])
// {
// 	/* code */
// 	fptr padd = add;
// 	fptr psub = sub;

// 	printf("%d\n", compute(padd,10,20));
// 	printf("%d\n", compute(psub,20,10));
// 	return 0;
// }
// ------------------------
// 30
// 10
// 


// typedef int (*fptr)(int,int);

// int add(int num1, int num2)
// {
// 	return num1+num2;
// }
// int sub(int num1, int num2)
// {
// 	return num1 - num2;
// }
// fptr select(int value)
// {
// 	switch (value)
// 	{
// 		case '+':return add;
// 		break;
// 		case '-':return sub;
// 		break;
// 		default:return NULL;
// 	}
	
// }
// int compute(char selector, int num1, int num2)
// {
// 	fptr p=select(selector);
// 	if(NULL == p)
// 	{
// 		printf("select error\n");
// 		return;
// 	}
// 	return p(num1,num2);
// }
// int main(int argc, char const *argv[])
// {
// 	printf("%d\n",compute('+',10,20));
// 	printf("%d\n",compute('-',10,20));
// 	return 0;
// }
// ----------------
// 30
// -10
// 
// 

// #define MUX 1

// typedef int (*fptr)(int,int);

// int add(int num1, int num2)
// {
// 	return num1+num2;
// }

// int sub(int num1, int num2)
// {
// 	return num1 - num2;
// }

// int squar(int num1,int num2)
// {
// 	return num1 *num2;
// }
// fptr ops[5]={
// add,
// sub,
// #if MUX
// squar,
// #endif

// };

// int main(int argc, const char * argv[])
// {
// 	int i = 0;
// 	for (i = 0; i < 5; ++i)
// 	{
// 		if(NULL !=ops[i])
// 		{
// 			printf("%d\n", ops[i](10,20));
// 		}
		
// 	}
// 	return 0;
// }


// -------------------------------
// 30
// -10
// 200
// 
// int (*fptr)[5](int, int) = {NULL};



// typedef int (*fptr)(int,int);

// int add(int num1, int num2)
// {
// 	return num1 + num2;
// }

// int sub(int num1, int num2)
// {
// 	return num1 -num2;
// }

// int main(int argc,const char* argv[])
// {
// 	fptr ops[2] = {add,sub};
// 	int i = 0;

// 	if(ops[0] == add)
// 		printf("point to add function\r\n");
// 	else
// 		printf("error\n");
// 	return 0;
// }

// ------------------------------
// point to add function
// 
// 
// 
// int main(int argc, char const *argv[])
// {
// 	int nums[]={1,11,21,111,555,};
// 	int i = 0;
// 	int *p = nums;
// 	for(i = 0;i < sizeof(nums)/sizeof(nums[0]);i++)
// 	{
// 		printf("addr:%##p,value:%d\n",(p+i), *(p+i));
// 		printf("addr:%##p,value:%d\n",&nums[i], nums[i]);
// 	}
// 	return 0;
// }

// ----------------------------
// addr:0X0028FF20,value:1
// addr:0X0028FF20,value:1
// addr:0X0028FF24,value:11
// addr:0X0028FF24,value:11
// addr:0X0028FF28,value:21
// addr:0X0028FF28,value:21
// addr:0X0028FF2C,value:111
// addr:0X0028FF2C,value:111
// addr:0X0028FF30,value:555
// addr:0X0028FF30,value:555
// 


// int creat_array(int **p, int size)
// {
// 	int index = 0;

// 	if(p != NULL)
// 	{
// 		*p = malloc(size * sizeof(int));
// 		if(NULL != *p)
// 		{
// 			for(index = 0; index < size;index++)
// 			{
// 				*(*p+index)= index;
// 				printf("addr:%##p value:%d\n",*p+index,*(*p+index));
// 			}
// 			return OK;
// 		}
// 		return ERROR;	
// 	}
// 	return ERROR;

// }

// int main(int argc, char const *argv[])
// {
// 	int *p = NULL;
// 	int i = 0;
// 	if(!(creat_array(&p,10)))
// 	{
// 		printf("\r\n in main function \r\n");
// 		for(i = 0; i < 10;i++)
// 		{
// 			printf("addr:%##p value:%d\n",(p+i),*(p+i));
// 		}
// 		return OK;
// 	}
// 	return ERROR;
// }

// ----------------------------------------
// addr:0X00380FF8 value:0
// addr:0X00380FFC value:1
// addr:0X00381000 value:2
// addr:0X00381004 value:3
// addr:0X00381008 value:4
// addr:0X0038100C value:5
// addr:0X00381010 value:6
// addr:0X00381014 value:7
// addr:0X00381018 value:8
// addr:0X0038101C value:9
//  in main function 
// addr:0X00380FF8 value:0
// addr:0X00380FFC value:1
// addr:0X00381000 value:2
// addr:0X00381004 value:3
// addr:0X00381008 value:4
// addr:0X0038100C value:5
// addr:0X00381010 value:6
// addr:0X00381014 value:7
// addr:0X00381018 value:8
// addr:0X0038101C value:9
// 
// 

// /*input buffer increment step count*/
// #define INCREMENT 10 

// char *get_line(void)
// {

// 	char *input_buf = malloc(INCREMENT);
// 	/*current str length*/
// 	unsigned int len =0; 
// 	/*current inpurt buffer max length*/
// 	unsigned int max_buf_len = INCREMENT;
// 	char *cur_pos = input_buf;
// 	char c ='\n';
	
// 	if(NULL == input_buf)
// 		return NULL;

// 	while(1)
// 	{
// 		c = fgetc(stdin);
		
// 		if('\n' == c)
// 			break;
// 		/*++len reserve the end of line '\0' */

// 		if(++len < max_buf_len)
// 		{
// 			char *new_buf = realloc(input_buf,max_buf_len += INCREMENT);
			
// 			if(NULL == new_buf)
// 			{
// 				free(input_buf);
// 				return NULL;
// 			}
			
// 			cur_pos = new_buf+(cur_pos-input_buf);
// 			input_buf = new_buf;
// 		}
// 		*cur_pos++ = c ;
// 	}
// 	*cur_pos = '\0';
// 	return input_buf;
// }


// int main(int argc, char const *argv[])
// {
	
// 	char* p = NULL;
	
// 	if(NULL != (p = get_line()))
// 	{
// 		printf("%s\n", p);
// 		free(p);
// 		return OK;
// 	}

// 	return ERROR;
// }
// 


// int main(int argc, char const *argv[])
// {
// 	char nums[6] = {10,20,30,40,50,60};
// 	char *p = nums;
// 	int i = 0;

// 	for(i = 0; i < sizeof(nums)/sizeof(nums[0]);i++)
// 	{
// 		*p++ = i;
// 		printf("addr:%p value:%d\n", &nums[i],nums[i]);
// 	}
// 	return OK;

// }
// -------------------------------
// addr:0028FF30 value:0
// addr:0028FF31 value:1
// addr:0028FF32 value:2
// addr:0028FF33 value:3
// addr:0028FF34 value:4
// addr:0028FF35 value:5


// char *tirm(char* str)
// {
// 	char *old_str = str;
// 	char *new_str = str;

// 	while(*old_str == ' ')
// 		old_str++;

// 	while(*old_str)
// 		*new_str++ = *old_str++;
	
// 	*new_str = '\0';
// 	return (char *)realloc(str,strlen(str)+1);
// }

// int main(int argc, char const *argv[])
// {
// 	char *str =malloc(strlen("  xptd")+1);

// 	if(NULL == str)
// 	{
// 		fprintf(stderr, "%s\n","malloc error\r\n");
// 		return ERROR;
// 	}

// 	strcpy(str,"  xptd");
// 	printf("before tirm:%s\n", str);
// 	printf("after  tirm:%s\n", tirm(str));
// 	return OK;
// }
// -----------------------------------
// before tirm:  xptd
// after  tirm:xptd
// 
// 

// char *trim(char *ptr)
// {
// 	char *old_str = ptr;
// 	char *new_str = ptr;
	
// 	if(NULL == ptr)
// 		return NULL;

// 	while(*old_str == ' ')
// 		old_str++;
	
// 	while(*old_str)
// 		*new_str++ = *old_str++;
	


	
// 	while(*new_str == ' ')
// 		new_str--;

// 	*(++new_str) = '\0';
// 	return (char *)realloc(ptr,strlen(ptr)+1); 

// }




// #define STR "    hello coder xptd    "
// int main(int argc, char const *argv[])
// {
// 	char *p = malloc(strlen(STR)+1);
// 	char *modify_ptr = NULL;
	
// 	if(NULL == p)
// 	{
// 		fprintf(stderr, "%s\n", "malloc error");
// 	}
// 	strcpy(p,STR);
// 	printf("befor trim:%s\tled:%d\n", p,strlen(STR)+1);
// 	if(NULL != (modify_ptr = trim(p)))
// 	{
// 		p = NULL;
// 		printf("after tirm:%s\tlen:%d\n", modify_ptr ,strlen(modify_ptr)+1);
// 		free(modify_ptr);
// 		return OK;
// 	}
// 	free(p);
// 	p = NULL;
// 	return ERROR;
// }
// --------------------------------------
// befor trim:    hello coder xptd    	led:25
// after tirm:hello coder xptd	len:17
// 
// 
// 

// #define STEP_LEN 16

// char* get_line()
// {
// 	char *str = calloc(STEP_LEN,1);
// 	char c = '\0';
// 	unsigned int buf_len = STEP_LEN;
// 	unsigned int len = 0;
// 	char *cur_pos = str;

// 	if(NULL == str)
// 	{
// 		fprintf(stderr, "%s\n", "calloc error");
// 		return NULL;
// 	}
	
// 	while(1)
// 	{
// 		c = fgetc(stdin);
// 		if(c == '\n')
// 			break;
// 		if(++len > buf_len)
// 		{
// 			char *tmp_ptr = realloc(str,buf_len += STEP_LEN);
			
// 			if(NULL == tmp_ptr)
// 			{
// 				free(str);
// 				return NULL;
// 			}
			
// 			cur_pos =tmp_ptr+(cur_pos - str);
// 			str = tmp_ptr;
			
// 		}
// 		*cur_pos++ = c;
// 	}
// 	cur_pos = '\0';
// 	return str;
// }

// char *str_trim(char *str)
// {
// 	char *old_str = str;
// 	char *new_str = str;

// 	if(NULL == str)
// 		return NULL;
	
// 	while(*old_str == ' ')
// 		old_str++;
	
// 	while(*old_str)
// 		*new_str++ = *old_str++;

// 	new_str--;
// 	while(*new_str == ' ')
// 		new_str--;
	
// 	*(++new_str) = '\0';
	
// 	return (char *)realloc(str,strlen(str)+1);
// }

// int main(int argc, char const *argv[])
// {
// 	char* str = NULL;
// 	char* modify_str = NULL;
	
// 	if(NULL != (str = get_line()))
// 	{
// 		printf("before trim:%s----len:%d\r\n",str,strlen(str)+1);
// 		if(NULL != (modify_str = str_trim(str)))
// 		{
// 			printf("after tirm:%s----len:%d\r\n",modify_str,strlen(modify_str)+1);
// 			free(modify_str);
// 			return OK;
			
// 		}

// 	}
// 	return ERROR;
// }




// void printf_array(int array[],int size)
// {
// 	int index = 0;
// 	for(index = 0; index < size;index++)
// 	{
// 		printf("addr:%p value:%d\n",&array[index],array[index]);
// 	}

// }
// int main(int argc, char const *argv[])
// {
// 	int nums[5] = {11,22,33,44,55,};
// 	printf_array(nums,sizeof(nums)/sizeof(nums[0]));
// 	return 0;
// }

// --------------------
// addr:0028FF20 value:11
// addr:0028FF24 value:22
// addr:0028FF28 value:33
// addr:0028FF2C value:44
// addr:0028FF30 value:55
// 
// 



// void print_array(int *addr, int size)
// {
// 	int i = 0;
// 	if(NULL == addr)
// 		return;
// 	for(i = 0; i < size;i++,addr++)
// 	{
// 		printf("addr:%p,value:%d\n",addr,*addr);
// 	}
// }
// int main(int argc, char const *argv[])
// {
// 	int nums[] ={123,456,789,741,258,};
// 	print_array(nums,sizeof(nums)/sizeof(nums[0]));
// 	return 0;
// }
// ------------------------------
// addr:0028FF20,value:123
// addr:0028FF24,value:456
// addr:0028FF28,value:789
// addr:0028FF2C,value:741
// addr:0028FF30,value:258
// 

// void print_array(int addr[5])
// {
// 	int i = 0;
// 	if(NULL == addr)
// 		return;
// 	for(i = 0; i < 5;i++)
// 	{
// 		printf("addr:%p,value:%d\n",&addr[i],addr[i]);
// 		addr[i] = i;
// 	}
// }
// int main(int argc, char const *argv[])
// {
// 	int nums[] ={123,456,789,741,258,};
// 	int i = 0;

// 	for(i = 0; i< 5;i++)
// 	{
// 		printf("addr:%p,value:%d\n",&nums[i],nums[i]);
// 	}

// 	print_array(nums);

// 	for(i = 0; i< 5;i++)
// 	{
// 		printf("addr:%p,value:%d\n",&nums[i],nums[i]);
// 	}
// 	return 0;
// }
// ---------------------------------
// addr:0028FF20,value:123
// addr:0028FF24,value:456
// addr:0028FF28,value:789
// addr:0028FF2C,value:741
// addr:0028FF30,value:258

// addr:0028FF20,value:123
// addr:0028FF24,value:456
// addr:0028FF28,value:789
// addr:0028FF2C,value:741
// addr:0028FF30,value:258

// addr:0028FF20,value:0
// addr:0028FF24,value:1
// addr:0028FF28,value:2
// addr:0028FF2C,value:3
// addr:0028FF30,value:4
// 
// 
// 



// int main(int argc, char const *argv[])
// {
// 	int *array[4];
// 	int i = 0;
	
// 	for(i = 0; i < sizeof(array)/sizeof(array[0]); i++)
// 	{
// 		array[i] = calloc(sizeof(int),1);
// 		if(array[i] == NULL)
// 			return ERROR;
// 		*array[i] = i;
// 		printf("addr:%p,value:%d\n",*(array+i),**(array+i));
// 	}
// 	return 0;
// }

// ------------------------
// addr:00A50F78,value:0
// addr:00A50FF8,value:1
// addr:00A51008,value:2
// addr:00A51018,value:3
// 
// 


// int main(int argc, char const *argv[])
// {
// 	int matrix[2][5]={
// 		{1,2,3,4,5},
// 		{6,7,8,9,10},
// 	};

// 	int i,j;
	
// 	for(i =0; i < 2;i++)
// 	{
// 		for(j = 0; j < 5;j++)
// 			printf("addr:%p value:%d\n",&matrix[i][j],matrix[i][j]);
// 	}
// 	return 0;
// }

// -------------------------
// addr:0028FF10 value:1
// addr:0028FF14 value:2
// addr:0028FF18 value:3
// addr:0028FF1C value:4
// addr:0028FF20 value:5
// addr:0028FF24 value:6
// addr:0028FF28 value:7
// addr:0028FF2C value:8
// addr:0028FF30 value:9
// addr:0028FF34 value:10
// 
// 

// typedef int (*parray)[5] ;

// void print_array(parray p, int row, int col)
// {
// 	int i = 0;
// 	int j = 0;
	
// 	if(NULL == p)
// 		return;

// 	for(i = 0; i < row; i++)
// 	{
// 		for(j = 0; j < col;j++)
// 			printf("addr:%p,value:%d\n",(*(p+i)+j),*(*(p+i)+j));
// 	}
// }
// int main(int argc, char const *argv[])
// {
// 	int nums[2][5] = {
// 		{1,2,3,4,5,},
// 		{6,7,8,9,10,},
// 	};
// 	print_array(nums,2,5);
// 	return 0;
// }
// -------------------------------
// addr:0028FF10,value:1
// addr:0028FF14,value:2
// addr:0028FF18,value:3
// addr:0028FF1C,value:4
// addr:0028FF20,value:5
// addr:0028FF24,value:6
// addr:0028FF28,value:7
// addr:0028FF2C,value:8
// addr:0028FF30,value:9
// addr:0028FF34,value:10
// 
// 
// 
// 


// void print_array(int arr[][5],int rows)
// {
// 	int i =0;
// 	int j = 0;
// 	for(i =0; i < rows;i++)
// 	{
// 		for(j= 0;j<5;j++)
// 		{
// 			printf("addr:%p value:%d\n", &arr[i][j],arr[i][j]);
// 		}
// 	}
// }
// int main(int argc, char const *argv[])
// {
	
// 	int nums[2][5]={
// 		{1,2,3,4,5},
// 		{6,7,8,9,10},
// 	};

// 	print_array(nums,sizeof(nums)/sizeof(nums[0]));
// 	return 0;
// }

// -------------------------------
// addr:0028FF10 value:1
// addr:0028FF14 value:2
// addr:0028FF18 value:3
// addr:0028FF1C value:4
// addr:0028FF20 value:5
// addr:0028FF24 value:6
// addr:0028FF28 value:7
// addr:0028FF2C value:8
// addr:0028FF30 value:9
// addr:0028FF34 value:10
// 
// 

// #define ROWS 2
// #define COLS 5

// int main(int argc, char const *argv[])
// {
// 	int **array = (int **)malloc(ROWS*sizeof(int));
// 	int i = 0;
// 	int j = 0;
	
// 	for(i = 0; i < COLS;i++)
// 	{
// 		*(array+i) = calloc(sizeof(int),5);

// 		if(*(array+i) == NULL)
// 			return ERROR;
// 		for(j = 0; j < COLS;j++)
// 		{
// 			*(*(array+i)+j) = j;
// 		}
// 	}

// 	for(i = 0; i < ROWS;i++)
// 	{
// 		printf("addr:%p,value:%p\n", (array+i),*(array+i));
// 		for ( j = 0; j < COLS; ++j)
// 		{
// 			printf("addr:%p,value:%d\n",*(array+i)+j,*(*(array+i)+j));
// 		}
// 	}
// 	return 0;
// }


// #define ROWS 2
// #define COLS 5
// int main(int argc, char const *argv[])
// {
// 	int **array = (int **)calloc(sizeof(int*),ROWS);
// 	int i = 0;
// 	int j = 0;
	
// 	if(array == NULL)
// 		return ERROR;
	
// 	array[0] = (int *)calloc(sizeof(int),ROWS*COLS);
// 	if(array[0] == NULL)
// 		return ERROR;

// 	for(i = 0; i < ROWS;++i)
// 	{
// 		array[i] = array[0]+COLS*i;
// 		for(j = 0; j < COLS;j++)
// 			array[i][j] = j;
// 	}

// 	for(i = 0; i < ROWS;i++)
// 	{
// 		printf("addr:%p,value:%p\n", (array+i),*(array+i));
// 		for ( j = 0; j < COLS; ++j)
// 		{
// 			printf("addr:%p,value:%d\n",*(array+i)+j,*(*(array+i)+j));
// 		}
// 	}
// 	return 0;
// }
// -------------------------
// addr:003D0F78,value:003D0FF8
// addr:003D0FF8,value:0
// addr:003D0FFC,value:1
// addr:003D1000,value:2
// addr:003D1004,value:3
// addr:003D1008,value:4
// addr:003D0F7C,value:003D100C
// addr:003D100C,value:0
// addr:003D1010,value:1
// addr:003D1014,value:2
// addr:003D1018,value:3
// addr:003D101C,value:4
// 
// 
// #define ROWS 2
// #define COLS 5


// int main(int argc, char const *argv[])
// {
// 	int *P = calloc(sizeof(int),ROWS*COLS);
// 	int i = 0;
// 	int j = 0;
// 	int (*array)[COLS] = (void*)p;
	
// 	if(NULL == array)
// 		return ERROR;
// 	for(i = 0; i < ROWS;i++)
// 	{
// 		for(j = 0; j < COLS;j++)
// 		{
// 			*(array+i*COLS+j) = j;
// 		}
// 	}

// 	for(i = 0; i < ROWS;i++)
// 	{
// 		printf("addr:%p\n", (array+i*COLS));
// 		for ( j = 0; j < COLS; ++j)
// 		{
// 			printf("addr:%p,value:%d\n",(array+i*COLS+j),*(array+i*COLS+j));
// 		}
// 	}
	
// 	return 0;
// }
// 


// int main(int argc, char const *argv[])
// {
// 	printf("sizeof(char):%d\n",sizeof(char));
// 	printf("sizeof('a'):%d\n",sizeof('a'));
// 	return 0;
// }
// ---------------------------------
// sizeof(char):1
// sizeof('a'):4
// 

// #define PID "xptd"

// int main(int argc, char const *argv[])
// {
// 	char *pid =PID;
// 	printf("%s\n", pid); 
// 	return 0;
// }

// ---------------------
// xptd
// 
// 



// char *get_str(void)
// {
// 	char*str = "hello xptd";
// 	return str;
// }
// char *get_str_1(void)
// {
// 	char str[] = "hello xptd";
// 	printf("%s\n",str);
// 	return str;
// }
// int main(int argc, char const *argv[])
// {
// 	char *p = NULL;
// 	p = get_str();
// 	printf("%s\n", p);
// 	p = get_str_1();
// 	printf("%s\n", p);

// 	return 0;
// }
// 

// int main(int argc, char const *argv[])
// {
// 	char *str = "xptd";
// 	printf("%s\n", str);
// 	*str='L';
// 	printf("%s\n",str );
// 	return 0;
// }
// 

// int main(int argc, char const *argv[])
// {
// 	char str[5];
// 	str[0] = 'x';
// 	str[1] = 'p';
// 	str[2] = 't';
// 	str[3] = 'd';
// 	str[4] = '\0';
// 	printf("%s\n", str);

// 	return 0;
// }
// ---------------
// xptd
// 

// int main(int argc, char const *argv[])
// {
// 	char str[5];
// 	strcpy(str,"xptd");
// 	printf("%s\n", str);
// 	return 0;
// }
// --------------
// xptd
// 
// 
// 


// int main(int argc, char const *argv[])
// {
// 	char*str = NULL;
// 	strcpy(str,"xptd");
// 	printf("%s",str);
// 	return 0;
// }


// #define CODER "xptd"
// int main(int argc, char const *argv[])
// {
// 	char*str = calloc(strlen(CODER)+1,1);

// 	if(NULL == str)
// 		return ERROR;
	
// 	strcpy(str,CODER);

// 	printf("%s\n",str);
// 	return 0;
// }

// ------------------
// xptd
// 
// 

// int main(int argc, char const *argv[])
// {
// 	char*str = "xptd";
// 	printf("%s\n", str);
// 	return 0;
// }
// ----------------------
// xptd
// 
// 
// int main(int argc, char const *argv[])
// {
// 	char *command = NULL;
// 	printf("%s\n", "please input a command");
// 	scanf("%s",command);

// 	return 0;
// }
// 

// #define STEP_LEN 5

// char *get_line()
// {
// 	char *input = (char*)calloc(STEP_LEN,1);
// 	char len = 0;
// 	char buf_len = STEP_LEN;
// 	char *cur_pos = input;
// 	char c = '\n';
	
// 	if (NULL == input)
// 		return NULL;

// 	while(1)
// 	{
// 		if((c = fgetc(stdin)) == '\n')
// 			break;
		
// 		if(++len < buf_len)
// 		{
// 			char *temp = realloc(input,buf_len += STEP_LEN);
// 			if(NULL == temp)
// 			{
// 				free(input);
// 				return NULL;
// 			}
// 			cur_pos = temp + (cur_pos - input);
// 			input = temp;
// 		}
// 		*cur_pos++ = c;
// 	}
// 	*cur_pos = '\0';
	
// 	printf("get_line:%s\r\n",input);
	
// 	return input;
// }

// int main(int argc, char const *argv[])
// {
// 	char *str = NULL;
// 	if(NULL == (str = get_line()))
// 		return ERROR;
	
// 	printf("%s----len:%d\n", str, strlen(str)+1);
// 	return OK;
// }
// 
// 


// #define PASS_WD "xptd"
// int main(int argc, char const *argv[])
// {
// 	char passwd[9];
// _retry:	
// 	scanf("%s",passwd);
// 	if(!(strcmp(PASS_WD,passwd)))
// 		printf("%s\n", "passwd ok");
// 	else
// 	{
// 		printf("%s\n", "passwd error");
// 		goto _retry;
// 	}

// 	return 0;
// }
// 


// int main(int argc, char const *argv[])
// {
// 	char* names[4];
// 	char name[30];

// 	unsigned int count = 0;
// _input:
// 	printf("%s\n", "please input a name(max 29 chars):");
// 	scanf(" %s",name);
// 	names[count]=(char *)calloc(1,strlen(name)+1);

// 	strcpy(names[count],name);
// 	count++;
// 	if(count < 4)
// 		goto _input;
	
// 	for(count = 0 ; count < 4;count++)
// 	{
// 		printf("addr:%p value:%s\n",names[count],names[count]);
// 		free(names[count]);
// 	}
	
// 	return 0;
// }
// 
// 


// #define ERROR_PRINT "error:"
// int main(int argc, char const *argv[])
// {
// 	char*error_msg = "it's time to over wrok\n";
// 	char *print_buf = calloc(1,strlen(ERROR_PRINT)+strlen(error_msg)+1);
// 	if(NULL == print_buf)
// 		return ERROR;
// 	strcpy(print_buf,ERROR_PRINT);
// 	printf("%s\n", strcat(print_buf,error_msg));
// 	free(print_buf);
// 	return 0;
// }
// -------------------------------
// error:it's time to over wrok
// 

// int main(int argc, char const *argv[])
// {
// 	char* error = "ERROR";
// 	char* err_msg = "it's time to over wrok";
// 	printf("%s\n", strcat(error,err_msg));
// 	printf("%s\n", error);
// 	printf("%s\n",err_msg);
// 	return 0;
// }
// 
// 


// int main(int argc, char const *argv[])
// {
// 	char *root_path = "C:";
// 	char *file_path = (char *)calloc(1,(strlen(root_path)+3));
// 	char *file = "\\\\";
// 	printf("len:%d\n",strlen(root_path)+1);
	
// 	stpcpy(file_path,root_path);
// 	file_path = strcat(file_path,file);
// 	printf("%s----len:%d\n",file_path,strlen(file_path)+1);
	
// 	return 0;
// }
// ------------------------------
// len:3
// C:\\----len:5
// 
// 
// 



// unsigned int str_len(const char* str)
// {
// 	unsigned int count = 0;
// 	if(NULL == str)
// 		return count;

// 	while(*str++)
// 	{
// 		count++;
// 	}
// 	return count;
// }

// int main(int argc, char const *argv[])
// {
// 	char*str = "xptd\n";

// 	printf("%d\n", str_len(str));

// 	return 0;
// }

// #define STEP_LEN 10
// int str_len(const char *str)
// {
// 	int len = 0;

// 	if(NULL == str)
// 	{
// 		fprintf(stderr, "%s\n", "strl_len error\n");
// 		return -1;
// 	}

// 	while(*str++ != '\0')
// 		len++;

// 	return len;
// }

// char *get_input_line(void)
// {
// 	char *input = NULL;
// 	char c = '\n';
// 	char *cur_input_buffer = NULL;
// 	unsigned int max_buffer_len = STEP_LEN;
// 	unsigned int cur_buffer_len = 0;

	
// 	if(NULL == (input=calloc(STEP_LEN,1)))
// 	{
// 		fprintf(stderr, "%s\n", "calloc error\n");
// 		return NULL;
// 	}

// 	cur_input_buffer = input;

// 	while((c = fgetc(stdin)) != '\n')
// 	{

// 		if(++cur_buffer_len > max_buffer_len)
// 		{
// 			char *temp_buffer = realloc(input, max_buffer_len += STEP_LEN);
// 			if(NULL == temp_buffer)
// 			{
// 				fprintf(stderr, "%s\n", "realloc error\n");
// 				free(input);
// 				return NULL;
// 			}
			
// 			cur_input_buffer = temp_buffer + (cur_input_buffer - input);
// 			input = temp_buffer;
// 		}
// 		*cur_input_buffer++ = c;
// 	}
// 	*cur_input_buffer = '\0'; 
// 	return input;
// }

// char* str_trim(char *str)
// {
	
// 	char *old_str = NULL;
//     char * new_str = NULL;

// 	if(NULL == str)
// 	{
// 		printf("%s\n", "str_trim error\n");
// 		return NULL;
// 	}

// 	old_str = str;
//     new_str = str;

// 	while(*old_str == ' ')
// 		old_str++;

// 	while(*old_str)
// 		*new_str++ = *old_str++;

// 	new_str--;
// 	while(*new_str == ' ')
// 		new_str--;

// 	*(++new_str) = '\0';
// 	return (char *)realloc(str,str_len(str)+1);
// }

// int main(int argc, char const *argv[])
// {
// 	char *input_str = NULL;
// 	char *trim_str = NULL;
// 	printf("%s\n", "please input a line:\n");

// 	input_str = get_input_line();
// 	if (NULL == input_str)
// 	{
// 		fprintf(stderr, "%s\n", "get input line error");
// 		return ERROR;
// 	}
// 	printf("%s_str len %d\n",input_str,str_len(input_str));
// 	trim_str = str_trim(input_str);

// 	if(NULL != trim_str)
// 		printf("%s_str len %d\n",trim_str,str_len(trim_str));
	
// 	free(trim_str);
// 	return 0;
// }



// #include <stdio.h>
// #include <string.h>

// struct _person
// {
// 	char *first_name;
// 	char *secode_name;
// 	char *title;
// 	unsigned int age;
// }person;

// int main(int argc, char const *argv[])
// {
// 	struct _person person_1;
// 	person_1.first_name = (char*)malloc(strlen("gao")+1);
// 	if(NULL == person_1.first_name)
// 		return 1;
// 	strcpy(person_1.first_name,"gao");
// 	person_1.secode_name = (char*)malloc(strlen("yj")+1);
// 	if(NULL == person_1.secode_name)
// 	{
// 		free(person_1.first_name);
// 		return 1;
// 	}
// 	strcpy(person_1.secode_name,"yj");
// 	person_1.title = (char *)malloc(strlen("xptd")+1);
// 	if(NULL == person_1.title)
// 	{
// 		free(person_1.first_name);
// 		free(person_1.secode_name);
// 		return 1;
// 	}
// 	strcpy(person_1.title,"xptd");
// 	printf("struct _person size:%d\n", sizeof(struct _person));	
// 	person_1.age = 20;
// 	printf("%s\n",person_1.secode_name );
// 	printf("%s\n",person_1.title );
// 	printf("%d\n",person_1.age);
// 	person = person_1;
// 	printf("%s\n",person.first_name);
// 	printf("%s\n",person.secode_name );
// 	printf("%s\n",person.title );
// 	printf("%d\n",person.age);
// 	return 0;
// }

// --------------------------
// struct _person size:16
// gao
// yj
// xptd
// 20
// gao
// yj
// xptd
// 20	


// #include <stdio.h>
// #include <string.h>

// typedef struct _person
// {
// 	char *first_name;
// 	char *secode_name;
// 	char *title;
// 	unsigned int age;
// }Person;

// int main(int argc, char const *argv[])
// {
// 	Person person_1;
// 	person_1.first_name = (char*)malloc(strlen("gao")+1);
// 	if(NULL == person_1.first_name)
// 		return 1;
// 	strcpy(person_1.first_name,"gao");
// 	person_1.secode_name = (char*)malloc(strlen("yj")+1);
// 	if(NULL == person_1.secode_name)
// 	{
// 		free(person_1.first_name);
// 		return 1;
// 	}
// 	strcpy(person_1.secode_name,"yj");
// 	person_1.title = (char *)malloc(strlen("xptd")+1);
// 	if(NULL == person_1.title)
// 	{
// 		free(person_1.first_name);
// 		free(person_1.secode_name);
// 		return 1;
// 	}
// 	strcpy(person_1.title,"xptd");
// 	printf("struct _person size:%d\n", sizeof(struct _person));	
// 	person_1.age = 20;
// 	printf("%s\n",person_1.first_name );
// 	printf("%s\n",person_1.secode_name );
// 	printf("%s\n",person_1.title );
// 	printf("%d\n",person_1.age);
// 	return 0;
// }
// -----------------------
// struct _person size:16
// gao
// yj
// xptd
// 20


// #include <stdio.h>
// #include <string.h>

// typedef struct _person
// {
// 	char *first_name;
// 	char *secode_name;
// 	char *title;
// 	unsigned int age;
// }Person;

// int main(int argc, char const *argv[])
// {
// 	Person* person_1 = (Person *)malloc(sizeof(Person));

// 	if(NULL == person_1)
// 		return 1;

// 	(*person_1).first_name = (char*)malloc(strlen("gao")+1);
// 	if(NULL == (*person_1).first_name)
// 		return 1;
// 	strcpy(person_1->first_name,"gao");
// 	person_1->secode_name = (char*)malloc(strlen("yj")+1);
// 	if(NULL == person_1->secode_name)
// 	{
// 		free(person_1->first_name);
// 		return 1;
// 	}
// 	strcpy((*person_1).secode_name,"yj");
// 	(*person_1).title = (char *)malloc(strlen("xptd")+1);
// 	if(NULL == person_1->title)
// 	{
// 		free(person_1->first_name);
// 		free(person_1->secode_name);
// 		return 1;
// 	}
// 	strcpy(person_1->title,"xptd");
// 	printf("struct _person size:%d\n", sizeof(struct _person));	
// 	(*person_1).age = 20;
// 	printf("%s\n",person_1->first_name );
// 	printf("%s\n",person_1->secode_name );
// 	printf("%s\n",person_1->title );
// 	printf("%d\n",(*person_1).age);
// 	return 0;
// }

// ------------------------
// struct _person size:16
// gao
// yj
// xptd
// 20
// 请按任意键继续. . .


//#pragma pack(1);

// typedef struct _person
// {
// 	char *first_name;
// 	char *secode_name;
// 	char *title;
// 	unsigned int age;
// }Person;
 
//  typedef struct 
//  {
//  	char * first_name;
//  	char *secode_name;
//  	char *title;
//  	unsigned short age;
//  }AlterPerson;

// typedef struct 
// {
// 	int i;
// 	short k;
// 	Person person;
// 	short j;
// 	AlterPerson alt_person;
// }Test;

// int main(int argc, char const *argv[])
//  {
//  	/* code */
//  	printf("sizeof(Person):%d\n", sizeof(Person));
//  	printf("sizeof(AlterPerson):%d\n", sizeof(AlterPerson));
// 	printf("sizeof(Test):%d\n", sizeof(Test));
//  	return 0;
//  }


// --------------------------
// sizeof(Person):16
// sizeof(AlterPerson):16
// sizeof(Test):44
// 请按任意键继续. . .

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// typedef struct 
// {
// 	char* first_name;
// 	char* second_name;
// 	char* title;
// 	unsigned int age;
// }Person;


// int init_data(Person *person,const char* fn, const char* sn,
// 	const char* tt, unsigned int num)
//  {
//  	person->first_name = calloc(strlen(fn)+1,1);
//  	if(NULL == person->first_name)
//  		goto err1;
//  	strcpy((*person).first_name,fn);

//  	(*person).second_name = malloc(strlen(sn)+1);
//  	if(NULL == person->second_name)
//  		goto err2;
//  	memset(person->second_name,0,strlen(sn)+1);
//  	strcpy(person->second_name,sn);

//  	person->title = calloc(1,strlen(tt)+1);
//  	if(NULL == person->title)
//  		goto err3;
//  	strcpy((*person).title,tt);
//  	person->age = num;
 	
//  	return 0;

//  err3:
//  	free(person->second_name);
//  err2:
//  	free(person->first_name);
//  err1:
//   return 1;

//  }

// int print_data(Person *person)
// {
// 	if(NULL == person)
// 	{
// 		printf("data error\n");
// 		return 1;
// 	}

// 	printf("%s\n", person->first_name);
// 	printf("%s\n", person->second_name);
// 	printf("%s\n", person->title);
// 	printf("%d\n", person->age);

// 	return 0;
// }

// void free_data(Person *person)
// {
// 	if(person == NULL)
// 		return ;
// 	free(person->first_name);
// 	free(person->second_name);
// 	free(person->title);
// 	free(person);
	
// }
// void process_data(void)
// {

// 	Person *person = calloc (1,sizeof(Person));
// 	if(NULL == person)
// 		return;
//     if(!(init_data(person,"gao","yj","xptd",18)))
//     	print_data(person);
//     free_data(person);

// }

// int main(int argc, char const *argv[])
// {
// 	process_data();
// 	return 0;
// }

// --------------------------
// gao
// yj
// xptd
// 18
// 请按任意键继续. . .


// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #define POOL_SIZE 10

// typedef struct{
// 	char* first_name;
// 	char* second_name;
// 	char* title;
// 	unsigned int age;
// }Person;

// Person *person_list[POOL_SIZE];

// void init_pool()
// {
// 	int index;
// 	for(index = 0; index < POOL_SIZE;index++)
// 	{
// 		person_list[index] = NULL;
// 	}
// }

// Person *get_element(void)
// {
// 	int index;
// 	Person *person = NULL;
// 	for (index = 0; index < POOL_SIZE;index++)
// 	{
// 		if(NULL != person_list[index])
// 		{
// 			person = person_list[index];
// 			person_list[index] = NULL;
// 			return person;
// 		}
			
		
// 	}
	
// 	person = calloc(1,sizeof(Person));
// 	if(NULL == person)
// 	{
// 		printf("%s\n","calloc error get element failed");
// 		return NULL;
// 	}
// 	return person;

// }
// void free_person(Person *person)
// {
// 	free(person->first_name);
// 	free(person->second_name);
// 	free(person->title);
// }
// Person *put_element(Person *person)
// {
// 	int index = 0;
// 	if(NULL == person)
// 		return NULL;
// 	for(index = 0;index < POOL_SIZE;index++)
// 	{
// 		if(person_list[index] == NULL)
// 		{
// 			person_list[index]= person;
// 			return person;
// 		}
// 	}
// 	free_person(person);
// 	free(person);
// 	return NULL;

// }

// void print_data(Person *person)
// {
// 	if(NULL == person)
// 	{
// 		printf("%s","print info error");
// 		return;
// 	}
// 	printf("%s\n",person->first_name);
// 	printf("%s\n",(*person).second_name);
// 	printf("%s\n", (*person).title);
// 	printf("%d\n", person->age);

// }
// int init_person(Person *person, const char *fn,const char *sn,
// 	const char *tt, unsigned int age)
// {
// 	if(NULL == (person->first_name = (char *)calloc(1,strlen(fn)+1)))
// 	{
// 		printf("%s\n","calloc error");
// 		goto _err1;
// 	}
// 	strcpy(person->first_name,fn);

// 	if(NULL == (person->second_name = (char *)calloc(1,strlen(sn)+1)))
// 	{
// 		printf("%s\n","calloc error");
// 		goto _err2;
// 	}
// 	strcpy(person->second_name,sn);
// 	if(NULL ==(person->title = malloc(strlen(tt)+1)))
// 	{
// 		printf("%s\n", "malloc error");
// 		goto _err3;
// 	}
// 	memset(person->title,0,strlen(tt)+1);
// 	strcpy(person->title,tt);
// 	person->age = age;
// 	return 0;

// _err3:
// 	free(person->second_name);
// _err2:
// 	free(person->first_name);
// _err1:
// 	return 1;
// }
// int main(int argc, char const *argv[])
// {
// 	Person *person = NULL;
// 	init_pool();
// 	person = get_element();
// 	init_person(person,"gao","yunjie","xptd",18);
// 	print_data(person);
// 	put_element(person);
// 	return 0;
// }
// -------------------------------
// gao
// yunjie
// xptd
// 18
// 请按任意键继续. . .'''



// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// typedef void (*pFdisplay)(void*);

// typedef int (*pFcmp)(void*,void*);

// typedef struct 
// {
// 	char name[32];
// 	unsigned int age;
// }Employee;

// typedef struct _node
// {
// 	void *data;
// 	struct _node *next_ptr;
	
// }Node;
// typedef struct 
// {
// 	Node *list_head;
// 	Node *list_tail;
// 	Node *list_cur;
// }LinkList;
// /*
// 0:相等；
// 1：大于
// -1：小于；
// */
// int cmp_employee(Employee* e1,Employee *e2)
// {
// 	return strcmp(e1->name,e2->name);
// }

// void print_info(Employee *e)
// {
// 	printf("%s\n",e->name);
// 	printf("%d\n",e->age);
// }

// void init_list(LinkList* list)
// {
// 	list->list_head = NULL;
// 	list->list_tail = NULL;
// 	list->list_cur =  NULL;

// }
// /*
// 	1.定义节点指针变量；
// 	2.为节点变量开辟空间；
// 	3.赋值节点的数据域；
// 	4.处理节点的指针域（将节点加入到链表的合适位置）;
// */
// void add_head(LinkList* list,void* dat)
// {
// 	Node *node = calloc(1,sizeof(Node));
// 	if(NULL == node)
// 		return;
// 	node->data = dat;

// 	if(NULL == list->list_head)
// 	{
// 		list->list_tail = node;
// 		node->next_ptr = NULL;
// 	}
// 	else
// 	{
// 		node->next_ptr = list->list_head;
// 	}
// 	list->list_head = node;
// }

// void add_tail(LinkList* list,void* dat)
// {
// 	Node *node = NULL;
// 	if(NULL == (node = calloc(1,sizeof(Node))))
// 		return;
// 	node->data = dat;
// 	if(NULL == list->list_tail)
// 	{
// 		list->list_head = node;
// 	}
// 	else
// 	{
// 		list->list_tail->next_ptr = node;
// 	}
// 	node->next_ptr = NULL;
// 	list->list_tail = node;
// }
// /*
// 1.param1: list pointer;
// 2.param2: compare funcitong pointer;
// 3.parama3:target data pointer;

// */
// Node *get_node(LinkList* list, pFcmp fcmp,void *dat)
// {
// 	Node *node = list->list_head;

// 	if(NULL == list || NULL == fcmp || NULL == dat )
// 		return NULL;
// 	while(node != NULL)
// 	{
// 		if(0 == fcmp(node->data,dat))
// 		{
// 			return node;
// 		}
// 		node = node->next_ptr;
// 	}
// 	return NULL;

// }

// /*
// 	1.先确认给定的数据是否再当前列表（删除只是给的定节点数据域的某一个字段）；
// 		用get_node()函数判断，如果存在调用delete_node()函数进行删除操作，
// 	2.如果数据在链表中：移动指针指向既；
// 		1.
// 	3.释放内存空间；
// */
// void delete_node(LinkList* list, Node* node)
// {
// 	if(NULL == list || NULL == node)
// 		return;
// 	if(node == list->list_head)
// 	{
// 		if(node->next_ptr == NULL)
// 		{
// 			list->list_head = list->list_tail = NULL;
// 		}
// 		else
// 		{
// 			list->list_head = node->next_ptr;
// 		}
// 	}
// 	else
// 	{
// 		Node * tmp_node = list->list_head;
// 		while((tmp_node != NULL)&&( tmp_node->next_ptr != node))
// 		{
// 			tmp_node = tmp_node->next_ptr;
// 		}
// 		if(NULL != tmp_node)
// 			tmp_node->next_ptr = node->next_ptr;
// 	}
// 	free(node);
// }


// void print_list(LinkList *list, pFdisplay show)
// {
// 	printf("%s\n", "print emp_list");
// 	Node *cur = list->list_head;
// 	while(cur != NULL)
// 	{
// 		show(cur->data);
// 		cur = cur->next_ptr;
// 	}
// }

// int main(int argc, char const *argv[])
// {
// 	LinkList emp_list;

// 	Employee *e1 = calloc(1,sizeof(Employee));
// 	Employee *e2 = NULL;
// 	Employee *e3 = NULL;

// 	if(NULL == e1)
// 		goto _err1; 
// 	strcpy(e1->name,"gao");
// 	e1->age = 18;
// 	if(NULL == (e2 = malloc(sizeof(Employee))))
// 		goto _err2; 
// 	memset(e2,0,sizeof(Employee));
// 	strcpy(e2->name,"yun");
// 	e2->age = 19;

// 	if(NULL == (e3 = calloc(1,sizeof(Employee))))
// 		goto _err3;
// 	strcpy(e3->name,"jie");
// 	e3->age = 20;

// 	init_list(&emp_list);

// 	add_head(&emp_list,e1);
// 	add_head(&emp_list,e2);
// 	add_head(&emp_list,e3);

    
//     add_tail(&emp_list,e1);
//     add_tail(&emp_list,e2);
//     add_tail(&emp_list,e3);
    
//    Node *node = get_node(&emp_list,(int (*)(void*,void*))cmp_employee,e3);
//    	if(node)
//    		delete_node(&emp_list,node);
//    	print_list(&emp_list,(void (*)(void *))print_info);

// _err3:
// 	free(e2);
// _err2:
// 	free(e1);
// _err1:
// 	return 1;
// }

// ---------------------------------
// print emp_list
// yun
// 19
// gao
// 18
// gao
// 18
// yun
// 19
// jie
// 20
// 请按任意键继续. . .




// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>


// typedef struct 
// {
// 	char name[31];
// 	unsigned int age;
// }Employee;

// typedef struct _node
// {
// 	void * data;
// 	struct _node* next_ptr;
// }Node;

// typedef struct
// {
// 	 Node* head;
// 	 Node* tail;
// 	 Node* cur;
// }LinkList;

// typedef LinkList Queue;

// void init_list(LinkList * list)
// {
// 	list->head = NULL;
// 	list->tail = NULL;
// 	list->cur = NULL;
// }

// void init_queue(Queue * queue)
// {
// 	init_list(queue);
// }

// void add_head(LinkList *list,void* dat)
// {
// 	Node *node = NULL;	
// 	if(NULL== list)
// 		return;
// 	if(NULL == (node = calloc(1,sizeof(Node))))
// 		return;
// 	node->data = dat;


// 	if(NULL == list->head)
// 	{
// 		list->tail = node;
// 		node->next_ptr = NULL;
// 	}
// 	else
// 	{
// 		node->next_ptr = list->head;
// 	}
// 	list->head = node;
// }
// void in_queue(Queue *queue,void* dat)
// {
// 	add_head(queue,dat);
// }
// void* out_queue(Queue *queue)
// {
// 	Node *tmp_node = queue->head;
// 	void *data = NULL;
// 	if(NULL == queue)
// 		return NULL;
// 	if(NULL == queue->head)
// 	{
// 		data = NULL;
// 	}
// 	else if(queue->head == queue->tail)
// 	{
// 		queue->head = queue->tail = NULL;
// 		data = tmp_node->data;
// 		free(tmp_node);
// 	}else
// 	{
// 		while(tmp_node->next_ptr != queue->tail)
// 			tmp_node = tmp_node->next_ptr;

// 		queue->tail = tmp_node;
// 		tmp_node = tmp_node->next_ptr;
// 		queue->tail->next_ptr = NULL;
// 		data = tmp_node->data;
// 		free(tmp_node);
// 	}
// 	return data;
// }

// int main(int argc, char const *argv[])
// {
// 	Queue emp_queue;
	
// 	Employee *e1 = calloc(1,sizeof(Employee));
// 	Employee *e2 = NULL;
// 	Employee *e3 = NULL;

// 	if(NULL == e1)
// 		goto _err1; 
// 	strcpy(e1->name,"gao");
// 	e1->age = 18;
// 	if(NULL == (e2 = malloc(sizeof(Employee))))
// 		goto _err2; 
// 	memset(e2,0,sizeof(Employee));
// 	strcpy(e2->name,"yun");
// 	e2->age = 19;

// 	if(NULL == (e3 = calloc(1,sizeof(Employee))))
// 		goto _err3;
// 	strcpy(e3->name,"jie");
// 	e3->age = 20;

// 	init_queue(&emp_queue);
// 	in_queue(&emp_queue,e1);
// 	in_queue(&emp_queue,e2);
// 	in_queue(&emp_queue,e3);

// 	Employee *tmp_emp = (Employee *)out_queue(&emp_queue);
// 	printf("%d\n",tmp_emp->age);
// 	tmp_emp = (Employee *)out_queue(&emp_queue);
// 	printf("%d\n",tmp_emp->age);
// 	tmp_emp = (Employee *)out_queue(&emp_queue);
// 	printf("%d\n",tmp_emp->age);

// _err3:
// 	free(e2);
// _err2:
// 	free(e1);
// _err1:
// 	return 1;

// }
// --------------------------
// 18
// 19
// 20
// 请按任意键继续. . .


// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// typedef struct 
// {	
// 	char name[31];
// 	unsigned int age;
// }Employee;

// typedef struct _node
// {
// 	void *data;
// 	struct _node *next_ptr;
// }Node;

// typedef struct 
// {
// 	Node *head;
// 	Node *tail;
// 	Node *cur;

// }LinkList;

// typedef  LinkList Stack;

// void init_stack(Stack *stack)
// {
// 	stack->head = NULL;
// 	stack->tail = NULL;
// 	stack->cur = NULL;
// }

// void push_stack(Stack *stack,void *dat)
// {
// 	Node *node = NULL;
// 	if(NULL == stack)
// 		return;
// 	if(NULL==(node = calloc(1,sizeof(Node))))
// 		return;
// 	node->data = dat;
// 	if(stack->head == NULL)
// 	{
// 		stack->tail = node;
// 		node->next_ptr = NULL;
// 	}
// 	else
// 	{
// 		node->next_ptr = stack->head;
// 	}
// 	stack->head = node;
// }

// void *pop_stack(Stack* stack)
// {
// 	void* data = NULL;
// 	Node *tmp_node = stack->head;
// 	if(NULL == stack)
// 		return NULL;
// 	if(NULL == stack->head)
// 		return NULL;
// 	else if(stack->head == stack->tail)
// 	{
// 		stack->tail = stack->head = NULL;
// 		data = tmp_node->data;
// 		free(tmp_node);
// 	}
// 	else
// 	{
// 		data = tmp_node->data;
// 		stack->head =tmp_node->next_ptr;
// 		free(tmp_node);
// 	}
// 	return data;
// }

// int get_stack_len(Stack *stack)
// {
// 	int len = -1;
// 	Node *node = stack->head;
// 	if(NULL == stack)
// 		return -1;
// 	if(stack->head == NULL)
// 		len = 0;
// 	len = 1;
// 	while(node->next_ptr != NULL)
// 	{
// 		len++;
// 		node = node->next_ptr;
// 	}
// 	return len;
// }
// int main(int argc, char const *argv[])
// {
// 	Stack emp_stack;
// 	int index = -1;
// 	int i = 0;
// 	Employee *e1 = calloc(1,sizeof(Employee));
// 	Employee *e2 = NULL;
// 	Employee *e3 = NULL;

// 	if(NULL == e1)
// 		goto _err1; 
// 	strcpy(e1->name,"gao");
// 	e1->age = 18;
// 	if(NULL == (e2 = malloc(sizeof(Employee))))
// 		goto _err2; 
// 	memset(e2,0,sizeof(Employee));
// 	strcpy(e2->name,"yun");
// 	e2->age = 19;

// 	if(NULL == (e3 = calloc(1,sizeof(Employee))))
// 		goto _err3;
// 	strcpy(e3->name,"jie");
// 	e3->age = 20;
// 	init_stack(&emp_stack);
// 	push_stack(&emp_stack,e1);
// 	push_stack(&emp_stack,e2);
// 	push_stack(&emp_stack,e3);

// 	push_stack(&emp_stack,e1);
// 	push_stack(&emp_stack,e2);
// 	push_stack(&emp_stack,e3);
	
// 	if((index = get_stack_len(&emp_stack)) >= 0)
// 		printf("stack len:%d\n", index);

// 	for( i = 0; i < index;i++ )
// 	{	
// 		Employee *tmp_node = NULL;
// 		tmp_node = pop_stack(&emp_stack);
// 		if(NULL != tmp_node)
// 			printf("name:%s---age:%d\n",tmp_node->name,tmp_node->age);
// 		else
// 			printf("%s\n","pop_err" );
// 	}
	

// _err3:
// 	free(e2);
// _err2:
// 	free(e1);
// _err1:
// 	return 1;

// }

// -----------------------------------
// stack len:6
// name:jie---age:20
// name:yun---age:19
// name:gao---age:18
// name:jie---age:20
// name:yun---age:19
// name:gao---age:18
// 请按任意键继续. . .

// #include <stdio.h>
// #include <stdlib.h>
// #include <assert.h>
// int main(int argc, char const *argv[])
// {
// 	char * str = NULL;
// 	assert(str != NULL);
// 	str = "xptd";
// 	printf("%s\n", str);
// 	return 0;
// }
// --------------------------
// Assertion failed: str != NULL,


// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// void char_repalce(char buffer[],char c,unsigned int size)
// {
// 	unsigned int count = 0;;
// 	if(NULL == buffer)
// 		return;
// 	while(buffer != '\0' && count++ <size)
// 	{
// 		*buffer = c;
// 		buffer++;
// 	}
// }
// int main(int argc, char const *argv[])
// {
// 	char name[8];
// 	strcpy(name,"gaoyunjie");
// 	printf("%s\n", name);
// 	char_repalce(name,'+',sizeof(name));
// 	printf("%s\n",name );
// 	return 0;
// }
// ----------------------
// gaoyunjie
// ++++++++e
// 请按任意键继续. . .


// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// int main(int argc, char const *argv[])
// {
// 	char name[8];
// 	char *str = NULL;
// 	str = name;
// 	strcpy(name,"gaoyunjie");
// 	printf("%d\n", sizeof(name));
// 	printf("%d\n",sizeof(str));
// 	char_repalce(name,'+',sizeof(str));
// 	return 0;
// }
// --------------------
// 8
// 4
// 请按任意键继续. . .




// #include <stdio.h>
// #include <pthread.h>
// #include <stdlib.h>
// #include <windows.h>
// #include <time.h>

// #define MAX_COUNT 10000

// int g_number = 0;

// void *counter_1(void *arg)
// {
// 	int i = 1;
// 	while( i <= (MAX_COUNT / 4))
// 	{
// 		g_number++;
// 		printf("counter_1,num:%d\n",g_number);
// 		Sleep(1);
// 		i++;
// 	}
// 	return NULL;
// }

// void *counter_2(void* arg)
// {
// 	int j = 1;
// 	while(j <= (MAX_COUNT / 4))
// 	{
// 		g_number++;
// 		printf("counter_2,num:%d\n",g_number);
// 		Sleep(1);
// 		j++;
// 	}
// 	return NULL;
// }

// int main(int argc, char const *argv[])
// {
// 	pthread_t thread_id_1;
// 	pthread_t thread_id_2;

// 	pthread_create(&thread_id_1,NULL,counter_1,NULL);
// 	pthread_create(&thread_id_2,NULL,counter_2,NULL);

// 	pthread_join(thread_id_1,NULL);
// 	pthread_join(thread_id_2,NULL);
// 	return 0;
// }



// #include <stdio.h>
// #include <pthread.h>
// #include <windows.h>
// #include <time.h>


// void *myThread1(void* arg)
// {
// 	int i;
// 	for (i=0; i<100; i++)
// 	{
// 		printf("This is the 1st pthread,created by zieckey./n");
// 		Sleep(1);//Let this thread to sleep 1 second,and then continue to run
// 	}
// }

// void *myThread2(void* arg)
// {
// 	int i;
// 	for (i=0; i<100; i++)
// 	{
// 		printf("This is the 2st pthread,created by zieckey./n");
// 		Sleep(1);
// 	}
// }

// int main()
// {
// 	int i=0, ret=0;
// 	pthread_t id1,id2;

// 	ret = pthread_create(&id2, NULL, (void*)myThread1, NULL);
// 	if (ret)
// 	{
// 	printf("Create pthread error!/n");
// 	return 1;
// }

// 	ret = pthread_create(&id2, NULL, (void*)myThread2, NULL);
// 	if (ret)
// 	{
// 	printf("Create pthread error!/n");
// 	return 1;
// 	}

// 	pthread_join(id1, NULL);
// 	pthread_join(id2, NULL);
// 	return 0;
// }

// /*线性表的顺序结构*/
// #include <stdio.h>
// #define OK 1
// #define ERROR 0
// #define TRUE 1
// #define FALSE 0
// #define MAXSIZE 20
// typedef int Status;
// typedef int ElemType;

// typedef struct 
// {
// 	ElemType data[MAXSIZE];
// 	unsigned int length;
// }Sqlist;

// /*get element*/

// Status GetElem(Sqlist L,unsigned int i,ElemType *e)
// {
// 	if((L.length == 0)||(i < 1) || (i > L.length))
// 		return ERROR;
// 	*e = L.data[i-1];
// 	return OK;
// }

// /*insert element
// 	param:
// 		L:DATA LIST
// 		i:index
// 		e: data to insert
// */
// Status ListInsert(Sqlist *L,unsigned int i,ElemType e)
// {
// 	unsigned int index;
// 	if(NULL == L)
// 		return ERROR;
// 	//(i > (L->length +1)) 避免空隙
// 	if((L->length >= MAXSIZE) || i < 1 || (i > (L->length +1)))
// 		return ERROR;

// 	if(i <= (L->length))
// 	{
// 		for(index = L->length-1; index >= i-1; index--)
// 		{
// 			L->data[index +1] = L->data[index];
// 		}
// 	}
// 	L->data[i-1] = e;
// 	L->length += 1;
// 	return OK;
// }

// Status DeleteList(Sqlist *L, unsigned int i, ElemType *e)
// {
// 	unsigned int index =0;

// 	if(NULL == L)
// 		return ERROR;
// 	if(i < 1 || i > L->length)
// 		return ERROR;
// 	//i <= L->length
// 	if(NULL != e)
// 		*e = L->data[i-1];

// 	for(index = i; index < L->length; index++)
// 	{
// 		L->data[index-1] = L->data[index];
// 	}

// 	L->length -= 1;
// 	return OK;
// }

// int main(int argc, char const *argv[])
// {
	
// 	Sqlist order_list;
// 	ElemType temp;
// 	unsigned char index = 0;
// 	order_list.length = 0;
	
// 	for (index = 0; index < MAXSIZE;index++)
// 	{
// 		if(ERROR == ListInsert(&order_list,index+1,(ElemType)(index+1+100)))
// 			printf("insert data error\n");
// 	}
// 	printf("----------------------------------\n");
	
// 	DeleteList(&order_list,2,NULL);
// 	//DeleteList(&order_list,2,NULL);

// 	for(index = 0; index < order_list.length;index++)
// 	{
// 		printf("index:%d,value:", index+1);
// 		if(OK == GetElem(order_list,index+1,&temp))
// 			printf("%d\n", temp);
// 		else
// 			printf("%s\n","get error");
// 	}
// 	return 0;
// }

// -----------------------
// index:1,value:101
// index:2,value:103
// index:3,value:104
// index:4,value:105
// index:5,value:106
// index:6,value:107
// index:7,value:108
// index:8,value:109
// index:9,value:110
// index:10,value:111
// index:11,value:112
// index:12,value:113
// index:13,value:114
// index:14,value:115
// index:15,value:116
// index:16,value:117
// index:17,value:118
// index:18,value:119
// index:19,value:120
// 
// 
// 


// /*线性表的链式存储结构*/

// #include <stdio.h>
// #include <stdlib.h>

// #define OK  1
// #define ERROR 0

// typedef int Status;
// typedef int ElemType;

// typedef struct node
// {
// 	ElemType data;
// 	struct node* next_ptr;
// }Node,*LinkList;



// Status get_elem(LinkList list, int i,ElemType *e)
// {
// 	unsigned int index = 1;
// 	LinkList temp = NULL;

// 	if(NULL == list)
// 		return ERROR;
// 	if(i <=0)
// 		return ERROR;
// 	temp=list->next_ptr;

// 	while((temp!= NULL) && (index < i))
// 	{
// 		temp = temp->next_ptr;
// 		index++;
// 	}
// 	if(!temp || index > i)
// 		return ERROR;
// 	*e = temp->data;
// 	return OK;
// }

// Status insert_head(LinkList list,ElemType e)
// {
// 	LinkList temp = NULL;
// 	LinkList node = NULL;
// 	if(NULL == list)
// 		return ERROR;
// 	temp = list;
// 	if(NULL == (node = calloc(1,sizeof(Node))))
// 		return ERROR;
// 	node->data = e;
// 	node->next_ptr = temp->next_ptr;
// 	temp->next_ptr = node;
// 	list->data +=1;
// 	return OK;
// }

// Status insert_tail(LinkList list,ElemType e)
// {
// 	LinkList temp = NULL;
// 	LinkList node = NULL;
// 	if(NULL == list)
// 		return ERROR;
// 	temp = list;

// 	while(temp->next_ptr)
// 	{
// 		temp = temp->next_ptr;
// 	}

// 	if(NULL == (node = calloc(1,sizeof(Node))))
// 		return ERROR;
// 	node->data = e;
// 	node->next_ptr = NULL;
// 	temp->next_ptr = node;
// 	list->data +=1;
// 	return OK;
// }

// /*
// 	param:
// 	1.i:start from 1;
	
// */
// Status insert_elem(LinkList list, int i, ElemType e)
// {
// 	LinkList temp =NULL;
// 	LinkList node =NULL;
// 	unsigned int index = 1;
// 	if (NULL == list)
// 		return ERROR;
// 	if(i <= 0)
// 		return ERROR;
// 	//first node
// 	temp = list;

// 	while(temp->next_ptr && index < (i))
// 	{
// 		temp = temp->next_ptr;
// 		index++;
// 	}
	
// 	if(!temp->next_ptr || index > (i))
// 		return ERROR;
// 	if(NULL == (node = calloc(1,sizeof(Node))))
// 		return ERROR;
// 	node->data = e;
// 	node->next_ptr = temp->next_ptr;
// 	temp->next_ptr = node;
// 	list->data += 1;
// 	return OK;

// }

// Status delete_node(LinkList list,int i,ElemType *e)
// {
// 	LinkList temp = NULL;
// 	unsigned int index = 1;
// 	LinkList node = NULL;
// 	if(NULL == list)
// 		return ERROR;
// 	if(i <= 0)
// 		return ERROR;
	
// 	temp = list;
// 	while(temp->next_ptr && index < i)
// 	{
// 		index++;
// 		temp = temp->next_ptr;
// 	}
// 	if(!temp->next_ptr || i > i)
// 		return ERROR;
	
// 	node =temp->next_ptr;
// 	*e = node->data;
// 	temp->next_ptr = node->next_ptr;
// 	free(node);
// 	list->data -= 1;
// 	return OK;

// }
// Status init_list(LinkList list,ElemType e)
// {
// 	LinkList node = NULL;

// 	if(NULL == list)
// 		return ERROR;
// 	list->data = 0;//list length
// 	list->next_ptr = NULL;
// 	//create first node
// 	if(NULL == (node = calloc(1,sizeof(Node))))
// 		return ERROR;
// 	node->next_ptr = NULL;
// 	node->data = e;
// 	list->next_ptr = node;
// 	list->data += 1;
// }

// void print_list(LinkList list)
// {
// 	LinkList temp =NULL;
// 	unsigned int index = 0;
// 	if(NULL == list)
// 		printf("%s\n", "list error");
// 	temp =list;
// 	printf("list length:%d\n",temp->data);
// 	while(temp->next_ptr)
// 	{
// 		temp = temp->next_ptr;
// 		index++;
// 		printf("index:%d %d\n", index,temp->data);
		
// 	}
// 	printf("%s\n","print list over!" );
// }


// unsigned int get_list_len(LinkList list)
// {
// 	LinkList temp = NULL;
// 	unsigned int count = 0;
// 	if(NULL == list)
// 		return ERROR;

	
// 	temp =list->next_ptr;
// 	while(temp)
// 	{
// 		count++;
// 		temp = temp->next_ptr;
// 	}
// 	return count;
// }

// int main(int argc, char const *argv[])
// {
// 	// header node
// 	Node list;
// 	ElemType temp ;
// 	printf("init_list-------------------\n");
// 	init_list(&list,0);
// 	insert_elem(&list,1,1234);
// 	insert_elem(&list,2,2345);
// 	insert_elem(&list,3,3234);
// 	insert_elem(&list,4,4345);
// 	print_list(&list);
// 	if(OK == delete_node(&list,1,&temp))
// 		printf("delete node data:%d\n",temp);
// 	else
// 		printf("%s\n", "delete error");

// 	// insert_head(&list,3);
// 	// insert_head(&list,2);
// 	// insert_head(&list,1);
// 	// insert_head(&list,0);
// 	// insert_tail(&list,4);
// 	// insert_tail(&list,5);
// 	// insert_tail(&list,6);
	
// 	// print_list(&list);
// 	// printf("insert_elem-------------:\n");
// 	// insert_elem(&list,5,9999);
// 	// print_list(&list);
// 	// insert_elem(&list,7,1234);
// 	// print_list(&list);
// 	// printf("get_elem-------------:\n");
// 	// if(OK == get_elem(&list,2,&temp))
// 	// 	printf("%d\n",temp);
// 	// else
// 	// 	printf("%s\n","get element error" );
	
// 	// printf("delete_node-------------:\n");
// 	// if(OK == delete_node(&list,5,&temp))
// 	// 	printf("delete node data:%d\n",temp);
// 	// else
// 	// 	printf("%s\n", "delete error");


// 	print_list(&list);
// 	printf("list_len:%d,%d\n", get_list_len(&list),list.data);
// 	return 0;
// }


// -----------------------
// init_list-------------------
// list length:5
// index:1 1234
// index:2 2345
// index:3 3234
// index:4 4345
// index:5 0
// print list over!
// delete node data:1234
// list length:4
// index:1 2345
// index:2 3234
// index:3 4345
// index:4 0
// print list over!
// list_len:4,4
// [Finished in 0.3s]




// #include <stdio.h>

// #define OK 1
// #define ERROR 0
// #define MAXSIZE 100

// typedef int Status;
// typedef int ElemType;
// typedef struct 
// {
// 	ElemType data;
// 	int cur;
// }Component,StaticLinkList[MAXSIZE];



// /*double linked list*/
// #include <stdio.h>
// #include <stdlib.h>

// #define OK 1
// #define ERROR 0

// typedef int ElemType;
// typedef int Status;

// typedef struct _node
// {
// 	struct _node *pre_ptr;
// 	ElemType data;
// 	struct _node *next_ptr;
// }Node,*pNode,*pList;


// Status init_list(pList list)
// {
// 	if(NULL == list)
// 		return ERROR;
// 	list->pre_ptr = list;
// 	list->data = 0;
// 	list->next_ptr = list;
// 	return OK;
	
// }

// // Status insert_node_head(pList list,ElemType e)
// // {
// // 	if(NULL == list)
// // 		return ERROR;
// // 	if(i <= 0 || i> list)
// // }


// Status insert_node(pList list, int i, ElemType e)
// {
// 	pNode temp_node = NULL;
// 	unsigned int index = 1;
// 	pNode index_node = NULL;
// 	if(list == NULL)
// 		return ERROR;
// 	if(i <= 0 || i > (list->data + 1))
// 		return ERROR;
// 	index_node = list;//point to header node

// 	while(index_node && index < (i))
// 	{
// 		index_node = index_node->next_ptr;
// 		index++;
// 	}

// 	if(!index_node || index > (i))
// 		return ERROR;
	
// 	if(NULL == (temp_node = calloc(1,sizeof(Node))))
// 		return ERROR;

// 	temp_node->data = e;
// 	temp_node->next_ptr = index_node->next_ptr;
// 	temp_node->pre_ptr = index_node;
// 	index_node->next_ptr = temp_node;
// 	list->data += 1;
// 	return OK;
// }

// // exclude header node	
// void print_list(pList list)
// {
// 	pNode index_node = NULL;
// 	unsigned int index = 1;
	
// 	if(NULL == list)
// 	{
// 		printf("%s\n", "print list err");
// 		return;
// 	}
// 	index_node = list->next_ptr;
	
// 	printf("list len:%d\n", list->data);
// 	while(index_node != list)
// 	{
// 		printf("index:%d,data:%d\n",index,index_node->data);
// 		index++;
// 		index_node = index_node->next_ptr;
// 	}
// }
// //delete node and return delete data
// Status delete_node(pList list, int i, ElemType *e)
// {
// 	unsigned int index = 1;
// 	pNode index_node = NULL;
// 	pNode temp_node = NULL;

// 	if(NULL == list)
// 		return ERROR;
// 	if(i <= 0 ||  list->data <= 0 || i > list->data)
// 		return ERROR;

// 	index_node = list;//frist node
// 	while(index_node && index < (i))
// 	{
// 		index_node = index_node->next_ptr;
// 		index++;  
// 	}	
// 	if(!index_node && index > i)
// 		return ERROR;
// 	temp_node = index_node->next_ptr;
// 	index_node->next_ptr = temp_node->next_ptr;
// 	temp_node->next_ptr->pre_ptr = index_node;
// 	*e = temp_node->data;
// 	free(temp_node);
// 	list->data -= 1;
// 	return OK;
// }

// pNode get_node(pList list, int i)
// {
// 	pNode index_node = NULL;
// 	unsigned int index = 1;

// 	if(NULL == list)
// 		return NULL;
// 	if(i <= 0 || list->data <= 0 || i > list->data)
// 		return NULL;
// 	index_node = list;
// 	while(index_node && index < i)
// 	{
// 		index_node  = index_node->next_ptr;
// 		index++;
// 	}
// 	if(!index_node || index > i)
// 		return NULL;

// 	return index_node->next_ptr;

// }
// int main(int argc, char const *argv[])
// {
// 	Node list;
// 	ElemType tmp;
// 	pNode node = NULL;
// 	init_list(&list);
	
// 	insert_node(&list,1,4);
// 	insert_node(&list,1,5);
// 	insert_node(&list,1,6);
// 	insert_node(&list,4,3);
// 	insert_node(&list,5,2);
// 	insert_node(&list,6,1);
// 	print_list(&list);

// 	if(OK == delete_node(&list,6,&tmp))
// 		printf("delete data:%d\n", tmp);
// 	else
// 		printf("%s\n", "delte data err");

// 	if(OK == delete_node(&list,1,&tmp))
// 		printf("delete data:%d\n", tmp);
// 	else
// 		printf("%s\n", "delte data err");
// 	if(OK == delete_node(&list,1,&tmp))
// 		printf("delete data:%d\n", tmp);
// 	else
// 		printf("%s\n", "delte data err");


// 	printf("\n");
// 	print_list(&list);


// 	if(NULL == (node = get_node(&list,1)))
// 		printf("get node err");
// 	else
// 		printf("get node:%d\n",node->data);	 

// 	if(NULL == (node = get_node(&list,(int)list.data)))
// 		printf("get node err");
// 	else
// 		printf("get node:%d\n",node->data);	 
// 	return 0;
// }

// ------------------------------
// list len:6
// index:1,data:6
// index:2,data:5
// index:3,data:4
// index:4,data:3
// index:5,data:2
// index:6,data:1
// delete data:1
// delete data:6
// delete data:5

// list len:3
// index:1,data:4
// index:2,data:3
// index:3,data:2
// get node:4
// get node:2
// 
// 


/*Stack*/

// #include <stdio.h>

// #define ERROR 0
// #define OK 1
// #define uint unsigned int
// #define MAX_STACK_LEN 100
// typedef int ElemType;
// typedef int Status;


// typedef struct 
// {
// 	ElemType stack_data[MAX_STACK_LEN];
// 	int top;
// }Stack,*pStack;

// //栈顶指针指向最后一个插入的元素()
// //
// Status init_stack(pStack stack)
// {
// 	if(NULL == stack)
// 		return ERROR;
// 	stack->top = -1;
// }

// Status stack_push(pStack stack,ElemType e)
// {
// 	if(NULL == stack)
// 		return ERROR;
	
// 	if(stack->top >=MAX_STACK_LEN -1)
// 		return ERROR;
	
// 	stack->top += 1;
// 	stack->stack_data[stack->top] = e;
// 	return OK;
// }

// Status stack_pop(pStack stack, ElemType *e)
// {
// 	if(NULL == stack)
// 		return ERROR;
// 	if(stack->top < 0)
// 		return ERROR;
	
// 	*e = stack->stack_data[stack->top];
// 	stack->top -= 1;
// 	return OK;
// }

// void  print_stack(pStack stack)
// {
// 	int index = 0;
// 	if(NULL == stack)
// 		return;
// 	if(stack->top < 0)
// 		return;
	
// 	for (index = stack->top; index >= 0; index--)
// 	{
// 		printf("index:%d,value:%d\n",index, stack->stack_data[index]);
// 	}
// 	printf("%s\n","print stack over");
// }


// int main(int argc, char const *argv[])
// {
// 	Stack stack;
// 	ElemType tmp;
// 	int index = -1;
// 	init_stack(&stack);
// 	stack_push(&stack,1);
// 	stack_push(&stack,2);
// 	stack_push(&stack,3);
// 	stack_push(&stack,4);
// 	print_stack(&stack);
// 	if(OK== stack_pop(&stack,&tmp))
// 		printf("pop data:%d\n",tmp);
// 	else
// 		printf("pop err\n");
	
// 	print_stack(&stack);
// 	return 0;
// }
// -----------------------
// index:3,value:4
// index:2,value:3
// index:1,value:2
// index:0,value:1
// print stack over
// pop data:4
// index:2,value:3
// index:1,value:2
// index:0,value:1
// print stack over
// 
// 



// #include <stdio.h>

// #define OK 0
// #define ERROR 1 
// #define MAX_STACK_SIZE 100

// typedef int ElemType;
// typedef int Status;

// typedef enum 
// {
// 	f_stack = 1,
//     s_stack,
// }StackIndex; 

// typedef struct 
// {
// 	ElemType data[MAX_STACK_SIZE];
// 	int top1;
// 	int top2;
// }Stack,*pStack;


// Status init_stack(pStack stack)
// {
// 	if(NULL == stack)
// 		return ERROR;
// 	stack->top1 = MAX_STACK_SIZE;// 向下生长栈顶指针,栈底为data[MAMAX_STACK_SIZE -1]
// 	stack->top2 = -1; // 向上生长栈顶指针,栈底为data[0]
// 	return OK;
// }

// Status stack_push(pStack stack,ElemType e,StackIndex stack_num)
// {
// 	if(NULL == stack)
// 		return ERROR;
	
// 	if((stack->top1-1) == stack->top2)
// 		return ERROR;

// 	if(stack_num == f_stack)
// 		stack->data[--(stack->top1)] = e;
// 	else
// 		stack->data[++(stack->top2)] = e;
// 	return OK;

// }

// void print_stack(pStack stack,StackIndex stack_index)
// {
// 	int index = 0;
// 	if(NULL == stack)
// 		return;
// 	printf("\nprint stack_%d start!\n", (int)stack_index);
// 	if(stack_index == f_stack)
// 	{
// 		if(stack->top1 >= MAX_STACK_SIZE)
// 		{
// 			printf("%s\n", "stack 1 is empty");
// 			return;
// 		}
// 		else
// 		{
// 			for(index =stack->top1; index < MAX_STACK_SIZE;index++)
// 			{
// 				printf("index:%d,data:%d\n",index-stack->top1,stack->data[index]);
// 			}
// 			printf("print stack_%d over!\n", (int)stack_index);
// 			return;
// 		}
			
// 	}
// 	if(stack->top2 < 0)
// 	{
// 		printf("%s\n", "stack 2 is empty");
// 		return;
// 	}
// 	else
// 	{
// 		for(index = stack->top2; index >= 0;index--)
// 		{
// 			printf("index:%d,data:%d\n",stack->top2-index,stack->data[index]);
// 		}
// 		printf("print stack_%d over!\n", (int)stack_index);
// 		return;
// 	}
	
// }

// Status stack_pop(pStack stack,ElemType *e, StackIndex stack_num)
// {
// 	if(NULL == stack)
// 		return ERROR;
// 	if(stack_num == f_stack)
// 	{
// 		if(stack->top1 >= MAX_STACK_SIZE)
// 			return ERROR;
// 		*e = stack->data[stack->top1];
// 		stack->top1 += 1;
// 		return OK;
// 	}
// 	else
// 	{
// 		if(stack->top2 < 0)
// 			return ERROR;
// 		*e = stack->data[stack->top2];
// 		stack->top2 -= 1;
// 		return OK;
// 	}
// 	return ERROR;
// }

// int main(int argc, char const *argv[])
// {
// 	Stack stack;
// 	ElemType tmp;
// 	int i;
// 	if(ERROR == init_stack(&stack))
// 		printf("%s\n", "init stack err");

// 	// stack_push(&stack,1,f_stack);
// 	// stack_push(&stack,2,f_stack);
// 	// stack_push(&stack,3,f_stack);
// 	// stack_push(&stack,4,f_stack);

// 	// stack_push(&stack,1,s_stack);
// 	// stack_push(&stack,2,s_stack);
// 	// stack_push(&stack,3,s_stack);
// 	// stack_push(&stack,4,s_stack);
// 	// stack_push(&stack,5,s_stack);

// 	// print_stack(&stack,f_stack);
// 	// print_stack(&stack,s_stack);
	
// 	// if(ERROR == stack_pop(&stack,&tmp,f_stack))
// 	// 	printf("pop stack err\n");
// 	// else
// 	// 	printf("pop stack_%d,data:%d\n",f_stack,tmp);

// 	// if(ERROR == stack_pop(&stack,&tmp,s_stack))
// 	// 	printf("pop stack err\n");
// 	// else
// 	// 	printf("pop stack_%d,data:%d\n",s_stack,tmp);
// 	#if 0
// 	for(i = 0; i < MAX_STACK_SIZE; i++)
// 	{
// 		stack_push(&stack,(ElemType)i,f_stack);
// 	}
// 	#endif
// 	print_stack(&stack,f_stack);
// 	print_stack(&stack,s_stack);

// 	return 0;
// }

/*linked stack*/

// #include <stdio.h>
// #include <stdlib.h>

// #define OK 0
// #define ERROR 1
// #define  uint unsigned int 

// typedef int Status;
// typedef int ElemType;


// typedef struct _node
// {
// 	ElemType data;
// 	struct _node * next_ptr;
// }Node,*pNode;

// typedef struct 
// {
// 	pNode top;
// 	unsigned int len;
// }Stack,*pStack;

// Status stack_push(pStack stack, ElemType e)
// {
// 	pNode temp_node = NULL;
// 	if(NULL == stack)
// 		return ERROR;
// 	if(NULL == (temp_node=calloc(1,sizeof(Node))))
// 		return ERROR;
// 	temp_node->data = e;
// 	temp_node->next_ptr = stack->top;
// 	stack->top = temp_node;
// 	stack->len += 1;
// 	return OK;
// }

// Status stack_pop(pStack stack, ElemType *e)
// {
// 	pNode temp_node = NULL;
// 	if(NULL == stack)
// 		return ERROR;
// 	*e = stack->top->data;
// 	temp_node =stack->top ;
// 	stack->top = stack->top->next_ptr;
// 	free(temp_node);
// 	stack->len -= 1;
// 	return OK;
// }
// void  print_stack(pStack stack)
// {
// 	pNode temp_node = NULL;
// 	int index = 1;
// 	if(NULL == stack)
// 	{
// 		printf("print statck err\n");
// 		return;
// 	}
		
// 	if(NULL == stack->top)
// 	{
// 		printf("stack is empty\n");
// 		return;
// 	}
		
// 	printf("\nstack len:%d\n",stack->len);
// 	temp_node = stack->top;
// 	while(temp_node)
// 	{
// 		printf("index:%d,data:%d\n",index,temp_node->data);
// 		temp_node = temp_node->next_ptr;
// 		index++;
// 	}

// }
// Status init_stack(pStack stack)
// {
// 	if(NULL == stack)
// 		return ERROR;
// 	stack->top = NULL;
// 	stack->len = 0;
// }

// int main(int argc, char const *argv[])
// {
// 	Stack stack;
// 	ElemType tmp;
// 	int index;
// 	int tmp_index =0;
// 	if(ERROR == init_stack(&stack))
// 		printf("%s\n", "init_stack err");
// 	print_stack(&stack);
	
// 	stack_push(&stack,123);
// 	stack_push(&stack,223);
// 	stack_push(&stack,323);
// 	print_stack(&stack);
// 	tmp_index = stack.len;
// 	for(index = 1;index <=tmp_index ;index++)
// 	{
// 		printf("pop stack:index %d,data:",index);
// 		if(ERROR == stack_pop(&stack,&tmp))
// 			printf("err\n");
// 		else
// 			printf("%d\n",tmp);
// 	}
// 	printf("\n");
// 	print_stack(&stack);
// 	return 0;
// }
// --------------------------------
// stack is empty
// stack len:3
// index:1,data:323
// index:2,data:223
// index:3,data:123
// pop stack:index 1,data:323
// pop stack:index 2,data:223
// pop stack:index 3,data:123

// stack is empty
// [Finished in 0.3s]



// #include <stdio.h>
// int main(int argc, char const *argv[])
// {
// 	int a[40] = {0};
// 	int index = 0;
// 	a[0] = 0;
// 	a[1] = 1;
// 	for( index= 2; index < 40; index++)
// 	{
// 		a[index] =a[index-1] + a[index-2];
// 	}
// 	for (index = 0; index < 40; ++index)
// 	{
// 		/* code */
// 		printf("index:%d,data:%d\n",index,a[index]);
// 	}
// 	return 0;
// }
// -----------------------------
// index:0,data:0
// index:1,data:1
// index:2,data:1
// index:3,data:2
// index:4,data:3
// index:5,data:5
// index:6,data:8
// index:7,data:13
// index:8,data:21
// index:9,data:34
// index:10,data:55
// index:11,data:89
// index:12,data:144
// index:13,data:233
// index:14,data:377
// index:15,data:610
// index:16,data:987
// index:17,data:1597
// index:18,data:2584
// index:19,data:4181
// index:20,data:6765
// index:21,data:10946
// index:22,data:17711
// index:23,data:28657
// index:24,data:46368
// index:25,data:75025
// index:26,data:121393
// index:27,data:196418
// index:28,data:317811
// index:29,data:514229
// index:30,data:832040
// index:31,data:1346269
// index:32,data:2178309
// index:33,data:3524578
// index:34,data:5702887
// index:35,data:9227465
// index:36,data:14930352
// index:37,data:24157817
// index:38,data:39088169
// index:39,data:63245986
// 

// #include <stdio.h>

// int main(int argc, char const *argv[])
// {
// 	int a[30] = {0};
// 	int index = 0;
// 	int sum = 0;
// 	a[0] = 1;
// 	sum += a[0];
// 	for(index = 1; index < 30;index++)
// 	{
// 		a[index] = a[index-1]*2;
// 		sum += a[index];
// 	}
// 	for(index = 0; index < 30;index++)
// 	{
// 		printf("index:%d,data:%d\n",index,a[index]);
// 	}
// 	printf("sum:%d\n", sum);
// 	return 0;
// }





// #include <stdio.h>

// int fibonacci(int num)
// {
// 	int ret = 0;
// 	if(num < 2)
// 		return num ==0 ? 0 : 1;

	
// 	return fibonacci(num -1)+fibonacci(num -2);
// }

// int main(int argc, char const *argv[])
// {
// 	int num;
// 	num = 39;
// 	printf("%d\n", fibonacci(num));	
// 	return 0;
// }
// --------------------
// 63245986




// #include <stdio.h>
// #include <stdlib.h>
// #define OK 0
// #define ERROR 1
// #define MAX_QUEUE_LEN 100

// typedef int Status;
// typedef int ElemType;
// typedef struct
// {
// 	ElemType data[MAX_QUEUE_LEN];
// 	unsigned int len;
// }Queue,*pQueue;


// Status init_queue(pQueue queue)
// {
// 	if(NULL == queue)
// 		return ERROR;
// 	queue->len = 0;
// }
// Status in_queue(pQueue queue,ElemType e)
// {
// 	if(NULL == queue)
// 		return ERROR;
// 	if(queue->len >= MAX_QUEUE_LEN-1)
// 		return ERROR;
// 	queue->data[queue->len] = e;
// 	queue->len +=1;
// 	return OK;
// }

// Status out_queue(pQueue queue,ElemType *e)
// {
// 	unsigned int index = 0;
// 	if(NULL == queue)
// 		return ERROR;
// 	if(queue->len < 1)
// 		return ERROR;
// 	*e = queue->data[0];

// 	for(index = 0;index < queue->len;index++)
// 	{
// 		queue->data[index] = queue->data[index+1];
// 	}
// 	queue->len -= 1;
// 	return OK;
// }

// void print_queue(pQueue queue)
// {
// 	unsigned int index = 0;
// 	if(NULL == queue)
// 		return;
// 	printf("%s\n", "print queue start:");
// 	if(!queue->len)
// 		printf("%s\n", "empty quque");
// 	for(index = queue->len;index > 0;index--)
// 	{
// 		printf("index:%d,data:%d\n",(index),
// 			queue->data[index-1]);
// 	}
// 	printf("%s\n", "print queue over!");	

// }

// int main(int argc, char const *argv[])
// {
// 	Queue queue;
// 	ElemType tmp;
// 	if(ERROR == init_queue(&queue))
// 		return ERROR;
// 	print_queue(&queue);

// 	in_queue(&queue,1);
// 	in_queue(&queue,2);
// 	in_queue(&queue,3);
// 	in_queue(&queue,4);
// 	in_queue(&queue,5);
// 	print_queue(&queue);

// 	if(OK== out_queue(&queue,&tmp))
// 		printf("out queue:%d\n",tmp);
// 	else
// 		printf("%s\n","out queue err");
// 	print_queue(&queue);

// 	return 0;
// }

// -----------------------
// print queue start:
// empty quque
// print queue over!
// print queue start:
// index:5,data:5
// index:4,data:4
// index:3,data:3
// index:2,data:2
// index:1,data:1
// print queue over!
// out queue:1
// print queue start:
// index:4,data:5
// index:3,data:4
// index:2,data:3
// index:1,data:2
// print queue over!





// #include <stdio.h>
// #include <stdlib.h>

// #define OK 0
// #define ERROR 1

// #define MAX_QUEUE_LEN 5

// typedef int Status;
// typedef int ElemType;


// typedef struct 
// {
// 	ElemType data[MAX_QUEUE_LEN];
// 	int front;
// 	int rear;
// }CycleQueue,*pCycleQueue;


// Status init_cqueue(pCycleQueue c_queue)
// {
// 	if(NULL == c_queue)
// 		return ERROR;
// 	c_queue->front =0;
// 	c_queue->rear = 0;
// }

// Status is_empty(pCycleQueue c_queue)
// {
// 	if(NULL == c_queue)
// 	{
// 		printf("%s\n", "queue err");
// 		return ERROR;
// 	}
// 	if(c_queue->rear == c_queue->front)
// 		return  OK;
// 	return ERROR;	
// }

// Status is_full(pCycleQueue c_queue)
// {
// 	if(c_queue ==NULL)
// 	{
// 		printf("%s\n", "queue err");
// 		return ERROR;
// 	}
// 	if(((c_queue->rear+1)% MAX_QUEUE_LEN) == c_queue->front)
// 		return OK;
// 	return ERROR;
// }

// int get_cqueue_len(pCycleQueue c_queue)
// {
// 	if(OK == is_empty(c_queue))
// 		return -1;
// 	return ((c_queue->rear - c_queue->front + MAX_QUEUE_LEN) % MAX_QUEUE_LEN);
// }

// Status in_cqueu(pCycleQueue c_queue,ElemType e)
// {
// 	if(NULL == c_queue)
// 		return ERROR;
// 	if(OK == is_full(c_queue))
// 		return ERROR;
// 	c_queue->data[c_queue->rear] = e;
// 	c_queue->rear = (c_queue->rear + 1)%MAX_QUEUE_LEN;
// 	return OK;
// }

// Status out_cqueue(pCycleQueue c_queue,ElemType *e)
// {
// 	if(NULL == c_queue)
// 		return ERROR;
// 	if(OK == is_empty(c_queue ))
// 		return ERROR;
// 	*e = c_queue->data[c_queue->front];
// 	c_queue->front = (c_queue->front +1) % MAX_QUEUE_LEN;
// 	return OK;
// }


// void print_cqueue(pCycleQueue c_queue)
// {
// 	int index =0;
// 	if(get_cqueue_len(c_queue) > 0)
// 	{	
// 		printf("%s\n", "print c_queue start!");
// 		if(c_queue->rear > c_queue->front)
// 		{
// 			for(index = c_queue->front;index < c_queue->rear;index++)
// 				printf("index:%d,data:%d\n",index,c_queue->data[index]);
// 		}
// 		else
// 		{
// 			for(index = c_queue->front;index < MAX_QUEUE_LEN;index++)
// 				printf("index:%d,data:%d\n",index,c_queue->data[index]);
// 			for(index = 0; index < c_queue->rear;index++)
// 				printf("index:%d,data:%d\n",index,c_queue->data[index]);
// 		}
// 		printf("%s\n", "print c_queue over!");
// 	}
// 	else
// 		printf("%s\n", "c_queue is empty");

// }
// int main(int argc, char const *argv[])
// {
// 	CycleQueue queue;
// 	ElemType tmp;
// 	if(ERROR == init_cqueue(&queue))
// 	{
// 		printf("%s\n", "init queu ERROR");
// 		return 0;
// 	}
// 	print_cqueue(&queue);
	
// 	in_cqueu(&queue,1);
// 	in_cqueu(&queue,2);
// 	in_cqueu(&queue,3);
// 	print_cqueue(&queue);
	
// 	if(OK == out_cqueue(&queue,&tmp))
// 		printf("out queue:%d\n",tmp);
// 	else
// 		printf("out queue err\n");
// 	print_cqueue(&queue);
	
// 	printf("current queue len:%d\n",get_cqueue_len(&queue));
// 	in_cqueu(&queue,4);
// 	in_cqueu(&queue,5);
// 	in_cqueu(&queue,6);
// 	printf("current queue len:%d\n",get_cqueue_len(&queue));
// 	print_cqueue(&queue);
// 	return 0;
// }


// -----------------------------------------------
// c_queue is empty
// print c_queue start!
// index:0,data:1
// index:1,data:2
// index:2,data:3
// print c_queue over!
// out queue:1
// print c_queue start!
// index:1,data:2
// index:2,data:3
// print c_queue over!
// current queue len:2
// current queue len:4
// print c_queue start!
// index:1,data:2
// index:2,data:3
// index:3,data:4
// index:4,data:5
// print c_queue over!
// 
// 
// 
// 
// 

typedef struct 
{
	const char b[10];
}A,*pA;

 A a;
 
int main(int argc, char const *argv[])
{
	a.b[10] = "xptd";
	printf("%s\n", a.b);
	return 0;
}
