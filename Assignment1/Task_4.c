// • Accept file name and display file metadata using stat():
// • Size, inode, permissions, hard links, owner uid/gid, 
//   file type, last access/modify time.

#include<stdio.h>
#include<string.h>
#include<errno.h>
#include <sys/stat.h>

/////////////////////////////////////////////////////////////////
//
// Function name : DisplayInfo()
// Description   : Display Complete File Information.
// Input         : char*
// output        : -
// Author        : Mangesh Ashok Bedre.
// Date          : 20/12/2025
//
/////////////////////////////////////////////////////////////////

void DisplayInfo(char * FileName)
{
    int iRet = 0;
    struct stat Buffer;

    iRet = stat(FileName,&Buffer);

    if(iRet == 0)
    {
        printf("Inode Number : %ld\n", Buffer.st_ino);
        printf("File Size   : %ld bytes\n", Buffer.st_size);
        printf("Hard Links  : %ld\n", Buffer.st_nlink);
        printf("User ID     : %d\n", Buffer.st_uid);
        printf("Group ID    : %d\n", Buffer.st_gid);
        printf("Permissions : %o\n", Buffer.st_mode & 0777);
    }
    else
    {
        perror("Error");
    }
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
    
    memset(FileName,'\0',sizeof(FileName));

    printf("Enter the file name : \n");
    scanf("%s",FileName);

    DisplayInfo(FileName);

    return 0;
}