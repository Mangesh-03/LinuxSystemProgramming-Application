// Check File Present in Directory
// • Accept directory name and file name.
// • Check whether that file exists in that directory.
// • Print absolute matched path if found.

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<stdbool.h>
#include <dirent.h>
#include <sys/types.h>

/////////////////////////////////////////////////////////////////
//
//  User Defined Macros
//
/////////////////////////////////////////////////////////////////

#define MAX_PATH 512

/////////////////////////////////////////////////////////////////
//
// Function name : ChkFilePresentInDir()
// Description   : Check File Present in Directory
// Input         : char*,char*
// output        : void
// Author        : Mangesh Ashok Bedre.
// Date          : 23/12/2025
//
/////////////////////////////////////////////////////////////////

void ChkFilePresentInDir(char *DirName, char *FileName)
{
    DIR *fdDir = NULL;
    struct dirent *ptr = NULL;
    bool bFlag = false;
    char AbsolutePath[MAX_PATH] = {'\0'};

    fdDir = opendir(DirName);
    
    if(fdDir == NULL)
    {
        perror("Failed to open directory : ");
        return;
    }

    while((ptr = readdir(fdDir)) != NULL)
    {
        if(strcmp(ptr->d_name,FileName) == 0)
        {
            printf("File is present in this directory\n");
            bFlag = true;
            break;
        }
    }

    if(bFlag == false)
    {
        printf("File is not present in this directory\n");
        return;
    }

    if((realpath(FileName,AbsolutePath)) == NULL)
    {
        perror("Failed to get absolute path : ");
        return;
    }

    printf("Absolute path of file is : %s\n",AbsolutePath);

    closedir(fdDir);
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
    if(argc != 3)
    {
        printf("Usage: %s <Directory_Name> <File_Name>\n", argv[0]);
        return -1;
    }

    ChkFilePresentInDir(argv[1],argv[2]);
      
    return 0;
}
