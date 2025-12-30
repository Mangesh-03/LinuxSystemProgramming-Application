// File Copy with Offset

// Problem Statement:
// Copy a file starting from a given byte offset of the source file.

// Input:
// source_file destination_file offset

// Output:
// Partial file copied starting from offset.

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
#include<stdlib.h>

///////////////////////////////////////////////////////////////////////////////
//
//  User Defined Macros
//
///////////////////////////////////////////////////////////////////////////////

#define BUFFER_SIZE 1024

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name  :  ChkFileExistAndPermission()
//  Description    :  Check file is exist and having proper permission.
//  Input          :  char
//  Output         :  bool
//  Author         :  Mangesh Ashok Bedre.
//  Date           :  29/12/2025.
//
///////////////////////////////////////////////////////////////////////////////

bool ChkFileExistAndPermission(char *FileName)
{
    //access() => used check file existance and permission.
   
    if(access(FileName,F_OK ) == -1)
    {
        printf("Error : Souce File %s not exists\n",FileName);
        printf("Reason : %s\n",strerror(errno));
        return false;
    }
    if(access(FileName,R_OK) == -1)
    {
        printf("Error : Souce File %s have no read permission\n",FileName);
        printf("Reason : %s\n",strerror(errno));
        return false;
    }
    return true;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function Name  :  CopyUtilityWithOffset()
//  Description    :  Copies the contents of one file into another.
//  Input          :  char*,char*,char*
//  Output         :  -
//  Author         :  Mangesh Ashok Bedre.
//  Date           :  29/12/2025.
//
///////////////////////////////////////////////////////////////////////////////

void CopyUtilityWithOffset(char *SourceFile, char *DesFile,char *offset)
{
    int fd1 = 0, fd2 = 0;
    int iRetRead = 0,iRetWrite = 0,iWritten = 0; 
    int offSet = 0,iRet = 0;

    offSet = atoi(offset);

    char Buffer[BUFFER_SIZE];

    char NewDest[1024] = {'\0'};

    //if we want to copy file in same dir 
    if(strcmp(SourceFile, DesFile) == 0)
    {
        snprintf(NewDest, sizeof(NewDest), "%s-copy", SourceFile);
        DesFile = NewDest;
    }

    fd1 = open(SourceFile,O_RDONLY);

    if(fd1 == -1)
    {
        printf("error : Unable to open Source File\n");
        printf("Reason : %s\n",strerror(errno));
        return;
    }

    fd2 = open(DesFile,O_WRONLY | O_CREAT | O_TRUNC,0777);
   
    if(fd2 == -1)
    {
        printf("error : Unable to open Destination File for writing\n");
        printf("Reason : %s\n",strerror(errno));
        close(fd1);
        return;
    }

    // memset() => used here for set default value in Buffer to avoid garbage
    memset(Buffer,'\0',BUFFER_SIZE);

    // lseek() => used for move offset bytes in Source file
    iRet = lseek(fd1,offSet,SEEK_SET);

    if(iRet == -1)
    {
        printf("Error : Failed to move offset \n");
        printf("Reason : %s\n",strerror(errno));
        close(fd1);
        close(fd2);
        return;
    }

    while((iRetRead = read(fd1,Buffer,BUFFER_SIZE)) > 0)
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
            iRetWrite = write(fd2,Buffer + iWritten,iRetRead - iWritten);

            if(iRetWrite == -1)
            {
                printf("Error : Failed to write into : %s\n",DesFile);
                printf("Reason : %s\n",strerror(errno));
                close(fd1);
                close(fd2);
                return;
            }
            iWritten += iRetWrite;
        }
        
        memset(Buffer,'\0',BUFFER_SIZE);
    }    


    if (iRetRead == -1)
    {
        perror("Read failed");
    }
    else
    {
        printf("Data copied successfully\n");
    }

    close(fd1);
    close(fd2);

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
    // Handing segmentation fault in case no agrument passed by user.
    if(argc == 2)
    {
        if((strcmp(argv[1],"--h") == 0) || (strcmp(argv[1],"--H") == 0))
        {
            printf("This is Copy File Utility.\n");
            printf("For gets to know about usage (flag => --u)\n");
        }
        else if((strcmp(argv[1],"--U") == 0) || (strcmp(argv[1],"--u") == 0))
        {
            printf("./<Executable_Name> <Source_FileName> <Destination_FileName> <offset>\n");
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
    else if(argc == 4)
    {
        // Check File is exists and proper permission.
        if(ChkFileExistAndPermission(argv[1]) == false)
        {
            printf("The source file is not exists\n");
            return -1;
        }
        
        CopyUtilityWithOffset(argv[1],argv[2],argv[3]);
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