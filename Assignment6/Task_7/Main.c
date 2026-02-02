/*
    Create a shared library that maintains a global variable inside the library.
        
        The library should provide functions to:

        •Modify the global variable
        •Display its value
        •Reset its value
    
    Write a dynamically linked client program to demonstrate persistence of the 
    global variable across multiple function calls..

*/

///////////////////////////////////////////////////////////////////////////////
//
// Header File Inclusion
//
///////////////////////////////////////////////////////////////////////////////

#include"Myheader.h"

int main()
{
    char name[] = "./libGlobalVar.so";

    LinkLib(name);

    return 0;
}