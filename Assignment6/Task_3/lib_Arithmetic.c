/*
    Create a shared library that contains arithmetic functions:

        •Addition
        •Substraction
        •Multiplication
        •Division
*/

///////////////////////////////////////////////////////////////////////////////
//
//  Functions Definations
//
///////////////////////////////////////////////////////////////////////////////

int Addition(int iNo1,int iNo2)
{
    return (iNo1 + iNo2) ;
}

int Subtraction(int iNo1,int iNo2)
{
    return (iNo1 - iNo2) ;
}

int Multiplication(int iNo1,int iNo2)
{
    return (iNo1 * iNo2) ;
}

double Division(int iNo1,int iNo2)
{
    return (double)iNo1 / iNo2 ;
}