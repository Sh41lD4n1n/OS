#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    //Set setting of buffer. Now it write when buffer is full or "\n" is writen.
    setvbuf(stdin,NULL,_IOLBF,5);
    //Create string for output
    char *string="Hello";
    //print it
    for(int i=0;i<5;i++){
        printf("%c",string[i]);
        sleep(1);
    }
    printf("\n");
}