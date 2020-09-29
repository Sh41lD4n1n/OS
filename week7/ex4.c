#include <stdio.h>
int* realloc(int* ptr, int old_size,int new_size){
    //if memory was not allocated function do it
    if (ptr==NULL){
        ptr=malloc(new_size*sizeof(int));
        return ptr;
        }
    //if new_size=0 function delete ptr
    else if(new_size==0){
        free(ptr);
        return NULL;
        }
    //else it reallocate memory
    else{
        //create allocation with new size
        int* res=malloc(new_size*sizeof(int));
int n;
        //we pick min value to fill new memory allocation correctly
        if (old_size<new_size)
            n =old_size;
        else
            n =new_size;
        //store information from old array
        for(int i=0;i<n;i++)
            *(res+i) = *(ptr+i);
        free(ptr);
        return res;
    }
};
int main(){
    //Example
    const int N=10;
    int*a1=malloc(N*sizeof(int));
    for(int i=0;i<N;i++)
        *(a1+i)=i;

    a1=realloc(a1,N,5);

    for(int i=0;i<6;i++)
        printf("%d ",*(a1+i));
    return 0;
}