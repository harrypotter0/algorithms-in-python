#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,x,y,z;
	cin>>a>>b>>c>>x>>y>>z;
	a-=x,b-=y,c-=z;
	if (a>0) a/=2;
	if (b>0) b/=2;
	if (c>0) c/=2;
	if (a+b+c>=0) cout<<"Yes\n"; else cout<<"No\n"; 
}