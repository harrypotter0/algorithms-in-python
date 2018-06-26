#include<bits/stdc++.h>
using namespace std;
long long int  dp[20000];
long long int  dp1[20000];

long long int f(long long int a[],long long int k,long long int n)
{

    if(dp[n]!=-1)
    return dp[n];

    if(n==0)
    return 0;

    long long int res=INT_MAX;

    for(long long int i=0;i<k;i++)
    {
        if(a[i]<=n)
        {
            res=min( res, 1+f(a,k,n-a[i]) );
        }
    }
    return dp[n]=res;

}

long long int f1(long long int a[],long long int k,long long int n)
{

    if(dp1[n]!=-1)
    return dp1[n];

    if(n==0)
    return 0;

    long long int res=-INT_MAX;

    for(long long int  i=0;i<k;i++)
    {
        if(a[i]<=n)
        {
            res=max( res, 1+f1(a,k,n-a[i]) );
        }
    }
    return dp1[n]=res;
}


int main()
{

    memset(dp,-1,sizeof(dp));
    memset(dp1,-1,sizeof(dp1));

        long long int n,k;
        cin>>n>>k;

        long long int a[20000];

        for(long long int i=0;i<k;i++)
        {
            cin>>a[i];
        }

        long long int ans=f(a,k,n);
        long long int ans1=f1(a,k,n);

        if(ans==INT_MAX || ans1==INT_MIN)
        cout<<"-1 -1";
        else
        cout<<ans<<" "<<ans1;
    //}

    return 0;
}
