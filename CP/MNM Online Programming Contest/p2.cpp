#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define	endl		'\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
using namespace std;
#define N  100005

int main() {
  ll t;
  cin>>t;
  while(t--)
    {
      ll n,k;
      cin>>n>>k;
      if(n==0||n==1||n<0)
        {cout<<"0"<<endl;}
      else
      {ll d=(n-1)*k;
      long double r= (d*3)/50.0;
      cout<<r<<endl;}
    }


}
