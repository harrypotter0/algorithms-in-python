#include<bits/stdc++.h>
using namespace std;
vector <int> V[100005];
int n,m,i,j,s,t,x,y,h[100005],hh[100005],d;
int f(int x,int s)
{
	if(h[x])s+=1;
	else s=0;

	if(s>d or hh[x])return 0;
	hh[x]=1;
	int i,j,u=V[x].size(),t=0;
	if(x>1 and u==1)return 1;
	for(i=0;i<u;i++)
	{
		t+=f(V[x][i],s);
	}
	return t;
}
int main()
{
	cin>>n>>d;
	for(i=1;i<=n;i++)cin>>h[i];
	for(i=1;i<n;i++)
	{
		cin>>x>>y;
		V[x].push_back(y);
		V[y].push_back(x);
	}
	cout<<f(1,0)<<endl;
}