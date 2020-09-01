#include <stdio.h>
#define MAX_SIZE 100
void bobble_sort(int * array,int n){
    for (int i=0;i<n-2;i++){
        for (int j=0;j<n-1;j++){
            if(*(array+j) >*(array+j+1)){
                int temp=*(array+j);
                *(array+j)=*(array+j+1);
                *(array+j+1)=temp;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d",&n);
    int array[MAX_SIZE];
    for (int i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
    bobble_sort(array,n);
    for (int i=0;i<n;i++){
        printf("%d ",array[i]);
    }
    return 0;
}