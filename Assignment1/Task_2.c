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

void OpenFile(char * FileName,char mode)
{
    int fd = 0;
    int iFlag = 0;

    switch(mode)
    {
        case 'R':
            iFlag = O_RDONLY ;
            break;

        case 'W':
            iFlag = O_WRONLY | O_CREAT;
            break;
            
        case 'r':
            iFlag = O_RDWR | O_CREAT;
            break;

        case 'A':
            iFlag = O_WRONLY | O_APPEND | O_CREAT;
            break;

        default:
            printf("Invalid mode\n");
            exit(EXIT_FAILURE);
    }

    fd = open(FileName,iFlag,0777);

    if(fd == -1)
    {
        perror("Failed to open");
        exit(EXIT_FAILURE);        
    }
    printf("File open successfully with fd %d with mode : %c\n",fd,mode);    
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
    char FileName[100];
    char mode = '\0';

    memset(FileName,'\0',sizeof(FileName));

    printf("Enter the Name of File to be open : \n");
    scanf("%s",FileName);

    printf("Enter mode for open file (R, W, r(RW), A)\n");
    scanf(" %c",&mode);

    OpenFile(FileName,mode);
    
    return 0;
}