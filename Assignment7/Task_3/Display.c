#include<stdio.h>

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Display()
//  Description :   Display the given string on standard output device.
//  Input :         string
//  Output :        Nothing.
//  Author:         Mangesh Ashok Bedre
//  Date :          2/02/2026
//
///////////////////////////////////////////////////////////////////////////////

void Display(char* str)
{
    int iCount = 0;
    
    printf("%s\n",str);

    while(*str != '\0')
    {
        iCount++;
        str++;
    }
    
    printf("Total number of characters : %d\n",iCount);
} 
