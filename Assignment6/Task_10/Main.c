/*
    Design and implement a mini dynamic library inspection tool.
    
    The program should:
    
        •Accept shared library path and symbol name as command-line arguments
        •Load the library using dlopen()
        •Check whether the given symbol exists using dlsym()
        •Display symbol address if found
        •Display appropriate error message otherwise

*/

///////////////////////////////////////////////////////////////////////////////
//
// Header File Inclusion
//
///////////////////////////////////////////////////////////////////////////////

#include"Myheader.h"
#include<stdio.h>

int main(int argc,char **argv)
{
    printf("argc : %d\n",argc);
    if(argc != 3)
    {
        printf("usage : %s <lib_path> <symbol_name>\n",argv[0]);
        return -1;
    }

    InspectionTool(argv[1],argv[2]);

    return 0;
}