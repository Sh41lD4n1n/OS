#include<time.h>
#include <stdio.h>
#include <unistd.h>
#include<stdlib.h>
int main(){
time_t t1=time(NULL);

int size=10*1024*1024*100;
time_t t2=time(NULL);

while(t2-t1<10){
    memset(malloc(size),0,size);
    sleep(1);
    t2=time(NULL);

}
return 0;
}
