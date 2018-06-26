#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 100005;

int t;
int n, m;
int Z[Maxn];
vector <ii> seq[Maxn];
ll BIT[Maxn];

void Hit(int x, ll val)
{
  for (int i = x; i > 0; i -= i & -i)
    BIT[i] += val;
}

ll Get(int x)
{
  ll res = 0;
  for (int i = x; i <= n; i += i & -i)
    res += BIT[i];
  return res;
}

ll Solve()
{
  priority_queue <ii> Q;
  ll res = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < seq[i].size(); j++)
      Q.push(seq[i][j]);
    Z[i] -= Get(i);
    while (Z[i] > 0) {
      if (Q.empty()) return -1;
      ii v = Q.top(); Q.pop();
      if (v.first < i) continue;
      int tk = min(Z[i], v.second);
      Z[i] -= tk; v.second -= tk; Hit(v.first, tk); res += tk;
      if (v.second > 0) Q.push(v);
    }
  }
  return res;
}

int main()
{
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &Z[i]);
      BIT[i] = 0;
      seq[i].clear();
    }
    for (int i = 0; i < m; i++) {
      int L, R, K; scanf("%d %d %d", &L, &R, &K);
      seq[L].push_back(ii(R, K));
    }
    ll res = Solve();
    if (res < 0) printf("NO\n");
    else printf("YES %lld\n", res);
  }
  return 0;
}
