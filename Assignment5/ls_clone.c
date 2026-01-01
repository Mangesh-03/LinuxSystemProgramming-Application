// Directory Traversal Basics

// Create a program ls_clone.c that takes one directory path and prints:
// • Entry name
// • Type (file/dir/link/other)
// • Size (bytes)
// • Permissions in rwxr-xr-x format
// • Last modified time
// • Skip . and ..
// • Build full path using snprintf(dir + "/" + name).

///////////////////////////////////////////////////////////////////////////////
//
//  Required Header Files
//
///////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<time.h>
#include <sys/stat.h>
#include <inttypes.h>

///////////////////////////////////////////////////////////////////////////////
//
//  User Defined Macros
//
///////////////////////////////////////////////////////////////////////////////

#define SIZE 300

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   ShowDirectoryStat()
//  Description     :   Display Info of all files from Directory.
//  Input           :   char*
//  Output          :   -
//  Author          :   Mangesh Ashok Bedre.
//  Date            :   1/01/2026i Sh
//
///////////////////////////////////////////////////////////////////////////////

void ShowDirectoryStat(char *DirName)
{
    DIR *fd = NULL;
    struct dirent *ptr = NULL;
    char NewName[SIZE] ;
    struct stat sb;
    int iRet = 0;

    fd = opendir(DirName);

    if(fd == NULL)
    {
        perror("Unable to directory ");
        exit(EXIT_FAILURE);
    }

    memset(NewName,'\0',SIZE);

    while((ptr = readdir(fd)) != NULL)
    {
        snprintf(NewName,SIZE,"%s/%s",DirName,ptr->d_name);

        if(((strcmp(ptr->d_name,".")) == 0) || (strcmp(ptr->d_name,"..")) == 0)
        {
            continue;
        }

        iRet = lstat(NewName,&sb);

        if(iRet == -1)
        {
            perror("lstat failed ");
            exit(EXIT_FAILURE);
        }

        printf("File Name :               %s\n",ptr->d_name);
        printf("File size :               %jd bytes\n",(intmax_t)sb.st_size);
        printf("Last status change:       %s", ctime(&sb.st_ctime));
        printf("Last file access:         %s", ctime(&sb.st_atime));
        printf("Last file modification:   %s", ctime(&sb.st_mtime));
        switch (sb.st_mode & S_IFMT) 
        {
            case S_IFBLK:  
                printf("File type :               block device\n");            
                break;
            case S_IFCHR:  
                printf("File type :               character device\n");        
                break;
            case S_IFDIR:  
                printf("File type :               directory\n");            
                break;
            case S_IFIFO:  
                printf("File type :               FIFO/pipe\n");           
                break;
            case S_IFLNK:  
                printf("File type :               symlink\n");                 
                break;
            case S_IFREG:   
                printf("File type :               regular file\n");            
                break;
            case S_IFSOCK: 
                printf("File type :               socket\n");                 
                break;
            default:    
                printf("File type :               unknown?\n");           
                break;
        }

        printf("Permissions:              %c%c%c%c%c%c%c%c%c\n\n\n",
                    (sb.st_mode & S_IRUSR) ? 'r' : '-',
                    (sb.st_mode & S_IWUSR) ? 'w' : '-',
                    (sb.st_mode & S_IXUSR) ? 'x' : '-',
                    (sb.st_mode & S_IRGRP) ? 'r' : '-',
                    (sb.st_mode & S_IWGRP) ? 'w' : '-',
                    (sb.st_mode & S_IXGRP) ? 'x' : '-',
                    (sb.st_mode & S_IROTH) ? 'r' : '-',
                    (sb.st_mode & S_IWOTH) ? 'w' : '-',
                    (sb.st_mode & S_IXOTH) ? 'x' : '-'
                );

    }// End of while

}


///////////////////////////////////////////////////////////////////////////////
//
//  Function Name  :  main()     (Entry point Function)
//  Author         :  Mangesh Ashok Bedre.
//  Date           :  1/01/2026.
//
///////////////////////////////////////////////////////////////////////////////

int main(int argc, char **argv)
{   
    // Handing segmentation fault in case no agrument passed by user.
    if(argc == 2)
    {
        if((strcmp(argv[1],"--h") == 0) || (strcmp(argv[1],"--H") == 0))
        {
            printf("This is ls Utility.\n");
            printf("For gets to know about usage (flag => --u)\n");
        }
        else if((strcmp(argv[1],"--U") == 0) || (strcmp(argv[1],"--u") == 0))
        {
            printf("./<Executable_Name> <Directory_Name>\n");
        }
        else
        {
            printf("%s\n",argv[1]);
            ShowDirectoryStat(argv[1]);
        }
        
    }
    else
    {
        printf("Invalid Number of commandline Arguments\n");
        printf("Use the given flag as\n");
        printf("--h used to display help\n");
        printf("--u used to display usage\n");

        return -1;
    }

    return 0;
}