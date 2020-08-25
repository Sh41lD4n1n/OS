#include <stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int num, char*args[]) {
	char *p;
    if (num!=2){
        printf("Print the parameter");
        return 0;
    }
    long n=strtol(args[1],&p,10);
   printf("%d", (int)strtol(args[1],&p,10));
  for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++)
            printf("%c", ' ');
        for (int j = 0; j < 2 * n - 1 - 2 * i; j++)
            printf("%c", '*');
        for (int j = 0; j < i; j++)
            printf("%c", ' ');
        printf("%c", '\n');
}
}