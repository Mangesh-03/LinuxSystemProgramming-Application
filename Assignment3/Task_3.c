// Move All Files (Dir → Dir)
// • Accept source dir and destination dir.
// • Move all regular files:
//  ◦ Use rename() if same filesystem
//  ◦ Else copy + delete
// • Print count of moved files.

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
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
// Function name : MvFileDirToDir()
// Description   : Move All Files (Dir → Dir).
// Input         : char*,char*
// output        : void
// Author        : Mangesh Ashok Bedre.
// Date          : 23/12/2025
//
/////////////////////////////////////////////////////////////////

void MvFileDirToDir(char *src, char *des)
{
    //get src
    // ori = src + "/" + ptr.name
    // new = des + "/" + ptr.name
    //opendir src -> readdir -> rename(ori,new)

    DIR *fd = NULL;
    struct dirent *ptr = NULL;

    char original[MAX_PATH] = {'\0'};
    char new[MAX_PATH] = {'\0'};
    
    // making errno = 0 ,to check readdir is failed due to end stream 
    // or any error occured.
    errno = 0;

    fd = opendir(src);

    if(fd == NULL)
    {
        printf("Unable to open dir : %s\n",strerror(errno));
        return;
    }

    while((ptr = readdir(fd)) != NULL)
    {
        // making path at original position
        snprintf(original,MAX_PATH,"%s/%s",src,ptr->d_name);

        // making path for new position(i.e. moving position)
        snprintf(new,MAX_PATH,"%s/%s",des,ptr->d_name);

        rename(original,new);
        
    }

    if(errno != NULL)
    {
        printf("Moved successsfully\n");
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
    if(argc != 3)
    {
        printf("Usage: %s <Source_file> <Dest_file>\n", argv[0]);
        return -1;
    }

    MvFileDirToDir(argv[1],argv[2]);
      
    return 0;
}