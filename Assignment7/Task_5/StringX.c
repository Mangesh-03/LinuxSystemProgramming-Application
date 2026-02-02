#include<stddef.h>

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

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name : strrevX()
//  Description :   Reverse the string in-position.
//  Input :         string
//  Output :        reverse string.
//  Author:         Mangesh Ashok Bedre
//  Date :          2/02/2026
//
///////////////////////////////////////////////////////////////////////////////

char * strrevX(char * str)
{
    char *start = NULL;
    char *end = NULL;
    char temp = '\0';
    
    // Filter
    if(str == NULL)
    {
        return NULL;
    }

    end = str;
    start = str;

    while(*end != '\0')
    {
        end++;
    }

    end--;

    while(start < end)
    {
        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
    return str;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name : strcpyX()
//  Description :   copy the string from source to destination.      
//  Author:         Mangesh Ashok Bedre
//  Date :          2/02/2026
//
///////////////////////////////////////////////////////////////////////////////

char  *strcpyX(char *des, const char *src)
{
    while(*src != '\0')
    {
        *des = *src;

        des++;
        src++;
    }
    
    *des = '\0';

    return des;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name : strncpyX()
//  Description :   copy the string from source to destination.       
//  Author:         Mangesh Ashok Bedre
//  Date :          2/02/2026
//
///////////////////////////////////////////////////////////////////////////////

char  *strncpyX(char *des, const char *src, int size)
{
    int i = 0;

    for(i = 0;i < size; i++,src++,des++)
    {
        *des = *src;
    }
    *des = '\0';
    return des;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name : strcatX()
//  Description :   concat two string.      
//  Author:         Mangesh Ashok Bedre
//  Date :          2/02/2026
//
///////////////////////////////////////////////////////////////////////////////

char  *strcatX(char *str1, const char *str2)
{
    char* end = str1;

    while(*end != '\0')
    {
        end++;
    }
    
    while(*str2 != '\0')
    {
        *end = *str2;

        str2++;
        end++;
    }
    
    *end = '\0';

    return str1;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name : strncatX()
//  Description :   concat two string.       
//  Author:         Mangesh Ashok Bedre
//  Date :          2/02/2026
//
///////////////////////////////////////////////////////////////////////////////

char *strncatX(char *str1, const char *str2, int size)
{
    char* end = str1;

    while(*end != '\0')
    {
        end++;
    }

    for(int i = 0 ; i < size; i++ ,end++,str2++)
    {
        *end = *str2;
    }

    *end = '\0';

    return str1;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name : strcmpX()
//  Description :   compare two string.       
//  Author:         Mangesh Ashok Bedre
//  Date :          2/02/2026
//
///////////////////////////////////////////////////////////////////////////////

int  strcmpX(const char * str1, const char *str2)
{
    if(strlenX(str1) != strlenX(str2))
    {
        return -1;
    }

    while(*str1 != '\0')
    {
        if(*str1 != *str2)
        {
            break;
        }

        str1++;
        str2++;
    }
    return (*str1 - *str2);
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name : strncmpX()
//  Description :   compare two string.       
//  Author:         Mangesh Ashok Bedre
//  Date :          2/02/2026
//
///////////////////////////////////////////////////////////////////////////////

int strncmpX(const char *str1, const char *str2, int size)
{   
    int i = 0;

    for(i = 0; i < size; i++,str1++,str2++)
    {
        if(*str1 != *str2)
        {
            break;
        }
    }

    return (*str1 - *str2);
}

