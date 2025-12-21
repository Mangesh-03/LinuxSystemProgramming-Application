// • Accept file name and mode (read/write/execute).
// • Use access() to check permission for current process.
// • Print “Accessible / Not accessible” with reason.

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include <stdlib.h>

/////////////////////////////////////////////////////////////////
//
// Function name : ChkPermission()
// Description   : check file access permission.
// Input         : char*,char*
// output        : -
// Author        : Mangesh Ashok Bedre.
// Date          : 20/12/2025
//
/////////////////////////////////////////////////////////////////

void ChkPermission(char * FileName, char *mode)
{
    int permission = 0,iRet = 0;

    if((iRet = strcmp(mode,"read")) == 0)
    {
        permission = R_OK;
    }
    else if((iRet = strcmp(mode,"write")) == 0)
    {
        permission = W_OK;
    }
    else if((iRet = strcmp(mode,"execute")) == 0)
    {
        permission = X_OK;
    }

    iRet = access(FileName,permission | F_OK);

    if(iRet == 0)
    {
        printf("File has permission of %s\n",mode);
    }
    else
    {
        perror("File has no permission : ");
        exit(EXIT_FAILURE);
    }

}

//////////////////////////////////////////////////////////////////
//
//  Function Name : main()   (entry point function)
//  Author        : Mangesh Ashok Bedre.
//  Date          : 20/12/2025
//
//////////////////////////////////////////////////////////////////
int main()
{
    char FileName[50];
    char mode[30];
    
    memset(FileName,'\0',sizeof(FileName));

    printf("Enter the file name : \n");
    scanf("%s",FileName);

    memset(mode,'\0',sizeof(mode));

    printf("Enter the mode(read/write/execute) : \n");
    scanf(" %s",mode);

    ChkPermission(FileName,mode);

    return 0;
}