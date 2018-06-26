#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int  cmp(const void *a,const void *b)
{
    return (*(int*)a-*(int*)b);
}
int main ()
{
    int n,i,a[102];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    qsort(a,n,sizeof(int),cmp);
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
    return 0 ;
}