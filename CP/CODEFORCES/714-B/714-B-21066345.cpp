#include<bits/stdc++.h>
using namespace std;
int n,ans,v[111111];
int main()
{
	cin>>n;
	for(int i=0;i<n;++i)
		cin>>v[i];
	sort(v,v+n);
	ans=unique(v, v+n)-v;
	if(ans>3) cout<<"NO";
	else if (ans<3) cout<<"YES";
	else if (v[0]+v[2]==v[1]*2) cout<<"YES";
	else cout<<"NO";
	return 0;
}