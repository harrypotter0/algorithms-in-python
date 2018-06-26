#include<bits/stdc++.h>
using namespace std;
long long l,r,k,p=1,t;
int main()
{
	cin>>l>>r>>k;
	while (r>=p)
	{
		if (p>=l) cout<<p<<'\n',t++;
		if (r/k>=p) p*=k; else break;
	}
	if (!t) cout<<-1<<'\n';
}