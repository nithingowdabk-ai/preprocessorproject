#include "preprocessor.h"
static void append_text(char *dest,int size,const char *src)
{
	int len=strlen(dest);
	if(len<size-1)
		strncat(dest,src,size-len-1);
}

int macro_replace(const char *input, const char *output)
{
    FILE *fp1, *fp2;
    char str[200];
    char name[50],value[100];
    char macro_name[20][50];
    char macro_value[20][100];
    char argument[20][20];
    int type[20];
    int count=0,i;

    fp1 = fopen(input, "r");

    if(fp1 == NULL)
    {
        printf("Unable to open input file\n");
        return 1;
    }

    fp2 = fopen(output, "w");

    if(fp2 == NULL)
    {
        fclose(fp1);
        return 1;
    }

    while(fgets(str, sizeof(str), fp1) != NULL)
    {
        if(strncmp(str,"#define ",8)==0)
	{
		if(count >= 20)
			continue;
		if(sscanf(str + 8,"%49[^(](%19[^)]) %99[^\n]",name,argument[count],value)==3)
		{
			strcpy(macro_name[count],name);
			strcpy(macro_value[count],value);
			type[count]=1;
			count++;
		}
		else if(sscanf(str +8,"%49s %99[^\n]",name,value)==2)
		{
			strcpy(macro_name[count],name);
			strcpy(macro_value[count],value);
			type[count]=0;
			count++;
		}
		continue;
	}
	for(i=0;i<count;i++)
	{
		char *ptr=strstr(str,macro_name[i]);
		if(ptr !=NULL)
		{
			char before[200],after[200];
			char replacement[200];
			int len=ptr-str;
			strncpy(before,str,len);
			before[len]='\0';

			if(type[i]==0)
			{
				
				strcpy(after,ptr + strlen(macro_name[i]));
				str[0]='\0';
				append_text(str,sizeof(str),before);
				append_text(str,sizeof(str),macro_value[i]);
				append_text(str,sizeof(str),after);
				
			}
			else
			{
				char *start=ptr+strlen(macro_name[i]);
				char *end=strchr(ptr,')');
				if(*start =='(' && end!=NULL)
				{
					char actual[50];
					char expanded[200];
					char *p;
					int j=0,k;
					len=end-start-1;
					strncpy(actual,start+1,len);
					actual[len]='\0';
					p=macro_value[i];
					while(*p!='\0' && j<190)
					{
						if(strncmp(p,argument[i],strlen(argument[i]))==0)
						{
							for(k=0;actual[k]!='\0';k++)
								expanded[j++]=actual[k];
							p=p+strlen(argument[i]);
						}
						else
						{
							expanded[j++]=*p++;
						}
					}
					expanded[j]='\0';
					strcpy(after,end+1);
					str[0]='\0';
					append_text(str,sizeof(str),before);
					append_text(str,sizeof(str),expanded);
					append_text(str,sizeof(str),after);
					
				}
			}
		}
	}

					
	fputs(str,fp2);
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}

