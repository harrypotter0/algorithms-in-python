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
const int inf =1e9;
using namespace std;
#define MAX  100005

int gcd(int a, int b) {
  while(b) {
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}

int main() {
  ll t;
  cin>>t;
  while(t--)
    {
      ll n,m,a,b,c,d,p  ;
      cin>>n>>m>>a>>b>>c>>d>>p;
      ll A,B,C;
      A = a+b;
      B = c+d;
      C = p+m*b+n*d;
      ll g = gcd(A,B);
      if(C %g!=0){
          cout<<"-1"<<endl;
          continue;
      }
       int  ans = inf;
      int till = C / A;
    for(int N = m; N <= till; ++N) {
      int E = (C - N * A);
      if (E % B != 0) {
        continue;
      }
      E /= B;
      if (E < n) {
        break;
      }
      int S = N - m, W = E - n;
      ans = min(ans, N + S + E + W);
    }
    if (ans == inf) {
      ans = -1;
    }
    else {
      assert(ans >= n + m);
    }
    cout << ans << "\n";


    }

return 0;
}
