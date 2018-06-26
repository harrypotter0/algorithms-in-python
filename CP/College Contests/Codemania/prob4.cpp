#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7;
int po(int x,int k)
{
    int sum=1;
    while(k)
    {
        if(k&1)
        {
            sum=1LL*sum*x%mod;
        }
        x=1LL*x*x%mod;
        k>>=1;
    }
    return sum;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
    int n,m;
    scanf("%d%d",&n,&m);
    printf("%d\n",1LL*po(n+1,m-1)*(n-m+1)%mod*po (2,m)%mod);
    }
    return 0;
}
