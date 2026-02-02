#include<stdio.h>
#include<dlfcn.h>
#include<stdlib.h>
#include<stdbool.h>

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name : ChkPerfect()
//  Description :   Check whether given number is perfect or not.
//  Input :         Number
//  Output :        return True if number is perfect and false if not. 
//  Author:         Mangesh Ashok Bedre
//  Date :          2/02/2026
//
///////////////////////////////////////////////////////////////////////////////

bool ChkPerfect(int iNo)
{
    void *handle = NULL;

    int(*fp)(int) =  NULL;

    handle = dlopen("./libhelper.so",RTLD_LAZY);

    if(handle == NULL)
    {
        printf("Unble to load library\n");
        printf("%s\n",dlerror());
        exit(0);
    }

    fp = (int(*)(int))dlsym(handle,"SumOfFactors");

    if(fp == NULL)
    {
        printf("Unble to get address\n");
        printf("%s\n",dlerror());
        exit(0);
    }

    return (iNo == fp(iNo));
}