#include<bits/stdc++.h>
using namespace std;
int n,s,t;
int main()
{
	cin>>n;
	for (int i=0,x;i<n;i++) cin>>x,s|=x;
	for (int i=0,x;i<n;i++) cin>>x,t|=x;
	cout<<s+t;
}