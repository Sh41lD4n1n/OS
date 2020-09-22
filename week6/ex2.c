/*
Pr 	 AT 	 BT 	 CT 	 TAT 	 WT
3 	 0 	 1 	 1 	 1 	 0
0 	 0 	 2 	 3 	 3 	 1
1 	 0 	 5 	 8 	 8 	 3
2 	 0 	 8 	 16  16  8
Average Turnaround time: 7
Average waiting time: 3
*/

//shortest job first algorithm


#include <stdio.h>
//This structure store name of the process number and other parameters
struct Process{
int processNumber;
int BT;
int AT;
int TAT;
int CT;
int WT;
};

void sort(struct Process * p,int n){
//it sort by value of BT
    for (int i=1;i<n;i++){
        for(int j=0;j<n-1;j++){
            if (p[i].BT<p[j].BT ){
                struct Process t=p[i];
                p[i]=p[j];
                p[j]=t;
            }
        }
    }
//Search element with min value of AT
    for(int i=0;i<n;i++){
        if (p[i].AT<p[0].AT){
            struct Process t=p[0];
            p[0]=p[i];
            p[i]=t;
        }
    }
//It sort elements by AT
    for(int j=1;j<n-1;j++){
        int t1=p[j-1].AT;
        int t2=p[j-1].BT+t1;
        for(int i=j+1;i<n;i++){
            if (p[i].AT<p[j].AT && t2>p[i].AT &&p[i].BT<p[j].BT){
                struct Process t=p[j];
                p[j]=p[i];
                p[i]=t;
            }
        }
    }

}
int main(){
//Read input
    int NumberOfProcesses;
    printf("Write number of processes: ");
    scanf("%d",&NumberOfProcesses);

    struct Process P[NumberOfProcesses];
    for(int i=0;i<NumberOfProcesses;i++){
        P[i].processNumber=i;
        printf("Write AT and BT: ");
        scanf("%d",&P[i].AT);
        scanf("%d",&P[i].BT);
    }
    sort(&P,NumberOfProcesses);


//Completion Time:
    {
    int sum=0;
    for(int i=0;i<NumberOfProcesses;i++){
        if (P[i].AT-sum>=0)
            sum =sum+ P[i].BT+(P[i].AT-sum);
        else
            sum =sum+ P[i].BT;
        P[i].CT=sum;
    }
    }
    int TAsum=0;
    int WTsum=0;
    //Turn around time
    // Waiting Time:
    for(int i=0;i<NumberOfProcesses;i++){
        P[i].TAT=P[i].CT-P[i].AT;
        TAsum+=P[i].TAT;
        P[i].WT=P[i].TAT-P[i].BT;
        WTsum+=P[i].WT;
    }
    printf("Pr \t AT \t BT \t CT \t TAT \t WT\n");
    for(int i=0;i<NumberOfProcesses;i++){
        printf("%d \t %d \t %d \t %d \t %d \t %d\n",P[i].processNumber,P[i].AT,P[i].BT,P[i].CT,P[i].TAT,P[i].WT);
    }
    printf("Average Turnaround time: %d\n",TAsum/NumberOfProcesses);
    printf("Average waiting time: %d",WTsum/NumberOfProcesses);
}
