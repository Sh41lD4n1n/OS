/*
memory usage: 11036
memory usage: 21632
memory usage: 31928
memory usage: 42224
memory usage: 52520
memory usage: 62816
memory usage: 72848
memory usage: 83144
memory usage: 93440
memory usage: 103736

*/
#include<time.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/resource.h>
#include<stdlib.h>

extern int errno;
int main(){
time_t t1=time(NULL);

int size=10*1024*1024;
time_t t2=time(NULL);

struct rusage *usage=malloc(sizeof(struct rusage));
while(t2-t1<10){
    memset(malloc(size),0,size);
    if(getrusage(RUSAGE_SELF,usage)){
        printf("Error %d\n",errno);
    };
    printf("memory usage: %ld\n",(*usage).ru_maxrss);
    sleep(1);
    t2=time(NULL);

}
return 0;
}
