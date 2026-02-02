#include<stdlib.h>
#include<dlfcn.h>
#include<stdio.h>

void LinkLibrary_RTLD_LAZY(char *lib)
{
    void *handle = NULL;

    int(*fp)(int,int) = NULL;    
    
    handle = dlopen(lib,RTLD_LAZY);
 
    if(handle == NULL)
    {
        printf("Unble to load library\n");
        printf("%s\n",dlerror());
        return;
    }

    fp = dlsym(handle,"Addition");

    if(fp == NULL)
    {
        printf("Unble to get address\n");
        printf("%s\n",dlerror());
        dlclose(handle);
        return;
    }

    /* 
       RTLD_LAZY: dlopen() ,dlsym() succeeds, but the program crashes at the function call fp(11,10) 
       because the missing symbol is only looked up when the code tries to execute it.

       as it is RTLD_LAZY it does not check at dlopen 
    */
    printf("Summation is : %d\n",fp(11,10));

    dlclose(handle);

}

