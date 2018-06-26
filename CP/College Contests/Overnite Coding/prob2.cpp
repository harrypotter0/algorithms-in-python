#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll t,n,phi[1000006],val[1000006],pr[1000006],frq[2000006];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll i,j,k;
    for(i=2;i<=1000000;i++)
    {
        phi[i]=i;
    }
    for(i=2;i<=1000000;i++)
    {
        if(phi[i]==i)
        {
            phi[i]=i-1;
            for(j=2*i;j<=1000000;j+=i)
            {
                phi[j]-=(phi[j]/i);
            }
        }
    }
    for(i=3;i<=1000000;i++)
    {
        val[i]=phi[i];
        if(i%2==0)
        val[i]+=phi[i/2];
    }
    ll ans=0;
    for(i=1;i<=1000000;i++)
    {
        frq[val[i]]++;
        pr[i]=pr[i-1]+(frq[val[i]]-1);
    }
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<pr[n]<<"\n";
    }
    return 0;
} 
