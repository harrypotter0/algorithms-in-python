#include<iostream>
#include <cmath>
#include<cstdio>
#include <algorithm>
#include <vector>
#define gc getchar
using namespace std;
void scanint(long long &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

int main()
{
	long long N,K;
// 	scanint(N);
// 	scanint(K);
    cin>>N>>K;
	long hardness[N];
	long long i,j,tmp,c=0;
	long long cnt = 0;

	for(i=0;i<N;++i)
	{
		scanint(tmp);
		hardness[i]=tmp;
	}
	sort(hardness,hardness+N);

 	for(i=0;i<N-1;i++)
    {
		for(j=i+1;j<N;j++)
		{
			if(hardness[j]-hardness[i]>=K)
			{
				cnt+=(N-j);
				break;
			}
		}
  	}
   	cout<<cnt;
	return 0;
}
