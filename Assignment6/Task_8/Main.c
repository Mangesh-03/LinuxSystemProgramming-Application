/*
    Write a C program to dynamically load a shared library that performs string operations:

    •Count number of lowercase letters
    •Count number of uppercase letters
    •Count number of digits

    The client program should accept a string from the user and call the 
    appropriate functions using dlsym().

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