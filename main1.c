#include "preprocessor.h"
int main()
{
	if(comment_remove("inputfile.c","temp1.c")!=0)
	{
		printf("comment removal failed\n");
		return 1;
	}
	
	if(header_includes("temp1.c","temp2.c")!=0)
        {
	
		printf("header inclusion  failed\n");
		return 1;
	}
	
	printf("comment removal and file inclusion successfully\n");
	return 0;
}
