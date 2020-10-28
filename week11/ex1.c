#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>
int main()
{
    
    //Create string and get size of it
    char*text = "This is a nice day";
    size_t size = strlen(text)+1;
    
    //Open file and get size of this file
    int input=open("ex1.txt",O_RDWR);
    
    //Open file to change size
    FILE *file=fopen("ex1.txt","w");
    ftruncate(fileno(file),size-1);
    fclose(file);
    
    //Get text from file and change it
    char* output;
    output=mmap(NULL,size,PROT_READ|PROT_WRITE,MAP_SHARED,input,0);
    
    for(int i=0;i<size;i++){
        output[i]=text[i];
    }
    return 0;
}