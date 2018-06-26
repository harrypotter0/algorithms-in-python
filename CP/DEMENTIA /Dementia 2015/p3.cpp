#include <bits/stdc++.h>
using namespace std;
inline void inp(int &n ) {//fast input function
  n=0;
  int ch=getchar(),sign=1;
  while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
  while( ch >= '0' && ch <= '9' )
  n=(n<<3)+(n<<1)+ ch-'0', ch=getchar();
  n=n*sign;
}
typedef long long ll;
typedef vector <int> vi;
typedef pair< int ,int > pii;
typedef pair< int, ll > pil;
typedef istringstream iss;
typedef ostringstream oss;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define ln length()
#define rep(i,n) for(int i=0;i<n;i++)
#define fu(i,a,n) for(int i=a;i<=n;i++)
#define fd(i,n,a) for(int i=n;i>=a;i--)
#define all(a) a.begin(),a.end()
#define ESP (1e-9)
#define gi(n) scanf("%d",&n)
#define gl(n) cin >> n
#define pi(n) printf("%d",n)
#define pl(n) printf("%lld",n)
#define ps printf(" ")
#define pn printf("\n")
#define N 90
#define MOD 1000000007
int main () {
  int t;
  scanf("%d", &t);
  while(t--){
  int n, m;
  inp(n); inp(m);
  vector<int> graph[n+1];
  for (int i = 0; i < m; i++) {
    int x, y;
    inp(x); inp(y);
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  int ans = 0;
  while (1) {
    int num = 0;
    vector <int> tmp;
    for (int i = 1; i <= n; i++) {
    if (graph[i].size() == 1) {
      num++;
      tmp.push_back(i);
    }
    }
    if (num > 0) {
    ans++;
    for (int i = 0; i < num; i++) {
      int neigh = graph[tmp[i]][0];
      graph[tmp[i]].clear();
      graph[neigh].erase(remove(graph[neigh].begin(), graph[neigh].end(),tmp[i]), graph[neigh].end()); // erase then remove
    }
    }
    else break;
  }
  printf("%d\n",ans);
  }
}
