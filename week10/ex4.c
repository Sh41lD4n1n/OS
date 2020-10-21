#include "stdio.h"
#include <dirent.h>
#include <stdlib.h>
#define N 20

struct node {
int node;
int number;
int o;
char*c[50];
};
int occupied = 0;
void add_file(struct node* a,int i,char*name){
    int j=0;
    int k=node[i].o;
    while(name[j]!=' '){
        node[i].c[k]=name[j];
        k++;
        j++;
    }
    node[i].c[k]='\n';
    node[i].o=k+1;

}
void inser_node(struct node * array,int node,char*name){
    for(int i=0;i<occupied;i++)
        if (array[i].node==node){
            array[i].number=array[i].number+1;
            if(array[i].number>0)
                add_file(array,i,name);
                printf("----function:%d\n",node);
            return;
        }
    array[occupied].node=node;
    array[occupied].number=1;
    occupied=occupied+1;
    add_file(array,i,name);
    };

int main(){
DIR *dir=opendir("./tmp");
struct dirent* dp=readdir(dir);
struct node *a[N];
initialisation(a,N);
while ((dp = readdir(dir)) != NULL) {
inser_node(a,dp->d_ino);
printf("%s %d\n",dp->d_name,dp->d_ino);
}

return 0;
}
