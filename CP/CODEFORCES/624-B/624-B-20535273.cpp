#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n; cin>>n;
	map<long long, int> mp;
	long long sum=0;
	while(n--)
	{
		int k; cin>>k;
		while(mp[k]==1&&k>0) k--;
		mp[k]=1;
		sum+=k;
	}
	cout<<sum<<endl;
}