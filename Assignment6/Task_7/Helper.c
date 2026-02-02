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
//  Output :        Nothing
//  Author:         Mangesh Ashok Bedre
//  Date :          2/02/2026
//
///////////////////////////////////////////////////////////////////////////////

void LinkLib(char *lib)
{
    void *handle = NULL;

    void(*fp1)(void) = NULL;    
    void(*fp2)(void) = NULL;    

    
    handle = dlopen(lib,RTLD_LAZY);
 
    if(handle == NULL)
    {
        printf("%s\n",dlerror());
        exit(0);
    }

    fp1 = (void(*)(void)) dlsym(handle,"Disply");

    if(fp1 == NULL)
    {
        printf("%s\n",dlerror());
        exit(0);
    }

    fp2 = (void(*)(void)) dlsym(handle,"Modify");

    if(fp2 == NULL)
    {
        printf("%s\n",dlerror());
        exit(0);
    }
    
    /*
        Here value of global varible is persistent for every funtion call.
        It will reset after execution end or library(shared object) get unload.
    */

    // Display global var value
    fp1();

    // Modify global var value
    fp2();

    // This time it should display modify value
    fp1();

    // Modify global var value
    fp2();

    fp1();

}

