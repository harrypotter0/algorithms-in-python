#include<bits/stdc++.h>
using namespace std;
#define test() int t;scanf("%d",&t);for(int tno=1;tno<=t;tno++)
#define mp make_pair
#define pb push_back
#define wl(n) while(n--)
#define fi first
#define se second
#define all(c) c.begin(),c.end()
typedef long long ll;
typedef unsigned long long llu;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii ;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
#define sz(a) int((a).size())
#define ini(a,v) memset(a,v,sizeof(a))
#define sc(x) scanf("%d",&x)
#define sc2(x,y) scanf("%d%d",&x,&y)
#define sc3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define scl(x) scanf("%lld",&x)
#define scl2(x,y) scanf("%lld%lld",&x,&y)
#define scl3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define scs(s) scanf("%s",s);
#define gcd __gcd
#define debug() printf("here\n")
#define chk(a) cerr << endl << #a << " : " << a << endl
#define chk2(a,b) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << endl
#define tr(container, it)  for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define MOD 1000000007
#define inf ((1<<29)-1)
#define linf ((1LL<<60)-1)
const double eps = 1e-9;
//-----------------------------------------------------------------------------------------------

const int MAX = 310009;

char a[MAX],b[MAX];
int main()
{
  int i,j,k;
  test(){
    scs(a);
    scs(b);
    int l1 = strlen(a);
    int l2 = strlen(b);
    int ans = 0;
    stack<char>st;
    for(i=0;i<l2;i++){
      st.push(b[i]);
      if(b[i]==a[l1-1]){
        int cnt = 0;
        int ind = l1-1;
        vector<char>v;
        while(!st.empty() && ind>=0 && st.top()==a[ind]){
          ind--;
          v.push_back(st.top());
          st.pop();
          cnt++;
        }
        if(cnt==l1){
          ans++;
        }else{
          int x = v.size();
          for(j=x-1;j>=0;j--){
            st.push(v[j]);
          }
        }
      }
    }
    printf("%d\n",ans);
  }
  return 0;
} 
