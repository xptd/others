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





int main(int argc, char const *argv[])
{
	int index = 0;
	while(1)
	{
		printf("%s\n", "while");

		switch(index)
		{
			case 1:
				printf("%s","1");
			break;
			case 2:
				printf("%s","2");
			break;
			case 4:
			break;
		}
		index++;
	}
	return 0;
}