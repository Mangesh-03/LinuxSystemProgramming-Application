// List Files with Type
// • Accept directory name.
// • Print each entry with its type: Regular / Directory / Link / FIFO / Socket / Char / Block
// • Use lstat() for accurate type.

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include <sys/types.h>
#include <dirent.h>

/////////////////////////////////////////////////////////////////
//
// Function name : ChkType()
// Description   : List Files with Type.
// Input         : char*
// output        : -
// Author        : Mangesh Ashok Bedre.
// Date          : 23/12/2025
//
/////////////////////////////////////////////////////////////////


void ChkType(char * DirName)
{
    DIR *fd = NULL;
    struct dirent *ptr =  NULL;
    
    // opendir() => used to open directory file.
    fd = opendir(DirName);

    if(fd == NULL)
    {
        perror("Failed to open Directory");
        exit(EXIT_FAILURE);        
    }

    // readdir() => read data drom directory , return pointer pointing to dirent struct.
    while((ptr = readdir(fd)) != NULL)
    {
        printf("Name of file : %s\n",ptr->d_name);
        
        if(ptr->d_type == DT_BLK)
        {
            printf("File type : Device file\n\n");
        }
        else if(ptr->d_type == DT_REG)
        {
            printf("File type : Regular file\n\n");
        }
        else if(ptr->d_type == DT_DIR)
        {
            printf("File type : Directory file\n\n");
        }
        else if(ptr->d_type == DT_LNK)
        {
            printf("File type : Symbolic link\n\n");
        }
        else if(ptr->d_type == DT_CHR)
        {
            printf("File type : character device\n\n");
        }
    }
    
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
    ChkType(argv[1]);
      
    return 0;
}
