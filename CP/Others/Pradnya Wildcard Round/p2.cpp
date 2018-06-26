/*
 *
 ********************************************************************************************
 * AUTHOR : Akash Kandpal                                                                    *
 * Language: C++14                                                                          *
 * Motto : The master has failed more times than the beginner has even tried.               *                                                                *
 * IDE used: Atom                                                                           *
 * My Domain : http://harrypotter.tech/                                                     *
 ********************************************************************************************
 *
 */
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll          long long
#define pb          push_back
#define	endl		    '\n'
#define mod         1000000007
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define prec(n) fixed<<setprecision(n)
#define mem(dp) memset(dp,-1,sizeof(dp))
const int inf =1e9;
#define MAX  100005

using namespace std;

ll takemod(ll num)
{
    if(num<0)
	    num+=mod;
    num=num%mod;
    return num;
}
ll fast_power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

int dad[100010];
int find(int x){
    if(dad[x]==x) return x;
    return dad[x]=find(dad[x]);
}
void uni(int x,int y){
    int X=find(x),Y=find(y);
    dad[X]=Y;
}

int main() {
  // your code goes here
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;
  while(t--)
    {
      ll n,ans=0;
      cin>>n;
      ll res=fast_power(2,n,mod);
      ans=takemod(res%mod-(n+1)%mod);
      ans%=mod;
      cout<<ans<<"\n";
    }
return 0;
}
