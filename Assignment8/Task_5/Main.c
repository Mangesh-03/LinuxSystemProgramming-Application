#include<stdio.h>
#include"math.h"

int main()
{
    int no1 = 0,no2 = 0;

    printf("Enter the first no : \n");
    scanf("%d",&no1);

    printf("Enter the second no : \n");
    scanf("%d",&no2);

    printf("Addition is : %d\n",Addition(no1,no2));
    printf("Subtraction is : %d\n",Subtraction(no1,no2));
    printf("Multiplication is : %d\n",Multiplication(no1,no2));
    printf("Division is : %.f\n",Division(no1,no2));

    return 0;
}