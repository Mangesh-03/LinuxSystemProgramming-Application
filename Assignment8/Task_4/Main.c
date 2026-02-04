#include<stdio.h>
#include"Helper.h"

int main()
{
    int no1 = 0,no2 = 0;

    printf("Enter the first no : \n");
    scanf("%d",&no1);

    printf("Enter the second no : \n");
    scanf("%d",&no2);

    printf("Addition is : %d\n",Addition(no1,no2));

    return 0;
}