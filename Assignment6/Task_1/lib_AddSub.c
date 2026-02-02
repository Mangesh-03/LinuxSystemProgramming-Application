// create a shared library (.so) that contains two functions:
// •Addition(int, int)
// •Substraction(int, int)

///////////////////////////////////////////////////////////////////////////////
//
// Header File Inclusion
//
///////////////////////////////////////////////////////////////////////////////

#include <stdarg.h>

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Addition()
//  Description  :      It calculate the summation of given number
//  Input    :          int,(...)
//  Output  :           int
//  Author:             Mangesh Ashok Bedre
//  Date :              29/01/2026
//
///////////////////////////////////////////////////////////////////////////////

// 1. The '...' means this function takes variable arguments
// We need 'count' to know how many arguments to expect.
int Addition(int count,...)
{
    int sum = 0;

    // 2. Define the list variable
    va_list ptr;

    // 3. Initialize the list
    // You must tell it the name of the last fixed argument (count)
    va_start(ptr, count);

    for(int i = 0 ; i < count; i++)
    {
        //4. Get argument from varible_arg_list
        int val = va_arg(ptr, int);
        sum += val;
    }

    return sum;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Subtraction()
//  Description  :      It calculate the differnce between of given number
//  Input    :          int,int
//  Output  :           int
//  Author:             Mangesh Ashok Bedre
//  Date :              29/01/2026
//
///////////////////////////////////////////////////////////////////////////////

// 1. The '...' means this function takes variable arguments
// We need 'count' to know how many arguments to expect.
int Subtraction(int count,...)
{
    int sub = 0;

    // 2. Define the list variable
    va_list ptr;

    // 3. Initialize the list
    // You must tell it the name of the last fixed argument (count)
    va_start(ptr, count);

    sub = va_arg(ptr, int);

    for(int i = 1 ; i < count; i++)
    {
        //4. Get argument from varible_arg_list
        int val = va_arg(ptr, int);
        sub -= val;
    }

    return sub;
}