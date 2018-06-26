#include "bits/stdc++.h"
using namespace std;
	
#define ll long long int
#define F first
#define S second
	
const int N = 4e5 + 5;
	
int n;
pair  < int , int > p[N];
	
class cmp
{
public:
	bool operator()(int a , int b)
	{
		return a < b;
	}
};
	
bool check(int k)
{
	priority_queue < int , vector < int > , cmp > pq;
	ll sum = 0;
	for(int i = 1 ; i <= k ; i++)
	{
		pq.push(p[i].S);
		sum += p[i].S;
	}
	ll diff = sum - (k * 1LL * p[k].F);
	if(diff <= 0)
		return true;
	for(int i = k + 1 ; i <= n ; i++)
	{
		int large = pq.top();
		pq.pop();
		sum -= large;
		ll nsum = sum + p[i].S;
		ll ndiff = nsum - (k * 1LL * p[i].F);
		if(ndiff <= 0)
			return true;
		if(large >= p[i].S)
		{
			pq.push(p[i].S);
			sum += p[i].S;
		}
		else
		{
			pq.push(large);
			sum += large;
		}
	}
	return false;
}
	
int main()
{
	int t;
	scanf("%d", &t);
	while( t-- )
	{
		scanf("%d", &n);
		for(int i = 1 ; i <= n ; i++)
			scanf("%d %d", &p[i].F, &p[i].S);
		sort(p + 1, p + n + 1);
		// for(int i = 1 ; i <= n ; i++)
		// printf("%d%d",p[i].F,p[i].S);
		reverse(p + 1 , p + n + 1);
		// for(int i = 1 ; i <= n ; i++)
		// printf("%d%d",p[i].F,p[i].S);
		int l = 0;
		int r = n;
		int ans = 0;
		while( l <= r )
		{
			int mid = (l + r) / 2;
			if(check(mid))
			{
				ans = max(ans, mid);
				l = mid + 1;
			}
			else
				r = mid - 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}	