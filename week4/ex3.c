#include <stdio.h>
#include <stdlib.h>
int main()
{
    char com[15]; //this string will store command
    while(1){	  // we catch command while user write it
        printf(">>");
        scanf("%s",com);// catch new command
        system (com); // call system to execute it
    }
    return 0;
}
