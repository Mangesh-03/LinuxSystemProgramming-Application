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
#include <sys/stat.h>

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
    struct stat sobj ;
    int iRet = 0;

    char path[1024] = {'\0'};
    
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

        // flavour of printf for making absoulate path
        // via realpath() call -> this attch fileName with path of CWD.
        // realpath() works when operation happen in CWD otherwise being failed
        snprintf(path,1024,"%s/%s",DirName,ptr->d_name);

        iRet = lstat(path,&sobj);

        if(iRet == -1)
        {
            printf("Unable to get stat %s\n",strerror(errno));
            return;
        }

        switch(sobj.st_mode & S_IFMT) 
        {
            case S_IFBLK:  
                printf("block device\n");            
                break;

            case S_IFCHR:  
                printf("character device\n");      
                break;

            case S_IFDIR:  
                printf("directory\n");              
                break;
            case S_IFIFO:  
                printf("FIFO/pipe\n");               
                break;

            case S_IFLNK:  
                printf("symlink\n");                 
                break;

            case S_IFREG:  
                printf("regular file\n");            
                break;

            case S_IFSOCK: 
                printf("socket\n");                  
                break;

            default:       
                printf("unknown?\n");                
                break;
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
    if(argc != 2)
    {
        printf("Usage: %s <Directory_name> \n", argv[0]);
        return -1;
    }
    ChkType(argv[1]);
      
    return 0;
}
