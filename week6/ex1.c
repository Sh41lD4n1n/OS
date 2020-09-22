/*
 Pr 	 AT 	 BT 	 CT 	 TAT 	 WT
1 	 0 	 2 	 2 	 2 	 0
4 	 0 	 4 	 6 	 6 	 2
3 	 1 	 1 	 7 	 6 	 5
2 	 2 	 8 	 15 	 13 	 5
0 	 3 	 1 	 16 	 13 	 12
Average Turnaround time: 8
Average waiting time: 4
*/
#include <stdio.h>
struct Process{
int processNumber;
int BT;
int AT;
int TAT;
int CT;
int WT;
};
//Sort elements by AT
void sort(struct Process * p,int n){
    for (int i=1;i<n;i++){
        for(int j=0;j<n-1;j++){
            if (p[i].AT<p[j].AT){
                struct Process t=p[i];
                p[i]=p[j];
                p[j]=t;
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
