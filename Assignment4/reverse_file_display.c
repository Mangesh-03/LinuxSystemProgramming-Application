// Reverse File Content

// Problem Statement:
// Display the contents of a file in reverse order.

// Input:
// File name.

// Output:
// File content printed in reverse.

///////////////////////////////////////////////////////////////////////////////
//
//  Required Header Files.
//
///////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<sys/stat.h>
#include<stdbool.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<fcntl.h>

///////////////////////////////////////////////////////////////////////////////
//
//  User Defined Macros
//
///////////////////////////////////////////////////////////////////////////////

#define BUFFER_SIZE 1024
#define SUCCESS 1

#define UNABLE_TO_OPEN -2
#define FAILED_TO_WRITE -3
#define FAILED_TO_READ -4
#define FAILED_TO_SET_OFFSET -5

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name  :  IsFile()
//  Description    :  Check given name is file or not.
//  Input          :  char*
//  Output         :  -
//  Author         :  Mangesh Ashok Bedre.
//  Date           :  29/12/2025.
//
///////////////////////////////////////////////////////////////////////////////

bool IsFile(char *FileName)
{
    struct stat sobj;
    int iRet = 0;

    iRet = stat(FileName,&sobj);

    if(iRet == -1)
    {
        return false;
    }

    if((sobj.st_mode & S_IFMT) == S_IFREG)
    {
        return true;    //regular file
    }
   
    return false;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name  :  DisplayReverse()
//  Description    :  Display the file content in reverse order.
//  Input          :  char* 
//  Output         :  -
//  Author         :  Mangesh Ashok Bedre.
//  Date           :  29/12/2025.
//
///////////////////////////////////////////////////////////////////////////////

int DisplayReverse(char *FileName)
{
    int fd = 0;
    char ch = '\0';
    int iRet = 0;
    off_t offSet = 0;


    fd = open(FileName,O_RDONLY);

    if(fd == -1)
    {
        return UNABLE_TO_OPEN;
    }

    offSet = lseek(fd,0,SEEK_END);

    if(offSet == -1)
    {
        close(fd);
        return FAILED_TO_SET_OFFSET;
    }

    for(off_t iCnt = offSet - 1; iCnt >= 0; iCnt--)
    {
        offSet = lseek(fd,iCnt,SEEK_SET);

        if(offSet == -1)
        {
            return FAILED_TO_SET_OFFSET;
        }

        iRet = read(fd,&ch,1);

        if(iRet == -1)
        {
            return FAILED_TO_READ;
        }

        iRet = write(1,&ch,1);

        if(iRet == -1)
        {
            return FAILED_TO_WRITE;
        }
        
    }

    
    close(fd);

    return SUCCESS;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name  :  main()     (Entry point Function)
//  Author         :  Mangesh Ashok Bedre.
//  Date           :  29/12/2025.
//
///////////////////////////////////////////////////////////////////////////////

int main(int argc, char **argv)
{  
    char *OutputFile = NULL;
    char **InputFilesName = NULL;
    int InputCount = 0,iRet = 0;

    // Handing segmentation fault in case no agrument passed by user.
    if(argc == 2)
    {
        if((strcmp(argv[1],"--h") == 0) || (strcmp(argv[1],"--H") == 0))
        {
            printf("This is File Merge Utility.\n");
            printf("For gets to know about usage (flag => --u)\n");
        }
        else if((strcmp(argv[1],"--U") == 0) || (strcmp(argv[1],"--u") == 0))
        {
            printf("./<Executable_Name> <Output_File> <FileName>...\n");
        }
        else
        {
            iRet = DisplayReverse(argv[1]);

            if(iRet == UNABLE_TO_OPEN)
            {
                printf("Unable to open file\n");
                printf("Reason : %s\n",strerror(errno));
            }
            else if(iRet == FAILED_TO_READ)
            {
                printf("Error : Failed to read\n");
                printf("Reason : %s\n",strerror(errno));
            }
            else if(iRet == FAILED_TO_SET_OFFSET)
            {
                printf("Unable to set offset at end\n");
                printf("Reason : %s\n",strerror(errno));
            }
            else if(iRet == SUCCESS)
            {
                printf("\nDisplay file content in reverse order done successfully\n");
            }
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