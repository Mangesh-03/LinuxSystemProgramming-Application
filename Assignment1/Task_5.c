// • Accept file name and number of bytes N.
// • Read exactly N bytes using read() and print on console.
// • If file contains less than N, print only available bytes

#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include <sys/stat.h>

/////////////////////////////////////////////////////////////////
//
// Function name : ReadFile()
// Description   : Read N Bytes From File.
// Input         : char*
// output        : -
// Author        : Mangesh Ashok Bedre.
// Date          : 20/12/2025
//
/////////////////////////////////////////////////////////////////

void ReadFile(char * FileName,char *bytes)
{
    int iRet = 0,fd = 0;
    char buffer[100];

    int byte = bytes[0] - '0'; 
    
    // open() -> to open regular file.
    fd = open(FileName,O_RDONLY);

    // read() -> read content from file into program buffer.
    iRet = read(fd,buffer,byte);

    if(iRet == -1)
    {
        perror("Unable to read");
    }
    printf("Number of bytes read %d\n",iRet);
    close(fd);
    
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
    // Handing segmentation fault in case no agrument passed by user.
    if(argc != 3)
    {
        printf("Usage: %s <file_name> <bytes>\n", argv[0]);
        return -1;
    }
    ReadFile(argv[1],argv[2]);

    return 0;
}