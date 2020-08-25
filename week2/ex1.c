#include <stdio.h>
#include <limits.h>
#include <float.h>
int main()
{
    int a = INT_MAX;
    float b = FLT_MAX;
    double c=DBL_MAX;
    printf("a=%lu\n,b=%lu\n,c=%lu\n",sizeof(a),sizeof(b),sizeof(c));
    printf("a=%d\n,b=%f\n,c=%lf\n",a,b,c);
    return 0;
}

