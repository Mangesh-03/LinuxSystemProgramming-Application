#include<stdio.h>
#include<dlfcn.h>
#include<stdlib.h>
#include"Display.h"

///////////////////////////////////////////////////////////////////////////////
//
//  Entry point function
//
///////////////////////////////////////////////////////////////////////////////

int main()
{
    void *handle = NULL;

    char str[50] = {'\0'};

    void(*fp)(char*) =  NULL;

    handle = dlopen("./libDisplay.so",RTLD_LAZY);


    if((handle == NULL))
    {
        printf("Unble to load library\n");
        printf("%s\n",dlerror());
        exit(0);
    }


    fp = dlsym(handle,"Display");

    if((fp == NULL))
    {
        printf("Unble to get address\n");
        printf("%s\n",dlerror());
        exit(0);
    }

    printf("Enter the String: \n");
    scanf("%[^\n]s",str);

    fp(str);
    
    return 0;
}