//exercise 3
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>


#include  <time.h>
int buffer[5];
buffer[0]=4;
int NumberOfElem=0;
int ProducerSleep=1;
int ConsumerSleep=0;
void * Producer(void *p){
    while(1){
        if (ProducerSleep==0){
            continue;
        }
        if (NumberOfElem>=5){
            ProducerSleep=0;
            ConsumerSleep=1;
            printf("The buffer is full \n");
            continue;
            }
        NumberOfElem=NumberOfElem+1;
        buffer[NumberOfElem]=1+buffer[0];
        printf("Producer add new number: %d\n",buffer[NumberOfElem]);
    }
    pthread_exit();
    return0;
    }
void * Consumer(void *c){
    while(1){
        if (ConsumerSleep==0){
            continue;
        }
        if (NumberOfElem==0){
            ProducerSleep=1;
            ConsumerSleep=0;
            printf("The buffer is empty \n");
            continue;
            }
        int elem=buffer[NumberOfElem];
        buffer[NumberOfElem]=0;
        NumberOfElem=NumberOfElem-1;
        printf("Consumer remove number: %d\n",elem);
    }
    pthread_exit();
    return0;

}
int main(){
    pthread_t consumer;
    pthread_t produser;
    pthread_create(&produser,NULL,Producer,NULL);
    pthread_create(&consumer,NULL,Consumer,NULL);
    pthread_join(consumer,NULL);
    pthread_join(produser,NULL);
    return 0;


}
