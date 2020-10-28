#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <string.h>

int main()
{
    struct stat buf;
    
    //Open file ex1.txt, get size of file (buf.st_size)
    int file= open("ex1.txt",O_RDWR);
    fstat(file,&buf);
    char* text=mmap(NULL,buf.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,file,0);
    
    struct stat buf1;
    //Open file ex1.memcry.txt, change size of file(buf1.st_size)
    int file1= open("ex1.memcry.txt",O_RDWR);
    ftruncate(file1,buf.st_size);
    char* text1=mmap(NULL,buf.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,file1,0);
    //Copy text from ex1.txt to ex1.memcpy.txt
    memcpy(text1,text,buf.st_size);
}