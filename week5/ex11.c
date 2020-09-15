/*
The threads mixed. As program start all of them and doesn't wait termination
Thread number 0 is created
Thread number 1 is created
Thread number 2 is created
Thread number 3 is created
Thread number 4 is created
Thread number 5 is created
Thread number 6 is created
Thread number 7 is created
Thread number 8 is created
Thread number 9 is created
Thread number 10 is created
Thread number 11 is created
Thread number 12 is created
Thread number 13 is created
Thread number 14 is created
Thread number 15 is created
Thread number 16 is created
Thread number 17 is created
Thread number 18 is created
thread Number: 6 exit
thread Number: 7 exit
thread Number: 8 exit
thread Number: 5 exit
thread Number: 9 exit
thread Number: 10 exit
thread Number: 11 exit
thread Number: 12 exit
thread Number: 4 exit
thread Number: 13 exit
thread Number: 14 exit
thread Number: 15 exit
thread Number: 16 exit
thread Number: 17 exit
thread Number: 18 exit
thread Number: 3 exit
thread Number: 2 exit
thread Number: 1 exit
thread Number: 0 exit
*/
/*#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void * Thread(void *n){
    int i=(int) n;
    printf("thread Number: %d exit\n",i);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]){
    int n=0;
    if(argc!=0){n=atoi(argv[1]);}

    pthread_t thread;
    for(int i=0;i<n;i++){
        pthread_create(&thread,NULL,Thread,i);
        printf("Thread number %d is created\n",i);
    }
    //pthread_join(thread,NULL);
    pthread_exit(NULL);
    return 0;
}*/

/*Now we wait termination before starting new thread
Thread number 0 is created
thread Number: 0 exit
Thread number 1 is created
thread Number: 1 exit
Thread number 2 is created
thread Number: 2 exit
Thread number 3 is created
thread Number: 3 exit
Thread number 4 is created
thread Number: 4 exit
Thread number 5 is created
thread Number: 5 exit
Thread number 6 is created
thread Number: 6 exit
Thread number 7 is created
thread Number: 7 exit
Thread number 8 is created
thread Number: 8 exit
Thread number 9 is created
thread Number: 9 exit
Thread number 10 is created
thread Number: 10 exit
Thread number 11 is created
thread Number: 11 exit
Thread number 12 is created
thread Number: 12 exit
Thread number 13 is created
thread Number: 13 exit
Thread number 14 is created
thread Number: 14 exit
Thread number 15 is created
thread Number: 15 exit
Thread number 16 is created
thread Number: 16 exit
Thread number 17 is created
thread Number: 17 exit
Thread number 18 is created
thread Number: 18 exit
*/
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void * Thread(void *n){
    int i=(int) n;
    printf("thread Number: %d exit\n",i);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]){
    int n=0;
    if(argc!=0){n=atoi(argv[1]);}

    pthread_t thread;
    for(int i=0;i<n;i++){
        pthread_create(&thread,NULL,Thread,i);
        printf("Thread number %d is created\n",i);
        pthread_join(thread,NULL);
    }
    pthread_exit(NULL);
    return 0;
}