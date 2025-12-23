// • Accept file name and mode (R, W, RW, A) from user.
// • Convert mode to flags (O_RDONLY, O_WRONLY, O_RDWR, O_APPEND | O_CREAT).
// • Open file accordingly and display fd.

#include<stdio.h>
#include <fcntl.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>

/////////////////////////////////////////////////////////////////
//
// Function name : OpenFile
// Description   : open file with given name and mode.
// Input         : char*,char
// output        : -
// Author        : Mangesh Ashok Bedre.
// Date          : 20/12/2025
//
/////////////////////////////////////////////////////////////////

void OpenFile(char *FileName,char *mode)
{
    int fd = 0;
    int iFlag = 0;

    if((strcmp(mode,"r")) == 0)
    {
        iFlag = O_RDWR | O_CREAT;
    }
    else if((strcmp(mode,"R")) == 0)
    {
        iFlag = O_RDONLY;
    }
    else if((strcmp(mode,"W")) == 0)
    {
        iFlag = O_WRONLY | O_CREAT;
    }
    else if((strcmp(mode,"A")) == 0)
    {
        iFlag = O_WRONLY | O_APPEND | O_CREAT;
    }
    else
    {
        perror("Invalid mode :");
        exit(EXIT_FAILURE);
    }

    fd = open(FileName,iFlag,0777);

    if(fd == -1)
    {
        perror("Failed to open");
        exit(EXIT_FAILURE);        
    }
    printf("File open successfully with fd %d with mode : %s\n",fd,mode);  
    close(fd);  
}
//////////////////////////////////////////////////////////////////
//
//  Function Name : main()   (entry point function)
//  Author        : Mangesh Ashok Bedre.
//  Date          : 20/12/2025
//
//////////////////////////////////////////////////////////////////
int main(int argc,char **argv)
{
    
    OpenFile(argv[1],argv[2]);
    
    return 0;
}