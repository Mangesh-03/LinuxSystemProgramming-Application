// Delete All Empty Regular Files
// • Accept directory name.
// • Delete files with size = 0 bytes (regular files only).
// • Print names deleted + total deleted count.

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/stat.h> 
#include <sys/types.h>
#include <dirent.h>

/////////////////////////////////////////////////////////////////
//
//  User Defined Macros
//
/////////////////////////////////////////////////////////////////

#define MAX_PATH 512

/////////////////////////////////////////////////////////////////
//
// Function name : DeleteEmptyFile()
// Description   : Delete All Empty Regular Files.
// Input         : char*
// output        : void
// Author        : Mangesh Ashok Bedre.
// Date          : 23/12/2025
//
/////////////////////////////////////////////////////////////////

void DeleteEmptyFile(char *DirName)
{
    DIR * fd = NULL;
    struct dirent * ptr = NULL;
    struct stat sobj ;
    int iRet = 0,iCount = 0;
    char AbsPath[MAX_PATH] ={'\0'} ;
    
    fd = opendir(DirName);

    if(fd == NULL)
    {
        perror("Unable to open directory : ");
        return;
    }

    while((ptr = readdir(fd)) != NULL)
    {
        if(strcmp(ptr->d_name,".")==0)
        {
            continue;
        }
        else if(strcmp(ptr->d_name,"..")==0)
        {
            continue;
        }

        // flavour of printf for making absoulate path
        // via realpath() call -> this attch fileName with path of CWD.
        // realpath() works when operation happen in CWD otherwise being failed

        snprintf(AbsPath, MAX_PATH, "%s/%s", DirName, ptr->d_name);

        printf("Abs : %s\n",AbsPath);
        printf("ptr->name : %s\n",ptr->d_name);

        iRet = stat(AbsPath,&sobj);
        if(iRet == -1)
        {
            perror("Failed to get stat:");
            return;
        }
        if(S_ISREG(sobj.st_mode))
        {
            if(sobj.st_size == 0)
            {
                if(unlink(AbsPath) == 0)
                {
                    printf("File is deleted successfully\n");
                    printf("Name of File : %s\n",ptr->d_name);
                    iCount++;
                }
            }
        }
    }

    printf("Total number file deleted are : %d\n",iCount);

    closedir(fd);

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
    if(argc != 2)
    {
        printf("Usage: %s <DirectoryName> \n", argv[0]);
        return -1;
    }

    DeleteEmptyFile(argv[1]);
      
    return 0;
}
