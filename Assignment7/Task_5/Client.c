#include<stdio.h>
#include<dlfcn.h>
#include<stdlib.h>
#include"stringX.h"

///////////////////////////////////////////////////////////////////////////////
//
//  Entry point function
//
///////////////////////////////////////////////////////////////////////////////

int main()
{
    int iRet = 0,choice = 0,size = 0;

    char str1[100] = {'\0'}; 
    char str2[100] = {'\0'};

    void *handle = NULL;

    //Function pointers
    int(*lenfp)(const char*) =  NULL;
    char*(*revfp)(char *) = NULL;
    char*(*cpycatfp)(char*,const char*);
    char*(*ncpycatfp)(char*,const char*,int);
    int*(*cmpfp)(const char*,const char*);
    int*(*ncmpfp)(const char*,const char*,int);

    handle = dlopen("./libstring.so",RTLD_LAZY);

    if((handle == NULL))
    {
        printf("Unble to load library\n");
        printf("%s\n",dlerror());
        exit(0);
    }

    while(1)
    {
        printf("---------------------------------------------------------------\n");
        printf("---------------------Select the option-------------------------\n");
        printf("---------------------------------------------------------------\n");

        printf("1.strlen()\n");
        printf("2.strcmp()\n");
        printf("3.strncmp()\n");
        printf("4.strcpy()\n");
        printf("5.strncpy()\n");
        printf("6.strcat()\n");
        printf("7.strncat()\n");
        printf("8.strrev()\n");
        printf("9.Exit\n");

        scanf("%d",&choice);

        if(choice == 9)
        {
            printf("Thank You\n");
            break;
        }

        if(choice == 1)
        {
            lenfp = dlsym(handle,"strlenX");
            
            if(lenfp == NULL)
            {
                printf("Error : %s\n",dlerror());
                continue;
            }

            printf("Enter the string : \n");
            scanf(" %[^\n]s",str1);

            iRet = lenfp(str1);
            
            printf("Length of string is : %d\n",iRet);

        }//end of choice == 1

        else if(choice == 2)
        {
            cmpfp = dlsym(handle,"strcmpX");

            if(cmpfp == NULL)
            {
                printf("Error : %s\n",dlerror());
                continue;
            }

            printf("Enter first string : \n");
            scanf(" %[^\n]s",str1);

            printf("Enter second string : \n");
            scanf(" %[^\n]s",str2);

            iRet = cmpfp(str1,str2);

            if(iRet == 0)
            {
                printf("Strings are identical\n");
            }
            else
            {
                printf("String are not identical\n");
            }
        }//end of choice = 2
        
        else if(choice == 3)
        {
            ncmpfp = dlsym(handle,"strncmpX");

            if(ncmpfp == NULL)
            {
                printf("Error : %s\n",dlerror());
                continue;
            }
            printf("Enter first string : \n");
            scanf(" %[^\n]s",str1);

            printf("Enter second string : \n");
            scanf(" %[^\n]s",str2);

            printf("Enter the size : \n");
            scanf("%d",&size);

            iRet = ncmpfp(str1,str2,size);

            if(iRet == 0)
            {
                printf("Strings are identical for size %d\n",size);
            }
            else
            {
                printf("String are not identical for size %d\n",size);
            }
        }//end of choice = 3

        else if(choice == 4) ///////////////
        {
            cpycatfp = dlsym(handle,"strcpyX");

            if(cpycatfp == NULL)
            {
                printf("Error : %s\n",dlerror());
                continue;
            }
            printf("Enter source string : \n");
            scanf(" %[^\n]s",str2);

            printf("Enter destination string : \n");
            scanf(" %[^\n]s",str1);

            cpycatfp(str1,str2); 

            printf("Destination string : %s\n",str1);

        }//end of choice = 4

        else if(choice == 5) ///////////////
        {
            ncpycatfp = dlsym(handle,"strncpyX");

            if(ncpycatfp == NULL)
            {
                printf("Error : %s\n",dlerror());
                continue;
            }

            printf("Enter source string : \n");
            scanf(" %[^\n]s",str2);

            printf("Enter destination string : \n");
            scanf(" %[^\n]s",str1);

            printf("Enter size : \n");
            scanf("%d",&size);

            ncpycatfp(str1,str2,size); 

            printf("Destination string : %s\n",str1);

        }//end of choice = 5
        else if(choice == 6)
        {
            cpycatfp = dlsym(handle,"strcatX");

            if(cpycatfp == NULL)
            {
                printf("Error : %s\n",dlerror());
                continue;
            }
            printf("Enter first string : \n");
            scanf(" %[^\n]s",str1);

            printf("Enter second string : \n");
            scanf(" %[^\n]s",str2);

            cpycatfp(str1,str2); 

            printf("Final string : %s\n",str1);

        }//end of choice = 6
        else if(choice == 7)
        {
            ncpycatfp = dlsym(handle,"strncatX");

            if(ncpycatfp == NULL)
            {
                printf("Error : %s\n",dlerror());
                continue;
            }

            printf("Enter des string : \n");
            scanf(" %[^\n]s",str1);

            printf("Enter first string : \n");
            scanf(" %[^\n]s",str2);

            printf("Enter size : \n");
            scanf("%d",&size);

            ncpycatfp(str1,str2,size); 

            printf("Final string : %s\n",str1);
            
        }//end of choice = 7
        else if(choice == 8)
        {
            revfp = dlsym(handle,"strrevX");

            if(revfp == NULL)
            {
                printf("Error : %s\n",dlerror());
                continue;
            }
            printf("Enter the string : \n");
            scanf(" %[^\n]s",str1);

            revfp(str1);
            
            printf("Reverse string is : %s\n",str1);
        }//End of choice = 8

    }//end of while


    return 0;
}