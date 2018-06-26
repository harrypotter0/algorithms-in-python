#include <bits/stdc++.h>
using namespace std;
#define MOD (1000000007LL)
typedef long long ll;

ll n, t, h;

int main(){
	cin>>n>>t>>h;
	h += n*t*15;
// cout<<h<<endl;
	t *= 60;
	if(h <= n*1*t){
		cout<<100*n;
		return 0;
	}
	if(h <= n*2*t){
		ll ans = (ll)1e15;
		for(ll b=0;b<=n;b++){
			ll a = n-b;
			ll cost = 100*b + 500*a;
			if(t*(b+2*a) >= h)	ans = min(ans, cost);
		}
		cout<<ans;
		return 0;
	}
	ll ans = (ll)1e15;
	for(ll a=0;a<=n;a++){
		ll g = n-a;
		ll cost = 1500*g + 500*a;
		if(t*(3*g+2*a) >= h)	ans = min(ans, cost);
	}
	cout<<ans;
	return 0;
}
 
