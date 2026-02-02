#include<stdlib.h>
#include<dlfcn.h>
#include<stdio.h>

void LinkLibrary_RTLD_NOW(char *lib)
{
    void *handle = NULL;

    int(*fp)(int,int) = NULL;    
    
    /*
        RTLD_NOW: dlopen() fails immediately and returns NULL

        bcz it directly resolved all dependency from lib file it 
        not wait later it do immediately.
    */
    handle = dlopen(lib,RTLD_NOW);
 
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

    printf("Summation is : %d\n",fp(11,10));

    dlclose(handle);

}

