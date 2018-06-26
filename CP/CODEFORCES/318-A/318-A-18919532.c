#include<stdio.h>
int main()
{
    long long n,k,i,j,ans;
    scanf("%I64d %I64d",&n,&k);
    i=(n+1)/2;
    if (k<=i) ans=2*k-1;
    else ans=(k-i)*2;
    printf("%I64d\n",ans);
    return 0;
}