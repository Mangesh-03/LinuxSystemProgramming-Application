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
    
    // access() -> to check File has permission or not
    iRet = access(FileName,permission | F_OK);

    if(iRet == 0)
    {
        printf("File has permission of %s\n",mode);
    }
    else
    {
        perror("Error ");
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
int main(int argc,char **argv)
{
    //Handing segmentation fault in case no agrument passed by user.
    if(argc != 3)
    {
        printf("Usage: %s <file_name> <mode(read,write,execute)>\n", argv[0]);
        return -1;
    }

    ChkPermission(argv[1],argv[2]);

    return 0;
}