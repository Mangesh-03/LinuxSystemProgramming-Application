// Recursive Directory Traversal

// Write tree_clone.c which prints a directory as a tree, like:

// root/
//      a.txt
//      src/
//          Ganesh.c

// • Indentation based on recursion depth
// • Print type markers:
// ◦ [D] directory
// ◦ [F] regular file
// ◦ [L] symbolic link

// • Use lstat() to detect symbolic links.
// • Do not follow symlink directories (avoid loops).

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
//  Function Name : PrintIndent
//  Description   : Use to print proper spaces .
//  Author        : Mangesh Ashok Bedre.
//  Date          : 1/01/2026.
//
///////////////////////////////////////////////////////////////////////////////

void PrintIndent(int depth)
{
    for(int i = 0; i < depth; i++)
    {
        printf("    ");   // 4 spaces per level
    }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   RecursiveDirTraversal()
//  Description     :   Traversal directory recursively and create 
//                      hierarcal file system.
//
//  Input           :   char*
//  Output          :   -
//  Author          :   Mangesh Ashok Bedre.
//  Date            :   1/01/2026i Sh
//
///////////////////////////////////////////////////////////////////////////////

void RecursiveDirTraversal(char *DirName)
{
    DIR *fd = NULL;
    struct dirent *ptr = NULL;
    char NewName[SIZE];
    struct stat sb;
    char *chptr = NULL;

    static int depth = 0;
    
    fd = opendir(DirName);
    if(fd == NULL)
    {
        perror(DirName);
        return;
    }
    //Printing only Name of Directory not all Path
    chptr = DirName;

    while(*chptr != '\0')
    {
        chptr++;
    }
    chptr--;
    while(*chptr != '/')
    {
        chptr--;
    }
    chptr++;

    PrintIndent(depth);
    printf("[D] %s/\n",chptr);
    
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
            PrintIndent(depth + 1);
            printf("[L] %s\n",ptr->d_name);
        }
        else if(S_ISREG(sb.st_mode))
        {
            PrintIndent(depth + 1);
            printf("[F] %s\n",ptr->d_name);
        }
        else if(S_ISDIR(sb.st_mode))
        {
            depth++;
            RecursiveDirTraversal(NewName); // recursion
            depth--;  
        }
    }// End of while

    closedir(fd);
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
    if(argc != 2)
    {
        printf("Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    RecursiveDirTraversal(argv[1]);
    
    return 0;
}