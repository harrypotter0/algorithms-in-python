#include<stdio.h>
#include<conio.h>
int main ()
{
    int i,sum=0,n,m,a,jok=0;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        sum=sum+a;
        if(i!=n-1){
        sum=sum+10;
        jok=jok+2;}
    }
    if(sum<=m)
    printf("%d\n",jok+((m-sum)/5));
    else
    printf("-1\n");
    return 0 ;
}