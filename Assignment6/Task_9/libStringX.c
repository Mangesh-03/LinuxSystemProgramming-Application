///////////////////////////////////////////////////////////////////////////////
//
//  Header file inclusion
//
///////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

///////////////////////////////////////////////////////////////////////////////
//
// Function Name :   CountLowercase()
// Description:      It used to count lowercase character from given input str.
// Input :           String(char[])
// Output :          It will return Count of lowercase charater .
// Author :          Mangesh Ashok Bedre
// Date :            2/02/2026
//
///////////////////////////////////////////////////////////////////////////////

int CountLowercase(char *str)
{
    int iCount = 0;
    int i = 0;

    while(*str != '\0')
    {
        if((*str >= 'a') && (*str <= 'z'))
        {
            iCount++;
        }
        str++;
    }

    return iCount;
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name :   CountUppercase()
// Description:      It used to count Uppercase character from given input str.
// Input :           String(char[])
// Output :          It will return Count of Uppercase charater .
// Author :          Mangesh Ashok Bedre
// Date :            2/02/2026
//
///////////////////////////////////////////////////////////////////////////////

int CountUppercase(char *str)
{
    int iCount = 0;
    int i = 0;

    while(*str != '\0')
    {
        if(((*str) >= 'A') && ((*str) <= 'Z'))
        {
            iCount++;
        }
        str++;
    }

    return iCount;
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name :   CountDigit()
// Description:      It used to count Digit from given input string
// Input :           String(char[])
// Output :          It will return Count of lowercase charater .
// Author :          Mangesh Ashok Bedre
// Date :            2/02/2026
//
///////////////////////////////////////////////////////////////////////////////

int CountDigit(char *str)
{
    int iCount = 0;

    while(*str != '\0')
    {
        if(((*str) >= '0') && ((*str) <= '9'))
        {
            iCount++;
        }
        
        str++;
    }

    return iCount;
}