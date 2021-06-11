/*
* @Author: xptd
* @Date:   2020-03-07 18:12:10
* @Last Modified by:   xptd
* @Last Modified time: 2020-03-07 18:32:35
* @For: 
*/
#include <stdio.h>
int fib(num)
{
	if (num < 0)
		return 0;
	if(num < 2)
		return num?1:0;
	return fib(num -1)+fib(num-2);
}

// int main(int argc, char const *argv[])
// {
// 	int index = 0;
// 	for(index = 0; index < 39;index++)
// 		printf("%d\n", fib(index));
// 	return 0;
// }

// ---------------
// [Finished in 4.1s]

int main(int argc, char const *argv[])
{
	int index = 0;
	for(index = 38; index >=0;--index)
		printf("%d\n", fib(index));
	return 0;
}
------------------
[Finished in 2.3s]