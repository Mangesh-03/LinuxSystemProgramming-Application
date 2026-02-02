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

    int(*fp1)(char*) = NULL;
    int(*fp2)(char*) = NULL;
    int(*fp3)(char*) = NULL;
    
    handle = dlopen(lib,RTLD_LAZY);
 
    if(handle == NULL)
    {
        printf("%s\n",dlerror());
        exit(0);
    }

    fp1 = dlsym(handle,"CountLowercase");

    if(fp1 == NULL)
    {
        printf("%s\n",dlerror());
        exit(0);
    }

    fp2 = dlsym(handle,"CountUppercase");

    if(fp2 == NULL)
    {
        printf("%s\n",dlerror());
        exit(0);
    }
    fp3 = dlsym(handle,"CountDigit");

    if(fp3 == NULL)
    {
        printf("%s\n",dlerror());
        exit(0);
    }
    printf("lower : %d\n",fp1("MANgesh"));  // 4

    printf("upper : %d\n",fp2("123InDis")); // 2

    printf("Digit : %d\n",fp3("123Mangesh123")); //6

}

