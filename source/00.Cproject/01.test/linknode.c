#include <stdio.h>

#if 0
/*
1.头指针与首节点：
	1.头指针只是一个指针变量(4字节大小，类型是struct node *)，头节点是链表的第一个节点(sizeof(struct node)大小)；
	2.通常的链表实现是：定义一个头指针，头指针指向链表的第一个节点(头节点)，然后第一个节点指针指向下一个节点....
2.头节点：
	1.头指针指向链表的首个有实际意义的节点；
	2.把头指针指向的第一个节点作为头节点使用
	3.头节点：
		1.紧跟在头指针后面
		2.头节点的数据部分是空的（有时也会存储链表长度）指针部分指向第一个有效节点；
		3.头节点不是必须的，但是加上之后方便操作（操作统一化不需要对第一个有效节点做特殊处理）；
*/

/*定义节点*/
struct node{
	int data;
	struct node * pNext;
};

/*
1.申请堆内并检查申请内存是否成功；
2.申请的空间大小为节点结构体类型规定大小，刚申请到的内存空间就是一个新的节点；
3.清除刚申请到的内存空间---堆内存刚申请到的是脏内存块；
4.向新节点写入数据；
5.初始化指针域为NULL:----默认无后继--也不知道后继是什么；

	create a node 
	ret:nodr addr
*/

struct node* create_node(int value)
{
	struct node * p =(struct node*)malloc(sizeof(struct node));
	
	if(NULL == p)
	{
		printf("create node error\r\n");
		return NULL;
	}
	
	memset(p, 0, sizeof(struct node));
	
	p->data = value;
	p->pNext = NULL;
	return p;
}


/*
1.创建一个只有一个节点的链表；
	int main(int argc, const char *argv[])
	{
		
		struct node* pList = NULL;
		pList = create_node(2);
		printf("%d\r\n",pList->data);//2;
		return 0;
	}
*/

/*
在链表的尾部插入一个节点；
1.创建一个新节点（待插入的节点）；
2.找到当前的链表的尾节点（指针域为NULL）；
3.将当前链表的尾节点的指针域指向新节点，更新新节点的指针域为NULL（创建时默认为NULL）；	
*/

void insert_tail(struct node * pList, struct node* node)
{
	struct node* p = pList;
	
	while(NULL != p->pNext)
	{
		p = p->pNext;
	}
	p->pNext = node;
}
/*
在链表头部插入一个新节点：
	1.新节点的pNext指针指向之前的首节点（第一个有效节点，下同）
	2.头节点的pNext指针指向新节点；
*/

void insert_head(struct node* plist, struct node* node)
{
	node->pNext = plist->pNext;
	plist->pNext = node;	
}

/*
遍历链表：
1.指针p访问第一个有效节点并判断此节点是否为尾节点（指针域指向NULL），取出数据，指针p移动到下一节点
2.判断节点是否为尾节点，取出数据，继续下移；
3.循环到尾节点，停止遍历；


void print_list(struct node * plist)
{
	struct node* p = plist->pNext;
	unsigned int index = 0;
	printf("print list-----------------------start\r\n");
	
	while(NULL != p->pNext)
	{
		printf("index:%d,value:%d\r\n",index,p->data);
		p = p->pNext;
		index++;
	}
	printf("index:%d,value:%d\r\n",index,p->data);
	
	printf("print list-----------------------end\r\n");
}
*/
void print_list(struct node * plist)
{
	struct node* p = plist;
	unsigned int index = 0;
	
	printf("print list-----------------------start\r\n");
	while(NULL != p->pNext)
	{
		p = p->pNext;
		printf("index:%d,value:%d\r\n",index,p->data);
		index++;
	}
	
	printf("print list-----------------------end\r\n");
}

unsigned int get_list_len(const struct node* pList)
{
	struct node* p = pList;
	unsigned int count = 0;
	
	if(NULL != p)
	{
		count += 1;
		while(NULL != p->pNext){
			count++;
			p = p->pNext;
		}
		return count;
	}
	else
	{
		return 0;
	}
	
}

