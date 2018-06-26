#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
ll ans[5005];
ll T,ans1,n;
vector<pair<ll,ll > >g[5005];
ll dp[5005][5005];
ll dfs(ll u,ll num,ll t)
{
	ll flag=0;
	if(dp[u][num]<=t)
	return 0;
	else
	dp[u][num]=t;
	if(u==n)
	{
		if(t<=T&&num>ans1)
		{
			ans1=num;
			ans[num]=n;
			return 1;
		}
		return 0;
	}
	for(ll i=0;i<g[u].size();i++)
	{
		ll v=g[u][i].first,w=g[u][i].second;
		if(dfs(v,num+1,t+w))
		{
			ans[num]=u;
			flag=1;
		}
	}
	return flag;
}
int main()
{
	ll m;
	scanf("%I64d%I64d%I64d",&n,&m,&T);
	memset(dp,inf,sizeof(dp));
	for(ll i=1;i<=m;i++)
	{
		ll u,v,w;
		scanf("%I64d%I64d%I64d",&u,&v,&w);
		g[u].push_back(make_pair(v,w));
	}
	dfs(1,1,0);
	printf("%d\n",ans1);
	for(ll i=1;i<=ans1;i++)
	printf("%d ",ans[i]);
	return 0;
}