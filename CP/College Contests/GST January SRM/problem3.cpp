#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;

void solve() {
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
