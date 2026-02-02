/*
    Write a C program to demonstrate runtime dynamic linking in Linux.
    
    Your program should:

        •Load a shared library using dlopen()
        •Fetch function addresses using dlsym()
        •Handle errors using dlerror()
        •Release the library using dlclose()
*/


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
// Entry Point Function
//
///////////////////////////////////////////////////////////////////////////////

int main()
{
    int iValue1  = 0,iValue2 = 0;

    void * handle = NULL;
    int(*fp)(int,...) = NULL;

    /*
        dlopen() => used for load or link the shared object(dynamic library)
    */
    handle = dlopen("./libAddSub.so",RTLD_LAZY);

    if(handle == NULL)
    {
        printf("Unble to load library\n");

        // dlerror() => print meaning error message for understanding
        printf("Error : %s\n",dlerror());
        exit(EXIT_FAILURE);
    }

    printf("Library load successfully\n");

    // dlsym() => used to get address of desired function for do work
    fp = dlsym(handle,"Addition");

    if(fp == NULL)
    {
        printf("Error : %s\n",dlerror());
        dlclose(handle);
        exit(EXIT_FAILURE);
    }
    
    printf("Enter the First number : \n");
    scanf("%d",&iValue1);

    printf("Enter the second number : \n");
    scanf("%d",&iValue2);

    printf("Summation is : %d\n",fp(2,iValue1,iValue2));

    // dlclose() => used to unload or unlink dynamic library(shared object)
    dlclose(handle);

    return 0;
}