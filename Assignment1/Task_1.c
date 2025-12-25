// • Accept file name from user and open it using open().
// • Print: success message + returned file descriptor.
// • Handle errors using perror().

////////////////////////////////////////////////////////////////
//
// Header Files
//
////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>

/////////////////////////////////////////////////////////////////
//
// Function name : OpenFile
// Description   : open file with given name of file.
// Input         : char*
// output        : void
// Author        : Mangesh Ashok Bedre.
// Date          : 20/12/2025
//
/////////////////////////////////////////////////////////////////

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
    close(fd);   
}
//////////////////////////////////////////////////////////////////
//
//  Function Name : main()   (entry point function)
//  Author        : Mangesh Ashok Bedre.
//  Date          : 20/12/2025
//
//////////////////////////////////////////////////////////////////
int main(int argc, char **argv)
{
    //Handing segmentation fault in case no agrument passed by user.
    if(argc != 2)
    {
        printf("Usage: %s <File_name> \n", argv[0]);
        return -1;
    }

    OpenFile(argv[1]);
    
    return 0;
}
