#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <time.h>

#define OK 0
#define ERROR 1

#define SRC_PATCH "I:\\123.nc"
#define DES_PATCH "123.nc"
#define LOG_FILE  "log.log"

typedef int Status;
FILE *log_file = NULL;

Status copy_file(FILE* src,FILE *des)
{
	char ch;
	if(NULL == src || NULL == des)
		return ERROR;

	fseek(src,0L,SEEK_SET);
	fseek(des,0L,SEEK_SET);

	while((ch = getc(src)) != EOF)
		putc(ch,des);
	fflush(des);
	/* fclose(src);
	fclose(des); */
	return OK;
}

Status compare_file(FILE*src,FILE *des)
{
	char ch;
	char src_buffer[512] = {0};
	char des_buffer[512] = {0};

	long src_file_len = 0;
	long des_file_len = 0;
	
	if(NULL == src || NULL== des)
		return ERROR;
	
	fseek(src,0L,SEEK_SET);
	fseek(des,0L,SEEK_SET);

	fseek(src,0L,SEEK_END);
	fseek(des,0L,SEEK_END);

	src_file_len = ftell(src);
	des_file_len = ftell(des);
	fseek(src,0L,SEEK_SET);
	fseek(des,0L,SEEK_SET);
	
	fprintf(log_file,"src_file_len:%ld\n", src_file_len);
	fprintf(log_file,"des_file_len:%ld\n", des_file_len);

	if(src_file_len != des_file_len)
		return ERROR;
		
	/* while(ch=fgetc(src) != EOF)
	{
		if(ch != fgetc(des))
			return ERROR;
	} */
	
	
	while(!feof(src) && !feof(des))
	{
		memset(src_buffer,0,sizeof(src_buffer)/sizeof(src_buffer[0]));
		memset(des_buffer,0,sizeof(src_buffer)/sizeof(src_buffer[0]));

		fgets(src_buffer,sizeof(src_buffer)/sizeof(src_buffer[0]),src);
		fgets(des_buffer,sizeof(src_buffer)/sizeof(src_buffer[0]),des);
		
		if(strcmp(src_buffer,des_buffer))
			return ERROR;
	}
	return OK;
}


int main(int argc, const char *argv[])
{
	FILE *src_file,*des_file;
	unsigned int test_cout = 0;

	if(NULL == (log_file = fopen(LOG_FILE,"ab+")))
	{
		printf("open log file %s err\n",LOG_FILE);
		goto _err_1;
	}

	
	while(1)
	{
		if(NULL == (src_file = fopen(SRC_PATCH,"rb")))
		{
			printf( "open src file %s err\n",SRC_PATCH);
			goto _err_2;
		}
		if(NULL == (des_file = fopen(DES_PATCH,"wb+")))
		{
			printf("open des file %s err\n",DES_PATCH);
			goto _err_3;
		}

		if(OK == copy_file(src_file,des_file))
		{
			test_cout++;
			fprintf(log_file,"copy file %s to %s success ,copy count:%d\n",
				 SRC_PATCH,DES_PATCH,test_cout);
				 
			if(OK == compare_file(src_file,des_file))
				fprintf(log_file,"compare file %s to %s success\n",
				 SRC_PATCH,DES_PATCH);
			else
			{
				fprintf(log_file,"compare file %s to %s failed\n",
				 SRC_PATCH,DES_PATCH);
				 while(1);
				 break;
			}
				
			remove(des_file);
			fclose(des_file);
		    fclose(src_file);
			fflush(log_file);	
		}
		else
		{
			fprintf(log_file,"copy file %s to %s failed\n",
				 SRC_PATCH,DES_PATCH);
				 break;
		}
			
	}

_ret:
	fclose(des_file);
_err_3:
	fclose(src_file);
_err_2:
	fclose(log_file);
_err_1:
	return 0;	
}

