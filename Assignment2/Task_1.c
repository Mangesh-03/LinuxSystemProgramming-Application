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

    // memset() -> used here for initialed buffer with default value.
    memset(buffer,'\0',BUFFER_SIZE);

    // open() -> for open regular file.
    fd = open(FileName,O_RDONLY);

    if(fd == -1)
    {
        perror("Failed to open ");

        // exit() -> function causes normal process termination and
        //           send status to parent.
        exit(EXIT_FAILURE);        
    }

    // read() -> used to read data from the file.
    iRet = read(fd,buffer,BUFFER_SIZE);
    printf("Data from file is : %s \n",buffer);
    
    while(iRet > 0)
    {
        //memset() => used to flush and clean
        memset(buffer,'\0',BUFFER_SIZE);
        
        iRet = read(fd,buffer,BUFFER_SIZE);
        
        printf(" %s",buffer);
    }
    if(iRet == 0)
    {
        printf("We reach at end of file\n");
    }
    if(iRet == -1)
    {
        //perror() -> Handling error using errno ,printed it at stderr
        perror("Failed to read");
        
        // exit() -> function causes normal process termination and
        //           send status to parent.
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
    // Handing segmentation fault in case no agrument passed by user.
    if(argc != 2)
    {
        printf("Usage: %s <file_name> \n", argv[0]);
        return -1;
    }

    ReadFile(argv[1]);
      
    return 0;
}
