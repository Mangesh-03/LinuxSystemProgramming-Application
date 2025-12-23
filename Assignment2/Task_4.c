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
    
    fd = opendir(DirName);

    if(fd == NULL)
    {
        perror("Failed to open Directory");
        exit(EXIT_FAILURE);        
    }

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
    ChkType(argv[1]);
      
    return 0;
}
