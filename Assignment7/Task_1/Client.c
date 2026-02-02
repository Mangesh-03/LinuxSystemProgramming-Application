#include<stdio.h>
#include<dlfcn.h>
#include<stdlib.h>
#include<stdbool.h>
#include"Perfect.h"
#include"Helper.h"

///////////////////////////////////////////////////////////////////////////////
//
//  Entry point function
//
///////////////////////////////////////////////////////////////////////////////

int main()
{
    bool bRet = false;
    int iNo = 0;

    void *handle = NULL;

    int(*fp)(int) =  NULL;

    handle = dlopen("./libperfect.so",RTLD_LAZY);

    if(handle == NULL)
    {
        printf("Unble to load library\n");
        printf("%s\n",dlerror());
        exit(0);
    }

    fp = (int(*)(int))dlsym(handle,"ChkPerfect");

    if(fp == NULL)
    {
        printf("Unble to get address\n");
        printf("%s\n",dlerror());
        exit(0);
    }

    printf("Enter the Number : \n");
    scanf("%d",&iNo);

    bRet = fp(iNo);

    if(bRet == true)
    {
        printf("%d is perfect number\n",iNo);
    }
    else
    {
        printf("%d is not perfect number\n",iNo);
    }
    
    return 0;
}