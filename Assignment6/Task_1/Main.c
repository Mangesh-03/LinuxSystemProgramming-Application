/*
    Write a separate client program that loads this library at runtime using dlopen() 
    and calls both functions using dlsym().
*/


///////////////////////////////////////////////////////////////////////////////
//
// Header File Inclusion
//
///////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<dlfcn.h>
#include"lib_AddSub.h"

///////////////////////////////////////////////////////////////////////////////
//
// User Defined Macros
//
///////////////////////////////////////////////////////////////////////////////

#define ERR_FAIL_TO_ADDRESS -2

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Sum()
//  Description  :      It call library function to do Addition of given number
//  Input    :          It takes handle of library and numbers for addition with 
//                      their count  
//  Output  :           return Addition of numbers
//  Author:             Mangesh Ashok Bedre
//  Date :              29/01/2026
//
///////////////////////////////////////////////////////////////////////////////

int Sum(void *handle, int iCount, int iNo1,int iNo2)
{
    int iAns = 0;

    // Function pointer for get Address of Addition function
    int(*fp)(int,...) = NULL; 

    fp = (int(*)(int,...))dlsym(handle,"Addition");

    if(fp == NULL)
    {
        printf("Unble to get Address\n");
        printf("Reason : %s\n",dlerror());
        return ERR_FAIL_TO_ADDRESS;
    }
    // Addition from library can take varible number of argument
    // here we give 2 argument but client can change it according their need

    iAns = fp(iCount,iNo1,iNo2);

    return iAns;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Differnce()
//  Description  :      It call library function to do subtraction of given number
//  Input    :          It takes handle of library and numbers for subtraction with 
//                      their count 
//  Output  :           return subtraction of numbers
//  Author:             Mangesh Ashok Bedre
//  Date :              29/01/2026
//
///////////////////////////////////////////////////////////////////////////////

int Differnce(void *handle, int iCount, int iNo1,int iNo2)
{
    int iAns = 0;

    // Function pointer for get Address of Addition function
    int(*fp)(int,...) = NULL; 

    fp = (int(*)(int,...))dlsym(handle,"Subtraction");

    if(fp == NULL)
    {
        printf("Unble to get Address\n");
        printf("Reason : %s\n",dlerror());
        return -1;
    }
    // Subtraction from library can take varible number of argument
    // here we give 2 argument but client can change it according their need

    iAns = fp(iCount,iNo1,iNo2);

    return iAns;
}

///////////////////////////////////////////////////////////////////////////////
//
// Entry Point Function
//
///////////////////////////////////////////////////////////////////////////////

int main()
{
    int iValue1  = 0,iValue2 = 0;

    void * handle = NULL;

    handle = dlopen("./libAddSub.so",RTLD_LAZY);

    if(handle == NULL)
    {
        printf("Unble to load library\n");
        dlerror();
        return -1;
    }

    printf("Library load successfully\n");

    printf("Enter the first no : \n");
    scanf("%d",&iValue1);

    printf("Enter the sencod no : \n");
    scanf("%d",&iValue2);

    /* 
       Here inside parameter we write hardcode value 2 bcz It demonstration of 
       program in which Client want to do addition and subtraction of 2 number
       but the Library Function could work for 2 or more than 2 numbers 
    */
    printf("Addition is : %d\n",Sum(handle,2,iValue1,iValue2));
    
    printf("Subtraction is : %d\n",Differnce(handle,2,iValue1,iValue2));

    dlclose(handle);

    return 0;
}