#include <stdio.h>
void swap(int *a,int *b){
    int s=*a;
    *a=*b;
    *b=s;


}
int main()
{
    int a,b;
    int *ap=&a,*bp=&b;
    scanf("%d %d",ap,bp);
    swap(ap,bp);
    printf("%d %d",a,b);

}