#include<stdio.h>
#include<conio.h>
int main ()
{
    int i,j,n,m,s=0;
    scanf("%d%d",&n,&m);
    if(n<m)
    {printf("-1");}
    else {s=(n+1)/2;
    if(s%m==0)
    printf("%d",s);
    else
    printf("%d",((s/m)+1)*m);}
    return 0 ;
}