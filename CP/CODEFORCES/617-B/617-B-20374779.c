#include<stdio.h>
int main()
{
    long long n,a[101],i,ans=1,flag=0,c=0;
    scanf("%I64d",&n);
    for(i=0;i<n;i++) scanf("%I64d",&a[i]);
    for(i=0;i<n;i++)
    {
        if(a[i]){ans*=flag?i-c:1; flag=1; c=i;}
    }
    printf("%I64d",flag?ans:0);
    return 0;
}