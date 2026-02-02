///////////////////////////////////////////////////////////////////////////////
//
//  Function Name : SumOfFactors()
//  Description :   Calculate the sum of factors.
//  Input :         Number
//  Output :        Sum of factors
//  Author:         Mangesh Ashok Bedre
//  Date :          2/02/2026
//
///////////////////////////////////////////////////////////////////////////////

int SumOfFactors(int No)
{
    int i = 0,iSum = 0;

    for(i = 1; i <= (No / 2) ; i++)
    {
        if((No % i) == 0)
        {
            iSum += i;
        }
    }

    return iSum;
} 
