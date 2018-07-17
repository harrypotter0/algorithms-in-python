// Still unsolved What the fuck !

#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 2e3 + 5;

ll cnt[5], sum[5];
vector<int> a[5];
ll pre[N];

void solve() {

  for(int i = 0; i < 3; i++) {
    a[i].clear();
    cnt[i] = 0;
    sum[i] = 0;
  }

  int n, x, y;

  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d %d", &x, &y);
    x--, y--;
    a[x].push_back(y);
    sum[x] += y;
    cnt[x]++;
  }

  ll ans = 0;

  for(int i = 0; i < 3; i++) {
    sort(a[i].begin(), a[i].end());
  }

  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      if(i == j)	continue;
      for(int k = 0; k < a[i].size(); k++) {
        for(int p = k + 1; p < a[i].size(); p++) {
          ans += a[j].size() * 1LL * abs((a[i][p] - a[i][k]) * 1LL * (i - j));
        }
      }
    }
  }

  pre[0] = 0;
  for(int i = 0; i < a[1].size(); i++) {
    pre[i + 1] = pre[i] + a[1][i];
  }

  for(int i = 0; i < a[0].size(); i++) {
    int start = 0;
    for(int j = 0; j < a[2].size(); j++) {
      ll tot = a[0][i] + a[2][j];
      while(start < cnt[1] && 2*a[1][start] < tot) start++;
      ll contri = ((tot * start) - (2LL * pre[start])) + ((2LL * (pre[cnt[1]] - pre[start])) - (tot * (cnt[1] - start)));
      ans += contri;
    }
  }
  double res = double(ans) / 2.0;
  cout<<setprecision(7)<<fixed<<res<<'\n';
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    solve();
  }
}
