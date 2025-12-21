// • Accept file name from user and open it using open().
// • Print: success message + returned file descriptor.
// • Handle errors using perror().


/////////////////////////////////////////////////////////////////
//
// Function name : OpenFile
// Description   : open file with given name of file.
// Input         : char*
// output        : int
// Author        : Mangesh Ashok Bedre.
// Date          : 20/12/2025
//
/////////////////////////////////////////////////////////////////

#include<stdio.h>
#include <fcntl.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>

void OpenFile(char * FileName)
{
    int fd = 0;

    fd = open(FileName,O_RDONLY);

    if(fd == -1)
    {
        perror("Failed to open ");
        exit(EXIT_FAILURE);        
    }
    printf("File open successfully with fd %d\n",fd);    
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

    memset(FileName,'\0',sizeof(FileName));

    printf("Enter the Name of File to be open : \n");
    scanf("%s['^\n']",FileName);

    OpenFile(FileName);
    
    return 0;
}
