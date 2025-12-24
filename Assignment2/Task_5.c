// Find Largest File in Directory
// • Accept directory name.
// • Find and print:
// ◦ largest file name
// ◦ its size in bytes
// • Consider only regular files (ignore directories).

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>

/////////////////////////////////////////////////////////////////
//
// Function name : LargeFile()
// Description   : List Files name .
// Input         : char*
// output        : -
// Author        : Mangesh Ashok Bedre.
// Date          : 23/12/2025
//
/////////////////////////////////////////////////////////////////


void LargeFile(char * DirName)
{
    DIR *fd = NULL;
    struct dirent *ptr =  NULL;
    
    struct stat sobj;
    int iRet = 0,max = 0;
    
    char *str = {'\0'};
    
    fd = opendir(DirName);

    if(fd == NULL)
    {
        perror("Failed to open Directory");
        exit(EXIT_FAILURE);        
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

        // stat() => used retrive metadata about file from inode
        iRet = stat(ptr->d_name,&sobj);
        if(iRet == -1)
        {
            perror("Error in stat : ");
            exit(EXIT_FAILURE);
        }
        // printf("file name : %s and its size is %ld bytes\n",ptr->d_name,sobj.st_size);
        
        if(sobj.st_size > max)
        {
            str = ptr->d_name;
            max = sobj.st_size;
        }

    }
    
    printf("\nLargest file name : %s and its size is %d bytes\n",str,max);
    
    // closedir() => function closes the directory stream associated  with dirp.
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
    // Handing segmentation fault in case no agrument passed by user.
    if(argc != 3)
    {
        printf("Usage: %s <Directory_name> \n", argv[0]);
        return -1;
    }

    LargeFile(argv[1]);
      
    return 0;
}
