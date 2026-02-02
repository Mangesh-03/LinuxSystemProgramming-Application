///////////////////////////////////////////////////////////////////////////////
//
// Header File Inclusion
//
///////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<dlfcn.h>
#include<stdlib.h>

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name : LinkLib()
//  Description :   open shared object and call function from it
//  Input :         Takes name of shared object 
//  Output :        Returns result of function fromm shared object
//  Author:         Mangesh Ashok Bedre
//  Date :          2/02/2026
//
///////////////////////////////////////////////////////////////////////////////

int LinkLib(char *lib)
{
    void *handle = NULL;

    int(*fp)(int,int) = NULL;    
    
    handle = dlopen(lib,RTLD_LAZY);
 
    if(handle == NULL)
    {
        printf("%s\n",dlerror());
        exit(0);
    }

    fp = dlsym(handle,"Addition");

    if(fp == NULL)
    {
        printf("%s\n",dlerror());
        exit(0);
    }

    return fp(11,10);

}

