#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define li long int
#define pb push_back
#define pbk pop_back
#define mp make_pair
#define fs first
#define sc second
#define sp " "
#define en "\n"

using namespace std;

const ll MOD=1e9+7;
const ll N=1e5+5;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin>>t;
    vector<ll>v(1000000);
    ll a=0,b=0;
    bool flag=true;
    while(1)
    {
      if(flag)
      {
        a++;
        b++;
        v[b]=(a+1337)%1337;
      }
      else
      {
        a--;
        b++;
        v[b]=(a+1337)%1337;
      }
      string s = to_string(b);
      bool x=false;
      rep(i,0,s.length())
        if(s[i]=='7')
        {
          x=true;
          break;
        }
      if(b%7==0 || x)
        flag=(!flag);
      if(b>1000000)
        break;
    }
    while(t--)
    {
      ll n;
      cin>>n;
      cout<<v[n]<<en;
    }
    return 0;
}
