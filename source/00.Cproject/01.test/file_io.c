#include <stdio.h>
#include <stdlib.h>

#define LOG "log.txt"

void test(FILE *fp)
{

	fprintf(fp,"hello xptd\r\n"); 
	fprintf(fp,"hello xptd\r\n"); 
	fprintf(fp,"hello xptd\r\n"); 
	fprintf(fp,"hello xptd\r\n"); 
}


int main(int argc, char const *argv[])
{
	FILE *log = fopen(LOG,"a+");

	if(NULL == log)
	{
		printf("open log file error\r\n");
		return 1;
	}

	test((FILE *)log);
	fclose(log);
	return 0;
}
