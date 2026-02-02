#include<stdio.h>
#include<dlfcn.h>
#include<stdlib.h>
#include"StringX.h"

///////////////////////////////////////////////////////////////////////////////
//
//  Entry point function
//
///////////////////////////////////////////////////////////////////////////////

int main()
{
    int iRet = 0;

    void *handle = NULL;

    char str[50] = {'\0'};

    int(*fp)(const char*) =  NULL;

    handle = dlopen("./libstring.so",RTLD_LAZY);


    if((handle == NULL))
    {
        printf("Unble to load library\n");
        printf("%s\n",dlerror());
        exit(0);
    }


    fp = dlsym(handle,"strlenX");

    if((fp == NULL))
    {
        printf("Unble to get address\n");
        printf("%s\n",dlerror());
        exit(0);
    }

    printf("Enter the String: \n");
    scanf("%[^\n]s",str);

    iRet = fp(str);

    printf("Length of String : %d\n",iRet);

    return 0;
}