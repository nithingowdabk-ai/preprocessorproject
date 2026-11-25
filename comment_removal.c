#include "preprocessor.h"
int comment_remove(const char *input,const char *output)
{
	FILE *fp1,*fp2;  
	int ch,next;   
	int state=0;  
        fp1=fopen(input,"r");
	if(fp1==NULL)   
	{
		printf("unable to open inputfile\n");
		return 1;
	}
	fp2=fopen(output,"w");
	if(fp2==NULL)   
	{
		fclose(fp1);
		return 1;
	}
	while((ch=fgetc(fp1))!=EOF)
	{
		if(state==0)
	{
		if(ch=='/')
		{
			next=fgetc(fp1);
			if(next=='/')
				state=1; 
				else if(next=='*')
					state=2;  
				else
				{
					fputc(ch,fp2); 
					if(next!=EOF)
						ungetc(next,fp1);

				}
		}
		else
			fputc(ch,fp2);
	}
	else if(state==1)
	{
		if(ch=='\n') 
		{
			fputc('\n',fp2); 
				state=0;

		}
	}
	else if(state==2)
	{
		if(ch=='*')
		{
			next=fgetc(fp1);
			if(next=='/')
				state=0;
			else if(next!=EOF)
				ungetc(next,fp1);
		}
		if(ch =='\n') 
			fputc('\n',fp2);
	}
}
fclose(fp1);
fclose(fp2);
return 0;
}




