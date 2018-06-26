#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cassert>
#define d0(x) cout<<x<<" "
#define d1(x) cout<<x<<"\n"
#define d2(x,y) cout<<x<<" "<<y<<"\n"
#define d3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define d4(x,y,z,w) cout<<x<<" "<<y<<" "<<z<<" "<<w<<"\n"
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define fi           first
#define se           second
#define sz(x)       (ll int)x.size()
#define ll          long long
#define pb          push_back
#define	endl		    '\n'
#define MOD         1000000007
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define prec(n) fixed<<setprecision(n)
#define mem(dp) memset(dp,-1,sizeof(dp))
const int inf =1e9;
using namespace std;
#define MAX  100005

using namespace std;

int gcd(int a, int b) {
  while(b) {
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}

void solve() {
  #ifdef JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
  #endif

  int n, m, s, e;
  cin >> n >> m >> s >> e;

  assert(1 <= n);
  assert(1 <= m);
  assert(1 <= s && s <= n);
  assert(1 <= e && e <= n);

  s--;
  e--;

  vector<int> dist(n, -1);

  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    assert(1 <= u && u <= n);
    assert(1 <= v && v <= n);
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  queue<int> q;
  q.push(s);
  dist[s] = 0;

  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int v : g[u]) {
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }

  if (s == e) {
    printf("NO\n");
  } else if (dist[e] == -1) {
    printf("NO\n");
  } else {
    printf("YES %d\n", max(0, dist[e] - 1));
  }
}

int main() {
  int t;
  cin >> t;
  assert(1 <= t);

  while (t--) {
    solve();
  }
}
