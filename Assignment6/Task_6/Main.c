/*
    Write a program to demonstrate dynamic library search path resolution in Linux.
       
        •Place a shared library in a custom directory.
        •Write a client program that loads the library without specifying full path.
        •Execute the program with and without setting LD_LIBRARY_PATH.
       
    Explain the output in both cases.

*/

///////////////////////////////////////////////////////////////////////////////
//
// Header File Inclusion
//
///////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include"Myheader.h"

int main()
{
    char name[] = "libArithmetic.so";
    int iRet = 0;

    /*
        Here we not pass path of lib we just pass name of shared object (library).

        case 1: If we run code without set environment varible LD_LIBRARY_PATH 
        it wont run properly give an error

        Error : libArithmetic: cannot open shared object file: No such file or directory

        case 2: If we run code With Seting environment variable with shared object path
        then it will work
        
        LD_LIBRARY_PATH=/home/mangesh/Desktop/LSP_GIT/LSP_Assignments/Assignment6/Task_3 make run 

        above varible hold path for temporary not permenent. for perment use export keyword

    */

    iRet = LinkLib(name);

    printf("Summation is : %d\n",iRet);

    return 0;
}