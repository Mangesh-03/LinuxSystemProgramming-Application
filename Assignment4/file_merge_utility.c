// File Merge Utility

// Problem Statement:
// Merge multiple input files into a single output file.

// Input:
// output_file file1 file2 file3 ...

// Output:
// Combined file content in order.


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
#define MERGE_SUCCESS  1

#define UNABLE_TO_OPEN -2
#define FAILED_TO_WRITE -3
#define FAILED_TO_READ -4

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
//  Function Name  :  MergeUtility()
//  Description    :  Merge the contents of files into one file.
//  Input          :  char*,char**,int 
//  Output         :  int
//  Author         :  Mangesh Ashok Bedre.
//  Date           :  29/12/2025.
//
///////////////////////////////////////////////////////////////////////////////

int MergeUtility(char *OutputFile,char **MergeFiles,int FilesCount)
{
    int fd1 = 0,fd2 = 0;
    char Buffer[BUFFER_SIZE];
    int iRetRead = 0,iRetWrite = 0,iWritten = 0;

    memset(Buffer,'\0',BUFFER_SIZE);

    fd1 = open(OutputFile,O_WRONLY | O_TRUNC | O_CREAT,0777);

    if(fd1 == -1)
    {
        return UNABLE_TO_OPEN;
    }

    for(int iCnt = 0 ; iCnt < FilesCount; iCnt++)
    {
        // IsFile() => to skipping non-regular files.
        if((IsFile(MergeFiles[iCnt])) == false)
        {
            printf("%s is not regular file ,skip it\n",MergeFiles[iCnt]);
            continue;
        }

        fd2 = open(MergeFiles[iCnt],O_RDONLY);
        
        if(fd2 == -1)
        {
            perror(MergeFiles[iCnt]);
            continue;
        }

        while((iRetRead = read(fd2,Buffer,BUFFER_SIZE)) > 0)
        {
            iWritten = 0;

            /*
                This Loop Specially designed by considering partial write problem,
                partial read means not write all bytes which are given in parameter
                due to differ size of  system buffer and program local buffer but 
                if Buffer size is compatible to Destination loop execute once
            */
            while(iWritten < iRetRead)
            {
                /* 
                    write() => used to write .

                    here 2nd parameter looks weird but as handling partial writing
                    we use pointer arthimetic for write proper data from buffer.
                */
                iRetWrite = write(fd1,Buffer + iWritten,iRetRead - iWritten);

                if(iRetWrite == -1)
                {
                    close(fd1);
                    close(fd2);
                    return FAILED_TO_WRITE;
                }
                iWritten += iRetWrite;

            }// End of while

            memset(Buffer,'\0',BUFFER_SIZE);

        }//End of While

        if(iRetRead == -1)
        {
            return FAILED_TO_READ;
        }
        // After one file gets mergerd add new line and avoid new line at last file
        if(iCnt != FilesCount - 1)
        {
            write(fd1, "\n", 1);
        }

        close(fd2);

    }//End of For loop

    close(fd1);

    return MERGE_SUCCESS;
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
            printf("Invalid Number of commandline Arguments\n");
            printf("Use the given flag as\n");
            printf("--h used to display help\n");
            printf("--u used to display usage\n");

            return -1;
        }
        
    }
    else if(argc >= 3)
    {
        OutputFile = argv[1];
        InputFilesName = &argv[2];
        InputCount = argc - 2;
        
        iRet = MergeUtility(OutputFile,InputFilesName,InputCount);

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
        else if(iRet == MERGE_SUCCESS)
        {
            printf("Merge of files done successfully\n");
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