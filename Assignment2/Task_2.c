// Write String to File
// • Accept file name and a string from user.
// • Write string using write() (append mode by default).
// • Print number of bytes written.

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
// Function name : WriteFile()
// Description   : Write given string into File
// Input         : char*
// output        : void
// Author        : Mangesh Ashok Bedre.
// Date          : 23/12/2025
//
/////////////////////////////////////////////////////////////////


void WriteFile(char * FileName,char * str)
{
    int fd = 0,iRet = 0;
    
    //open() = used to open files.
    fd = open(FileName,O_WRONLY | O_APPEND);

    if(fd == -1)
    {
        //perror() -> Handling error using errno ,printed it at stderr
        perror("Failed to open ");

        // exit() -> function causes normal process termination and
        //           send status to parent.
        exit(EXIT_FAILURE);        
    }


    // write() -> used to write data into file.
    iRet = write(fd,str,sizeof(str));

    if(iRet <= 0)
    {
        //perror() -> Handling error using errno ,printed it at stderr
        perror("Failed to wite");

        // exit() -> function causes normal process termination and
        //           send status to parent.
        exit(EXIT_FAILURE); 
    }
    printf("Data written into file %d bytes\n",iRet);

    // close() => used to close fd of file
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
    if(argc != 3)
    {
        printf("Usage: %s <file_name> <string> \n", argv[0]);
        return -1;
    }

    WriteFile(argv[1],argv[2]);
      
    return 0;
}
