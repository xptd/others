#include <stdio.h>

#define OK     1
#define ERROR  0

#define TRUE   1
#define FALSE  0
#define SRC_FILE "NK.nb0"

#define FIRMWARE_LIMIT_OFFSET (0xf0)
#define NK_VERSION_OFFSET	(0x100)		

#define VERSION_MAJOR (1) 
#define VERSION_MAJOR_MINOR (0) 
#define VERSION_MAJOR_BUILD (0) 

#define NK_SUFFIX ".nb0"

typedef int status;

typedef enum 
{
	NK105E_3Axis = 1,
	NK105E_4Axis,
	NK260A1,
	NK280BA1,
	UNKNOWN,
}NK_TYPE;

const char* nk_name_prefixs[5] = {
	"unknown",
	"NK105E-NK-R"
};

void print_help(void)
{
	printf("****************welcome to wince tool*****************\r\n");
	printf("\t\tplease choose platform:\r\n");
	printf("\t\t1.NK105E(3_Axis)\r\n");
	printf("\t\t2.NK105E(4_Axis)\r\n");
	printf("\t\t3.NK260 A1\r\n");
	printf("\t\t4.NK280B A1\r\n");
	
	printf("******************************************************\r\n");
}

status modifled_nk105e_3Axis(void)
{
	char *nk_name = "NK105E-NK-R";
	
	return OK;
}

int main(int argc, const char* argv[])
{
	
	NK_TYPE nk_type = UNKNOWN;

	print_help();
	scanf("%d",&nk_type);
	
	printf("selected paltform type:");

	switch(nk_type)
	{
		
		case NK105E_3Axis: 
			printf("NK105E(3_Axis)\r\n");
		break;
		
		case NK105E_4Axis:
			printf("NK105E_4Axis\r\n");
		break;
		
		case NK260A1:
			printf("NK260 A1\r\n");
		break;
		
		case NK280BA1:
			printf("NK280B A1\r\n");
		break;
		
		default:
			printf("error\r\n");
			
	}
	
	return 0;
}
