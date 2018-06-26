#include<bits/stdc++.h>
using namespace std;
#define INF		1000000007
#define LL		long long int
#define SI(n)		cin >> n;
#define SC(c)		scanf("%c",&c);
#define SS(s)		scanf("%s",s);
#define FOR(x,a,b)	for(LL x=a;x<b;x++)
#define REP(i,n)	for(LL i=0;i<n;i++)
#define MP		make_pair
#define PB		push_back
#define	VI		vector<LL>
#define PLL             pair<LL,LL>  /* A Single Pair  */
#define VP		vector<PLL> /* Vector of Pairs */
#define VS		vector<string>
#define VVI		vector<VI>
#define VVS		vector<VS>
#define F first
#define S second
int main()
{
	LL n;
	cin >> n;
	cout<< (n*n+1)/2<<endl;
	REP(i,n)
	{
	    REP(j,n)
	{
	char r =i+j&1?'.':'C';
	cout<<r;}
	cout<<endl;}
	return 0;
}