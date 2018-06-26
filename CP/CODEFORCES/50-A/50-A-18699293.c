#include<stdio.h>
#include<math.h>
int main ()
{
    int n,m,k=0,area1,area2;
    scanf("%d%d",&n,&m);
    area1=m*n;
    area2=2;
    k=area1/area2;
    printf("%d\n",k);
    return 0;
}