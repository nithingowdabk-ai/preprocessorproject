#include "preprocessor.h"   //includes user defined headder file it contains function declartions
int main(int argc,char *argv[]) // ex ./mypreprocessor inputfile.c
{
	char output[200]; // char array stores the output file like inputfile.i
	char *ptr;  // char pointer used to locate the dot (.)int file name
	if(argc!=2) // ./mypreprocessor inputfile.c
	{
		printf("usage:./mypreprocessor filename.c\n");
		return 1;
	}
	strcpy(output,argv[1]);   //copy one string into another,inputfile.c
	ptr=strrchr(output,'.');  //finds the last occurence of a specfied character in a string
	if(ptr!=NULL) // checks wherther the dot was found 
		*ptr='\0';   //replaces the dot with null char
	strcat(output,".i");   // joins two string
	if(comment_remove(argv[1],"temp1.c")!=0) // call        temp1 after the comment removl
	{
		printf("comment removal failed\n");
		return 1;
	}
	if(header_includes("temp1.c","temp2.c")!=0)// call       temp1 input after comment removal temp2 output after file inclusion
	{
		printf("file inclusion filed\n");
		remove("temp1.c"); // deletees the temprory file if processing files
		return 1;
	}
	if(macro_replace("temp2.c",output)!=0) // call macros replace
	{
		printf("macro substitution failed\n");
		remove("temp1.c");
		remove("temp2.c");
		return 1;
	}
	remove("temp1.c");    // remove statnadar c library function it deletes the temprory files after successful processing
	remove("temp2.c");    
	printf("preprocessing completed successfully\n");
	printf("output file:%s\n",output);// like outputfile:inputfile.i
	return 0;
}



