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
    
    fd = opendir(DirName);

    if(fd == NULL)
    {
        perror("Failed to open Directory");
        exit(EXIT_FAILURE);        
    }

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
    ReadDirectory(argv[1]);
      
    return 0;
}
