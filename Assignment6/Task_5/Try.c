#include<stdio.h>
#include<dlfcn.h>

int main()
{
    void* handle = NULL;
    int(*fp)(int,int) = NULL;

    handle = dlopen("./libtest.so",RTLD_NOW);

    if(handle == NULL)
    {
        printf("open error handler : %s\n",dlerror());
        return -1;
    }

    fp = dlsym(handle,"ghost");

    if(fp == NULL)
    {
        printf("dlsym error handler : %s\n",dlerror());
        return -1;
    }

    printf("Summation : %d\n",fp(11,10));

    return 0;
}