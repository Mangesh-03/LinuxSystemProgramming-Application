// File Counter + Size Report
// Create dir_report.c that recursively calculates:
// • Total number of files
// • Total number of directories
// • Total size of regular files (in bytes)
// • Largest file name + size
// • Count a directory when you enter it.
// • For size: consider only regular files (S_ISREG).
// • Ignore symlink target size (treat symlink as link object only).

///////////////////////////////////////////////////////////////////////////////
//
//  Required Header Files
//
///////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<inttypes.h>

#include <limits.h> // for PATH MAX => file path size limit in linux

///////////////////////////////////////////////////////////////////////////////
//
//  User Defined Macros
//
///////////////////////////////////////////////////////////////////////////////

#define SIZE PATH_MAX

///////////////////////////////////////////////////////////////////////////////
//
//  Struct Name : Report
//  Description : Use to store information about directory .
//  Author      : Mangesh Ashok Bedre.
//  Date        : 1/01/2026.
//
///////////////////////////////////////////////////////////////////////////////

struct Report
{
    char MaxFileName[SIZE];

    int iFileCount ;
    int iDirCount ;
    off_t iSize ;
    off_t iMax;

}robj;

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   DirReport()
//  Description     :   Traversal directory recursively and give stat/report.
//  Input           :   char*
//  Output          :   -
//  Author          :   Mangesh Ashok Bedre.
//  Date            :   1/01/2026
//
///////////////////////////////////////////////////////////////////////////////

void DirReport(char *DirName)
{
    DIR *fd = NULL;
    struct dirent *ptr = NULL;
    char NewName[SIZE];
    struct stat sb;
    
    fd = opendir(DirName);
    if(fd == NULL)
    {
        perror(DirName);
        return;
    }
    
    // struct Report robj => uses to store recursive info
    // robj is global varible
    robj.iDirCount++;   // count directory when entered

    while((ptr = readdir(fd)) != NULL)
    {
        if(strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0)
            continue;

        snprintf(NewName, SIZE, "%s/%s", DirName, ptr->d_name);

        if(lstat(NewName, &sb) == -1)
        {
            perror(NewName);
            continue;
        }

        if(S_ISLNK(sb.st_mode))
        {
            continue;   // ignore symlink target size
        }
        else if(S_ISREG(sb.st_mode))
        {
            robj.iFileCount++;
            robj.iSize += sb.st_size;

            if(sb.st_size > robj.iMax)
            {
                robj.iMax = sb.st_size;

                // Copying path instead of name only bcz file may duplicate in another dir 
                strcpy(robj.MaxFileName, NewName);  
            }
        }
        else if(S_ISDIR(sb.st_mode))
        {
            DirReport(NewName);   // recursion
        }
    }// End of while

    closedir(fd);
}


///////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   DisplayReport()
//  Description     :   Display directory stat/report.
//  Input           :   -
//  Output          :   -
//  Author          :   Mangesh Ashok Bedre.
//  Date            :   1/01/2026.
//
///////////////////////////////////////////////////////////////////////////////

void DisplayReport()
{
    printf("Total Files:                 %d\n",robj.iFileCount);
    printf("Total Dir:                   %d\n",robj.iDirCount);
    printf("Total Size:                  %jd bytes\n",(intmax_t)robj.iSize);
    printf("Largest File:                %s (%jd bytes)\n",robj.MaxFileName,(intmax_t)robj.iMax);
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
            printf("This is dir report Utility.\n");
            printf("For gets to know about usage (flag => --u)\n");
        }
        else if((strcmp(argv[1],"--U") == 0) || (strcmp(argv[1],"--u") == 0))
        {
            printf("./<Executable_Name> <Directory_Name>\n");
        }
        else
        {
            DirReport(argv[1]);
            DisplayReport();
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