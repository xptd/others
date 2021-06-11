#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define ERROR 1

#define SRC_FILE "NK.nb0"

#define FIRMWARE_LIMIT_OFFSET (0xf0)
#define NK_VERSION_OFFSET	(0x100)		

#define BF_SIZE 16
#define DES_FILE "NK280B-A1-TEST-NK-R1.1.1.nb0"
int main(int argc, const char* argv[])
{
	FILE * fp = NULL;

	const char firmware[4] = {0x01,0x02,0x80,0xB1};
	const char version[4] = {0xA8,0x01,0x01,0x01};
	unsigned char *buffer = NULL;
	unsigned char i = 0;
	
	remove(DES_FILE);

	if(NULL == (fp = fopen(SRC_FILE,"rb+")))
	{
		printf("open file error\r\n");	
		return ERROR;
	}
	
	buffer = (unsigned char *)malloc(BF_SIZE);

	if(NULL == buffer)
	{
		printf("malloc error\n");
		goto _error;
	}

	memset(buffer,0,BF_SIZE);

	fseek(fp,FIRMWARE_LIMIT_OFFSET,SEEK_SET);
	fread(buffer,BF_SIZE,1,fp);

	for (i = 0; i < sizeof(firmware) / sizeof(firmware[0]);i++)
	{
		buffer[i] = firmware[i];
	}
	fseek(fp,FIRMWARE_LIMIT_OFFSET,SEEK_SET);
	fwrite(buffer,BF_SIZE,1,fp);
	fflush(fp);

	memset(buffer,0,BF_SIZE);
	fseek(fp,NK_VERSION_OFFSET,SEEK_SET);
	fread(buffer,BF_SIZE,1,fp);
	for (i = 0; i < sizeof(version) / sizeof(version[0]);i++)
	{
		buffer[i] = version[i];
	}
	fseek(fp,NK_VERSION_OFFSET,SEEK_SET);
	fwrite(buffer,BF_SIZE,1,fp);
	fflush(fp);

#if 0
	for(i = 0; i < BF_SIZE;i++)
	{
		printf("%02x ", *buffer);
		buffer++;
	}

	printf("\n");
#endif

	fclose(fp);
	free(buffer);
	rename(SRC_FILE,DES_FILE);

	remove(SRC_FILE);
	return OK;
_error:
	fclose(fp);
	return ERROR;
}
