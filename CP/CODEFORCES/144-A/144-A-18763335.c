#include<stdio.h>
int main()
{
    int n,i,max=-1,min=110,t1,t2;
    scanf("%d",&n);
    int soldier[n];
    for(i=0;i<n;i++)
        scanf("%d",&soldier[i]);
    for(i=0;i<n;i++)
    {
        if(max<soldier[i])max=soldier[i];
        if(min>soldier[i])min=soldier[i];
    }
    for(i=0;i<n;i++)
        if(soldier[i]==max)break;
    t1=i;
    for(i=n-1;i>=0;i--)
        if(soldier[i]==min)break;
    if(i<t1)t2=n-i-2;
    else t2=n-i-1;
    printf("%d",t1+t2);
    return 0;
}