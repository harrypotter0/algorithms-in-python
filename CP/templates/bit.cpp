#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <complex>
#pragma comment(linker, "/STACK:266777216")
using namespace std;

#define assert(f) { if(!(f)) { fprintf(stderr,"Assertion failed: "); fprintf(stderr,#f); fprintf(stderr,"\n"); exit(1); } }

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<double> VD;
typedef pair<double,double> PDD;

const int inf=1000000000;
const LL INF=LL(inf)*inf;
const double eps=1e-9;
const double PI=2*acos(0.0);
#define bit(n) (1<<(n))
#define bit64(n) ((LL(1))<<(n))
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define all(a) (a).begin(),(a).end()
#define fill(ar,val) memset((ar),(val),sizeof (ar))
#define MIN(a,b) {if((a)>(b)) (a)=(b);}
#define MAX(a,b) {if((a)<(b)) (a)=(b);}
#define sqr(x) ((x)*(x))
#define X first
#define Y second

//clock_t start=clock();
//fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));

#define N 101010
int n;
int a[N],b[N];
int f[N];

void add(int x)
{
// 	for(;x<=n;x+=x&-x) f[x]++;
	for(;x<=n;x+=x&-x) {
	   // cout<<x<<"x";
	    f[x]++;
	}
// 	cout<<endl<<"f";
// 	for(int i =1;i<=n;i++) {
// 	    cout<<f[i]<<" ";
// 	}
// 	cout<<endl;
}

int sum(int x)
{
	int s=0;
// 	for(;x>0;x-=x&-x) s+=f[x];
	for(;x>0;x-=x&-x) {
	    s+=f[x];
	   // cout<<s<<"s"<<x<<"x";
	}
// 	cout<<endl;
	return s;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
#endif
	int T;
	for(scanf("%d",&T);T--;)
	{
		int i,j;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&j);
			a[j]=i;
		}
		fill(f,0);
		LL ans=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&j);
			b[a[j]]=i;
		}
		for(i=1;i<=n;i++)
		{
		  //  cout<<b[i]<<"b[i]";
			add(b[i]);
			ans+=i-sum(b[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
