#include<stdio.h>

/*
    Global varible . 

    No need to initialise as it get memory into data section , default value from data 
    section is cleared
*/
int iVal;

///////////////////////////////////////////////////////////////////////////////
//
// Function Name :   Display()
// Description:      It will print global var value on console
// Author :          Mangesh Ashok Bedre
// Date :            2/02/2026
//
///////////////////////////////////////////////////////////////////////////////

void Disply()
{
    printf("Value of iVal : %d\n",iVal);
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name :   Modify()
// Description:      It will change global var value .
// Author :          Mangesh Ashok Bedre
// Date :            2/02/2026
//
///////////////////////////////////////////////////////////////////////////////

void Modify()
{
    iVal += 5;
}