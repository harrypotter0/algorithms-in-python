#include<stdio.h>
int main()
{
     int n,x,c=0,p=0;
    for(scanf("%d",&n);n--;scanf("%d",&x),c+=(x<0&&p<1),p+=(x>0?x:0),p-=(x<0&&p>0));

    printf("%d",c);
    return 0;}