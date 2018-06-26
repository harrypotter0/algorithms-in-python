#include<bits/stdc++.h>
using namespace std;
const int MAX=109;
int ans,res,n,m;
int main()
{
	cin>>n>>m;
	for (int i=0;i<n;i++)	
	{
		res=1e9;
		for (int j=0,x;j<m;j++) cin>>x,res=min(res,x);
		ans=max(ans,res);
	}
	cout<<ans;
}