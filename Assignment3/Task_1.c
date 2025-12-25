// Copy File Contents (source → destination)
// • Accept source_file and dest_file.
// • Create destination if not exists (O_CREAT | O_TRUNC).
// • Copy using buffered read()/write() loop.
// • Preserve permissions (optional bonus using stat() + chmod()).

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/stat.h>

/////////////////////////////////////////////////////////////////
//
//  User Defined Macros
//
/////////////////////////////////////////////////////////////////

#define BUFFER_SIZE 1024

/////////////////////////////////////////////////////////////////
//
// Function name : CopyFileData()
// Description   : Copy File Contents from source to destination.
// Input         : char*,char*
// output        : void
// Author        : Mangesh Ashok Bedre.
// Date          : 23/12/2025
//
/////////////////////////////////////////////////////////////////

void CopyFileData(char *src, char *des)
{
    int fd1 = 0,fd2 = 0,iRetSrc = 0,iRetDes = 0,iRet = 0;
    char buffer[BUFFER_SIZE];
    struct stat sobj;

    memset(buffer,'\0',BUFFER_SIZE);

    iRet = stat(src,&sobj);

    fd1 = open(src,O_RDONLY);
    fd2 = open(des,O_CREAT | O_TRUNC | O_WRONLY,0777);

    if(iRet == 0)
    {
        chmod(des,sobj.st_mode);
    }

    if(( fd1 == -1 ) || (fd2 == -1))
    {
        perror("Failed to open file");
        return;        
    }
    
    // while for read whole file and write it into destination
    while((iRetSrc = read(fd1,buffer,BUFFER_SIZE)) > 0)
    {
        iRetDes = write(fd2,buffer,iRetSrc);

        if(iRetDes == -1)
        {
            printf("Unable to move : %s\n",strerror(errno));
            return;
        }

        memset(buffer,'\0',BUFFER_SIZE);

    }
    if((iRetSrc == 0))
    {
        printf("We reach at end of file and copied Successfully\n");
    }
    if(iRetSrc == -1 || iRetDes == -1)
    {
        perror("Failed to copy");
        return;
    }
    
    close(fd1);
    close(fd2);
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

    CopyFileData(argv[1],argv[2]);
      
    return 0;
}
