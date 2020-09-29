#include <stdio.h>

int main(){
	//read N
    int N=0;
    scanf("%d",&N);
    //allocate memory
    int * array=malloc(N*sizeof(int));
    //fill array
    for(int i=0;i<N;i++){
        *(array+i)=i;
    }
    //print array
    for(int i=0;i<N;i++)
        printf("%d ",*(array+i));
    free(array);
}
