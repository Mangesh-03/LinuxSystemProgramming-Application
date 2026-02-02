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

#include"Myheader.h"

int main()
{
    char name[] = "./libString.so";

    LinkLib(name);

    return 0;
}