// • Accept file name and print full content on console.
// • Use a buffer loop (read() until 0).
// • Show total bytes read.

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<stdlib.h>

/////////////////////////////////////////////////////////////////
//
//  User Defined Macros
//
/////////////////////////////////////////////////////////////////

#define BUFFER_SIZE 1024

/////////////////////////////////////////////////////////////////
//
// Function name : ReadFile()
// Description   : Read Whole File
// Input         : char*
// output        : void
// Author        : Mangesh Ashok Bedre.
// Date          : 23/12/2025
//
/////////////////////////////////////////////////////////////////

void ReadFile(char * FileName)
{
    int fd = 0,iRet = 0;
    char buffer[BUFFER_SIZE];

    memset(buffer,'\0',BUFFER_SIZE);

    fd = open(FileName,O_RDONLY);

    if(fd == -1)
    {
        perror("Failed to open ");
        exit(EXIT_FAILURE);        
    }

    iRet = read(fd,buffer,BUFFER_SIZE);
    
    
    while(iRet > 0)
    {
        printf("Data from file is : %s \n",buffer);
        iRet = read(fd,buffer,BUFFER_SIZE);
    }
    if(iRet == 0)
    {
        printf("We reach at end of file\n");
    }
    if(iRet == -1)
    {
        perror("Failed to read");
        exit(EXIT_FAILURE); 
    }
    close(fd);
}
//////////////////////////////////////////////////////////////////
//
//  Function Name : main()   (entry point function)
//  Author        : Mangesh Ashok Bedre.
//  Date          : 23/12/2025
//
//////////////////////////////////////////////////////////////////

int main(int argc,char *argv[])
{   
    ReadFile(argv[1]);
      
    return 0;
}
