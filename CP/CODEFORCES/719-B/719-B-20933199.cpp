#include<iostream>
#include<cstdio>
using namespace std;
char c;
int n,i,s1,s2;
int main()
{
	cin>>n;
	getchar();
	for(i=1;i<=n;i++)
	{
		c=getchar();
		if(i&1) s1+=(c=='b');
		else s2+=(c=='r');
	}
	cout<<min(max(s1,s2),max((n+1)/2-s1,n/2-s2));
	return 0;
}