/*
删除节点：
1.知道节点的次序删除某个节点（比如指定删除第2个节点）；
2.删除指定数据域指的节点（遍历链表查找是否有包含指定数据的节点）；
3.如果节点存在：
	1.节点不是尾节点：
		1.将待删除节点的pNext值赋值给新节点的pNext
		2.修改待删除节点前一个节点的指针域指向新节点；
		3.free()；内存释放
	2.节点是尾节点：
		1.修改待删除节点前一个节点的指针域指向NULL(新的尾节点)；
		2..free()；内存释放
*/

int delete_node(struct node* plist, int data)
{

	struct node* p = plist;
	struct node* pPrev = NULL;
	
	while(NULL != p->pNext)
	{
		pPrev = p;
		p = p->pNext;
		
		if(p->data == data)
		{
			if(NULL == p->pNext)
			{
				pPrev->pNext = NULL;
				free(p);
			}
			else
			{
				pPrev->pNext = p->pNext;
				free(p);
			}
			return 0;
		}
	}
	printf("not find node\r\n");
	return 1;
}



/*
链表逆序：
1.依次取出原始列表的每个节点（遍历链表，如果没有有效节点、或者只有一个有效节点则不需要逆序操作）；
2.取出的数据每次都从头部插入到新链表中，即可实现逆序；
3.保持链表的头指针、头节点不变，原链表的第一个有效节点在逆序之后就变成了尾节点，所以要将其指针域
	赋值为NULL--=特殊处理,y原始链表的尾节点也需要特殊处理（遍历时判断条件限制了对该节点进行处理）；
4.引入辅助变量pBack：指向当前节点的后一个节点---协助完成遍历；
  即链表逆序 = 遍历+头插入；
*/


void  reverse_list(struct node* plist)
{
	struct node* p = plist->pNext;
	struct node* pBack = NULL;
	
	if ((NULL == p) || (NULL == p->pNext))
		return;
		
	while(NULL != p->pNext)
	{
		pBack = p->pNext;
		
		if(p == plist->pNext)
		{
			p->pNext = NULL;
		}
		else
		{
			p->pNext = plist->pNext;
		}
		plist->pNext = p;
		p = pBack;
	}
	insert_head(plist,p);
}





int main(int argc, const char *argv[])
{
	
	struct node* pList = NULL;
	pList = create_node(0);
			
	insert_tail(pList,create_node(3));
	insert_tail(pList,create_node(4));
	insert_tail(pList,create_node(5));
	
	insert_head(pList,create_node(2));
	insert_head(pList,create_node(1));
	
	printf("list len:%d\r\n",get_list_len(pList));
	print_list(pList);
	delete_node(pList,5);
	printf("list len:%d\r\n",get_list_len(pList));
	print_list(pList);
	
	insert_tail(pList,create_node(6));
	insert_tail(pList,create_node(7));
	insert_tail(pList,create_node(8));

	delete_node(pList,2);
	printf("list len:%d\r\n",get_list_len(pList));
	print_list(pList);
	
	
	reverse_list(pList);
	printf("list len:%d\r\n",get_list_len(pList));
	print_list(pList);
	return 0;
}
#endif

/*

单链表：
	优点：解决了数组不容易扩展、不容易插入元素的问题同时有利于利用碎片化内存；
	缺点：只能单向移动，不利于复杂算法的实现，只能访问当前节点以及后节点不能访问之前的节点；
双链表：
1.双链表并不是有两条链表而是一条链表中有两个遍历方向(向前、向后都可以)---双向链表；
2.链表节点：
	单链表：数据域+指针域（指向下一个节点pNext）；
	双链表：数据域+2*指针域（一个指向前一个节点pPrev，一个指向后一个节点pNext）,头节点的前向指针指向NULL，
		尾节点的后向指针指向NULL；
	
*/

/*定义双链表的链表节点*/

struct node
{
	int data;
	struct node* pPrev;
	struct node* pNext;
};

/*创建节点*/

struct node* create_node(int dat)
{

	struct node* p = (struct node *)malloc(sizeof(struct node));
	
	if(NULL == p)
	{	
		printf("create_node error\r\n");
		return NULL;
	}
	
	memset(p, 0, sizeof(struct node));
	
	p->pPrev = NULL;
	p->pNext = NULL;
	p->data = dat;
	
	return p;
	
}
int main(int argc , const char *argv[])
{
	printf("hello xptd\r\n");
	return 0;
}


