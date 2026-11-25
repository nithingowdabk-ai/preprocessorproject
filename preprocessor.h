#ifndef preprocessor_h  //if not defined they prevent same header file from being include multiple times during complition
#define preprocessor_h  //define the name preprocessor
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int comment_remove(const char *,const char *);
int header_includes(const char *,const char *);
int macro_replace(const char *,const char *);
#endif //closes the the ifndef condition
