/*
    Write a client program that dynamically loads the library and 
    calls the required function based on user choice.
*/

///////////////////////////////////////////////////////////////////////////////
//
//  Header file inclusion
//
///////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<dlfcn.h>


///////////////////////////////////////////////////////////////////////////////
//
//  Entry Point Function
//
///////////////////////////////////////////////////////////////////////////////

int main()
{
    int iRet = 0,iChoice = 0;
    int val1 = 0,val2 = 0;
    double ret = 0.0;

    void *handle = NULL;
    
    int(*fp)(int,int) = NULL;
    double(*fdp)(int,int) = NULL;

    handle = dlopen("./libArithmetic.so",RTLD_LAZY);

    if(handle == NULL)
    {
        printf("Unble to load library\n");
        printf("%s\n",dlerror());
        return -1;
    }
    do
    {
        printf("---------------------------------------------------------------\n");
        printf("----------------Select option from menu------------------------\n");
        printf("---------------------------------------------------------------\n");

        printf("1.Addtion\n");
        printf("2.Subtraction\n");
        printf("3.Multiplication\n");
        printf("4.Division\n");  
        printf("0.exit\n\n");

        printf("Enter your choice : \n");
        scanf("%d",&iChoice);

        if(iChoice == 0)
        {
            break;
        }

        printf("Enter first Number : \n");
        scanf("%d",&val1);

        printf("Enter second Number : \n");
        scanf("%d",&val2);

        if(iChoice == 1)
        {
            fp = dlsym(handle,"Addiition");

            if(fp == NULL)
            {
                printf("Unble to get address of function\n");
                printf("%s\n\n",dlerror());

                continue;
            }
            iRet = fp(val1,val2);
            printf("Summation of numbers : %d\n\n",iRet);
        }
        else if(iChoice == 2)
        {
            fp = dlsym(handle,"Subtraction");

            if(fp == NULL)
            {
                printf("Unble to get address of function\n");
                printf("%s\n\n",dlerror());

                continue;
            }
            iRet = fp(val1,val2);
            printf("Difference of numbers : %d\n\n",iRet);
        }
        else if(iChoice == 3)
        {
            fp = dlsym(handle,"Multiplication");

            if(fp == NULL)
            {
                printf("Unble to get address of function\n");
                printf("%s\n\n",dlerror());

                continue;
            }
            iRet = fp(val1,val2);
            printf("Multiplication of numbers : %d\n\n",iRet);
        }
        else if(iChoice == 4)
        {
            fdp = dlsym(handle,"Division");

            if(fdp == NULL)
            {
                printf("Unble to get address of function\n");
                printf("%s\n\n",dlerror());

                continue;
            }
            ret = fdp(val1,val2);
            printf("Division of numbers : %.2f\n\n",ret);
        }
        
    }
    while(iChoice < 5);

    return 0;
}