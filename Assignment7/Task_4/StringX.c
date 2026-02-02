#include<stdio.h>

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name : strlenX()
//  Description :   Calculate the length of string.
//  Input :         string
//  Output :        Number of character.
//  Author:         Mangesh Ashok Bedre
//  Date :          2/02/2026
//
///////////////////////////////////////////////////////////////////////////////

int strlenX(const char * str)
{
    int iCount = 0;
    
    while(*str != '\0')
    {
        iCount++;
        str++;
    }
    
    return iCount;
} 
