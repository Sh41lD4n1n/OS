/*
 *
For this case the system was not safe
3 5

7 2 6

0 0 0

0 1 0
2 0 0
3 0 3
2 1 1
0 0 2

1 0 0
2 0 2
0 0 10
1 0 0
0 0 2
For this case the system was safe
 3 5

7 2 6

0 0 0

0 1 0
2 0 0
3 0 3
2 1 1
0 0 2

0 0 0
2 0 2
0 0 0
1 0 0
0 0 2
 */

#include <stdio.h>
#include<stdlib.h>
int main()
{
    FILE *input;
    input = fopen("input.txt","r");
    int* E;
    int* A;
    int* C;
    int* R;
    int proc_counter=0,res_counter=0;

    //read number of resources and processes .
    fscanf(input,"%d %d", &res_counter, &proc_counter);

    E = calloc(10,sizeof(int)*res_counter);
    A = calloc(10,sizeof(int)*res_counter);
    C = (int*)malloc(res_counter*proc_counter*sizeof(int));
    R = (int*)malloc(res_counter*proc_counter*sizeof(int));

    //read evaluable resources lists
    for(int i=0;i<res_counter;i++){
        fscanf(input,"%d",&E[i]);
    }
    //read available resources lists
    for(int i=0;i<res_counter;i++){
        fscanf(input,"%d",&A[i]);
        //printf("%d ",A[i]);
    }

    //read Current state tables
    for(int i = 0;i<proc_counter;i++){
        for(int j=0;j<res_counter;j++){
            fscanf(input, "%d", (C+i*res_counter+j));
            //printf("%d ",*(C+i*res_counter+j));
        }
        //printf("\n");
    }
    //read Requests tables
    for(int i = 0;i<proc_counter;i++){
        for(int j=0;j<res_counter;j++){
            fscanf(input, "%d", (R+i*res_counter+j) );
        }
    }

    int* state = calloc(0,sizeof(int)*proc_counter);
    while (1){
        //check how many processes left before iteration
         int count1=0;
       for(int i = 0;i<proc_counter;i++){
           if(state[i]==0)
                count1 = count1 + 1;
       }
       //iteration
        for(int i = 0;i<proc_counter;i++){
            //choose state that doesn't terminated
            if(state[i]==0){
                //check ability to terminate process
                for(int j=0;j<res_counter;j++){
                    if(*(R+i*res_counter+j)-*(C+i*res_counter+j)-A[j]<=0){
                        state[i]=1;
                    }
                    else{
                        //if number of one resource is less then required state become 0
                        state[i]=0;
                        break;
                    }

                }
                if (state[i]==1){
                for(int j=0;j<res_counter;j++){
                    A[j]=*(C+i*res_counter+j)+A[j];
                }
                printf("Process %d finished \n", i);
                break;
            }
        }

        }
        //check how many processes left after iteration
        int count=0;
       for(int i = 0;i<proc_counter;i++){
           if(state[i]==0)
                count = count + 1;
       }
       //All processes are terminated.
       if(count==0){
           printf("All processes are terminated");
           break;
       }
       //During this iteration no more process are able to finish
       if(count1-count==0){
           printf("Deadlocks");
           break;
       }


    }
    return 0;
}