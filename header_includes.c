#include "preprocessor.h"

int header_includes(const char *input, const char *output)
{
	FILE *fp1,*fp2,*fp3; 
        char str[200]; 
        char filename[100]; 
         int ch,i;
        fp1=fopen(input,"r");
	if(fp1==NULL)
	{
		printf("unable to open input file\n");
		return 1;
	}
	fp2=fopen(output,"w");
	if(fp2==NULL)
	{
		fclose(fp1);
		return 1;
	}
	while(fgets(str,sizeof(str),fp1)!=NULL)
	{
		if(strstr(str,"#include <")!=NULL) 
		{ 
			i=0;
			char *ptr=strchr(str,'<');
			if(ptr!=NULL)
			{
				ptr++;
				    while(*ptr!='>' && *ptr!='\0')
				    {
					    filename[i++]=*ptr++;
					}
				    filename[i]='\0';
				    fp3=fopen(filename,"r");
				    if(fp3==NULL)
				    {
					    printf("unable to open header file\n");
					    fclose(fp1);
					    fclose(fp2);
					    return 1;
				    }
				    while((ch=fgetc(fp3))!=EOF)
				    {
					    fputc(ch,fp2); 
					}
			
			fclose(fp3);
		}
	}
	else
	{
		fputs(str,fp2);// if current line does not containes #include< the program copies the original line into the output file,fputs write complete string
	}
	}
	  fclose(fp1);
	  fclose(fp2);
	  return 0;
	}


