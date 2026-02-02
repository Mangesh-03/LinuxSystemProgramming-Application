/*
    Write a program to demonstrate the use of function pointers with dlsym().
        
        •Store addresses of multiple dynamically loaded functions in an array of 
         function pointers.
        •Invoke functions using this array.
        •Display function addresses along with results.
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
 
    // The array of Function pointer 
 
    int(*fp[3])(char*)  = {NULL};
   
    handle = dlopen(lib,RTLD_LAZY);
 
    if(handle == NULL)
    {
        printf("%s\n",dlerror());
        exit(0);
    }

    // Get Address in Array
    fp[0] = dlsym(handle,"CountLowercase");

    if(fp[0] == NULL)
    {
        printf("%s\n",dlerror());
        dlclose(handle);
        exit(0);
    }

    fp[1] = dlsym(handle,"CountUppercase");

    if(fp[1] == NULL)
    {
        printf("%s\n",dlerror());
        dlclose(handle);
        exit(0);
    }

    fp[2] = dlsym(handle,"CountDigit");

    if(fp[2] == NULL)
    {
        printf("%s\n",dlerror());
        dlclose(handle);
        exit(0);
    }

    // Function call using Array
    printf("Address of function : %p \tCount of lowerCase : %d\n",*fp[1],fp[0]("India"));  // 4

    printf("Address of function : %p \tCount of UpperCase : %d\n",*fp[2],fp[1]("PUne")); // 2

    printf("Address of function : %p \tCount of Digit : %d\n",*fp[2],fp[2]("123Mangesh123")); //6

    dlclose(handle);
}

