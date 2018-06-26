#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
const ll inf=pow(10,14);
bool apply(ll x,ll y,ll op)
{
if(op==0)
{
return x<y;
}
return x>y;
}

bool apply2(ll x,ll y,ll op)
{
if(op==1)
{
return x<y;
}
return x>y;
}

int main(){

   ll t;
cin>>t;
while(t--)
{
ll n,arr[100005];
cin>>n;
for(ll i=0;i<n;i++)
cin>>arr[i];

ll dp[100005][2];
for(ll i=0;i<100005;i++)
{
for(ll j=0;j<2;j++)
dp[i][j]=inf;
}

if(n==2)
{
if(arr[0]==arr[1])
cout<<-1<<endl;
else
cout<<0<<endl;
continue;
}

ll x=ceil(1.0*n/2);
dp[0][0]=0,dp[0][1]=1;
for(ll i=1;i<x;i++)
{
ll val1=dp[i-1][0],val2=dp[i-1][1];
if(!(apply(arr[i-1],arr[i],i%2) && apply(arr[n-i-1],arr[n-i],(n-i)%2)))
{
val1=inf;
}
if(!(apply(arr[n-i],arr[i],i%2) && apply(arr[n-i-1],arr[i-1],(n-i)%2)))
{
val2=inf;
}
dp[i][0]=min(val1,val2);

val1=dp[i-1][0],val2=dp[i-1][1];
if(!(apply(arr[i-1],arr[n-i-1],i%2) && apply(arr[i],arr[n-i],(n-i)%2)))
{
val1=inf;
}
if(!(apply(arr[n-i],arr[n-i-1],i%2) && apply(arr[i],arr[i-1],(n-i)%2)))
{
val2=inf;
}
dp[i][1]=min(val1,val2)+1;
}

ll dp2[100005][2];
for(ll i=0;i<100005;i++)
{
for(ll j=0;j<2;j++)
dp2[i][j]=inf;
}


dp2[0][0]=0,dp2[0][1]=1;
for(ll i=1;i<x;i++)
{
ll val1=dp2[i-1][0],val2=dp2[i-1][1];
if(!(apply2(arr[i-1],arr[i],i%2) && apply2(arr[n-i-1],arr[n-i],(n-i)%2)))
{
val1=inf;
}
if(!(apply2(arr[n-i],arr[i],i%2) && apply2(arr[n-i-1],arr[i-1],(n-i)%2)))
{
val2=inf;
}
dp2[i][0]=min(val1,val2);

val1=dp2[i-1][0],val2=dp2[i-1][1];
if(!(apply2(arr[i-1],arr[n-i-1],i%2) && apply2(arr[i],arr[n-i],(n-i)%2)))
{
val1=inf;
}
if(!(apply2(arr[n-i],arr[n-i-1],i%2) && apply2(arr[i],arr[i-1],(n-i)%2)))
{
val2=inf;
}
dp2[i][1]=min(val1,val2)+1;
}
ll res=min(min(dp[x-1][0],dp[x-1][1]),min(dp2[x-1][0],dp2[x-1][1]));
if(res>pow(10,12))
cout<<-1<<endl;
else
cout<<res<<endl;
}
   return 0;
}
