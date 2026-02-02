/*
    Write a program to demonstrate what happens when:
        
        •A valid shared library is loaded

        •An invalid or missing function name is passed to dlsym()
         Your program should gracefully handle errors using dlerror() and 
         print meaningful messages.
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

    /* 
        dlsym() => used to get address of desired function for do work
                   here we gave a wrong function name for demonstration
    */
    fp = dlsym(handle,"Addiition");

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