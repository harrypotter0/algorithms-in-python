#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a;
set<ll> s,t;
int main()
{
	cin>>n>>m;
	for (int i=0;i<n;i++) cin>>a,s.insert(a);
	for (int i=1;i<=m;i++) if (!s.count(i)) m-=i,t.insert(i);
	cout<<t.size()<<'\n';
	for (auto i:t) cout<<i<<' ';
}