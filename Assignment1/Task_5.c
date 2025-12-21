// • Accept file name and number of bytes N.
// • Read exactly N bytes using read() and print on console.
// • If file contains less than N, print only available bytes

#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include <sys/stat.h>

/////////////////////////////////////////////////////////////////
//
// Function name : ReadFile()
// Description   : Read N Bytes From File.
// Input         : char*
// output        : -
// Author        : Mangesh Ashok Bedre.
// Date          : 20/12/2025
//
/////////////////////////////////////////////////////////////////

void ReadFile(char * FileName,int bytes)
{
    int iRet = 0,fd = 0;
    char buffer[100];
    
    fd = open(FileName,O_RDONLY);

    iRet = read(fd,buffer,bytes);

    if(iRet == -1)
    {
        perror("Unable to read");
    }
    printf("Number of bytes read %d\n",iRet);
    
}

//////////////////////////////////////////////////////////////////
//
//  Function Name : main()   (entry point function)
//  Author        : Mangesh Ashok Bedre.
//  Date          : 20/12/2025
//
//////////////////////////////////////////////////////////////////
int main()
{
    char FileName[50];
    int bytes = 0;
    
    memset(FileName,'\0',sizeof(FileName));

    printf("Enter the file name : \n");
    scanf("%s",FileName);

    printf("Enter number of bytes :\n");
    scanf("%d",&bytes);

    ReadFile(FileName,bytes);

    return 0;
}