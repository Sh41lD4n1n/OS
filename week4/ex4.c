#include <stdio.h>
#include <stdlib.h>
int main()
{
    char com[15];
    while(1){
        printf(">>");
        fgets(com,15,stdin);//this function catch whole line that user print
        printf("%s",com);
        system (com);
    }
    return 0;
}
