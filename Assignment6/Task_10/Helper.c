///////////////////////////////////////////////////////////////////////////////
//
// Header File Inclusion
//
///////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<dlfcn.h>
#include<stdbool.h>
#include<stdlib.h>

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InspectionTool()
//  Description :   Check whether the given library and symbol exist or not.
//  Input :         Arr having library path and symbol name 
//  Output :        Nothing
//  Author:         Mangesh Ashok Bedre
//  Date :          2/02/2026
//
///////////////////////////////////////////////////////////////////////////////

void InspectionTool(char *lib,char *sym)
{
    void *handle = NULL;
    int(*fp)(char*) = NULL;

    handle = dlopen(lib,RTLD_LAZY);

    if(handle == NULL)
    {
        printf("Error : %s\n",dlerror());
        exit(0);
    }

    fp = (int(*)(char*))dlsym(handle,sym);

    if(fp == NULL)
    {
        printf("Error : %s\n",dlerror());
        dlclose(handle);
        exit(0);
    }

    printf("Symbol found at Address : %p\n",*fp);

    dlclose(handle);
}

