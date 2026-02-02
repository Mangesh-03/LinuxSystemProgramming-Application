// Explain the difference between RTLD_LAZY and RTLD_NOW ags used with dlopen().
// Write a program that loads the same shared library twice:
// •Once using RTLD_LAZY
// •Once using RTLD_NOW

#include<stdio.h>
#include"MyHeader.h"

int main()
{
    char name[] = "./libtest.so";

    LinkLibrary_RTLD_LAZY(name);

    LinkLibrary_RTLD_NOW(name);

    return 0;
}