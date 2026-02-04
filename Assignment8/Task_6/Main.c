#include<stdio.h>
#include<dlfcn.h>
#include<stdlib.h>
#include"math.h"

///////////////////////////////////////////////////////////////////////////////
//
//  Entry point function
//
///////////////////////////////////////////////////////////////////////////////

int main()
{
    int iNo1 = 0,iNo2 = 0;

    void *handle = NULL;

    int(*fp)(int,int) =  NULL;

    handle = dlopen("libmath.so",RTLD_LAZY);

    if(handle == NULL)
    {
        printf("Unble to load library\n");
        printf("%s\n",dlerror());
        exit(0);
    }

    fp = (int(*)(int,int))dlsym(handle,"Addition");

    if(fp == NULL)
    {
        printf("Unble to get address\n");
        printf("%s\n",dlerror());
        exit(0);
    }

    printf("Enter the first Number : \n");
    scanf("%d",&iNo1);

    printf("Enter the second Number : \n");
    scanf("%d",&iNo2);

    printf("Summation is : %d\n",fp(iNo1,iNo2));
    
    return 0;
}