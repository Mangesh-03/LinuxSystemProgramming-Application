// List All Files From Directory
// • Accept directory name.
// • Use opendir() / readdir() to print only names (skip . and ..)

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/types.h>
#include <dirent.h>

/////////////////////////////////////////////////////////////////
//
// Function name : ReadDirectory()
// Description   : Read the Directory and list All Files From Directory.
// Input         : char*
// output        : -
// Author        : Mangesh Ashok Bedre.
// Date          : 23/12/2025
//
/////////////////////////////////////////////////////////////////


void ReadDirectory(char * DirName)
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
        if((strcmp(ptr->d_name,".")) == 0)
        {
            continue;
        }
        else if((strcmp(ptr->d_name,"..")) == 0)
        {
            continue;
        }
        printf("Name of file : %s\n",ptr->d_name);    
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
    if(argc != 2)
    {
        printf("Usage: %s <Directory_name> \n", argv[0]);
        return -1;
    }

    ReadDirectory(argv[1]);
      
    return 0;
}
