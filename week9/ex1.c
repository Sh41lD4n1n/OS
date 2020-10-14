#include<stdio.h>
#include <stdlib.h>
#include<math.h>
void Modify_freq(int j,int *freq,int n){
    //This function insert 1 to left most position in binary
    // representation of the counter freq[j] and 0 for all other elements of array
    double max=pow(2,30); //used to insert 1 to the left most position in binary representation of freq[i]
    //insert 1 to left most position in binary representation of the counter freq[j]
    freq[j]= (freq[j] >> 1)+max;
    //printf("\nModification:");
    //insert 0 to left most position in binary representation of the counters
    for (int i=0;i<n;i++){
        //printf(" %d|",freq[i]);
        if(i!=j)
            freq[i]=freq[i]>>1;
        //printf("%d",freq[i]);
    }
};
void Update(int *freq,int *frames,int page,int *oqupaed,int n){
    //Update insert new page if there is empty page frames
    if (*oqupaed<n){
        frames[*oqupaed]=page;
        Modify_freq(*oqupaed,freq,n); //Change freq counters
        *oqupaed=*oqupaed+1;
    //Update search process with minimal freq counter and remove it
    }else{
        //Search min value
        int min=freq[0];
        int min_i=0;
        //printf("\n MIN: values");
        //printf("%d ",freq[0]);
        for(int i=1;i<n;i++){
            //printf("%d ",freq[i]);
            if(freq[i]<min){
                min=freq[i];
                min_i=i;
            }
        }
        //Insert new page
        freq[min_i]=0;
        Modify_freq(min_i,freq,n);
        frames[min_i]=page;
    }
};

int Number_in_frame(int a,int*frames,int N){
    //This function search page with name a in array of page frames
    //It will return number of page or -1 if page wasn't found
    for(int i=0;i<N;i++)
        if (frames[i]==a){
            return i;
        }
    return -1;
};

int main(){
    FILE *input;
    input= fopen("input.txt","r");
    const int N=100;                        //number of page frames
    int ocupaed=0;                          // number of pages occupied

    int *frames = calloc(N,sizeof(int));    //name of processes in each page frame
    int *freq= calloc(N,sizeof(int));       //counter

    int hit=0;                              //number of hits and miss
    int miss=0;

    char s=' ';                             //used to check next symbol in file (if there is now symbol, it means that program reach end of file)
    int a;                                  //read process number

    while (s==' '){
        s='1';
        fscanf(input,"%d%c",&a,&s);
    //printf("%d ",a);
        int num= Number_in_frame(a,frames,N);   //search number of page frame
        if(num!=-1){                            //if this page frames contain this page program will:
            Modify_freq(num,freq,N);            //change counter and number of hits
            hit=hit+1;
            //printf(" hit \n");
        }else{                                  //if this page frames doesn't contain this page program will:
            miss=miss+1;                        //increase number of miss, and remove old page and insert new one
            Update(freq,frames,a,&ocupaed,N);
            //printf(" miss \n");
        }
        /*for(int i=0;i<N;i++)
            printf(" %d ",frames[i]);
        printf("\n");*/
    }
    printf("hit/miss = %f",(float)hit/miss);
    return 0;
}
