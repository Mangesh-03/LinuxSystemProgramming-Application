#include<stdio.h>
#include<dlfcn.h>
#include<stdlib.h>
#include"Addition.h"
#include"Subtraction.h"

///////////////////////////////////////////////////////////////////////////////
//
//  Entry point function
//
///////////////////////////////////////////////////////////////////////////////

int main()
{
    int iNo1 = 0,iNo2 = 0;

    void *handle1 = NULL;
    void *handle2 = NULL;

    int(*fp1)(int,int) =  NULL;
    int(*fp2)(int,int) =  NULL;

    handle1 = dlopen("./libAddition.so",RTLD_LAZY);

    handle2 = dlopen("./libSubtraction.so",RTLD_LAZY);

    if((handle1 == NULL) || (handle2 == NULL))
    {
        printf("Unble to load library\n");
        printf("%s\n",dlerror());
        exit(0);
    }

    fp1 = (int(*)(int,int))dlsym(handle1,"Addition");

    fp2 = (int(*)(int,int))dlsym(handle2,"Subtraction");

    if((fp1 == NULL) || (fp2 == NULL))
    {
        printf("Unble to get address\n");
        printf("%s\n",dlerror());
        exit(0);
    }

    printf("Enter the first Number : \n");
    scanf("%d",&iNo1);

    printf("Enter the Second Number : \n");
    scanf("%d",&iNo2);

    printf("Summation is : %d\n",fp1(iNo1,iNo2));

    printf("Subtraction is : %d\n",fp2(iNo1,iNo2));
    
    return 0;
}