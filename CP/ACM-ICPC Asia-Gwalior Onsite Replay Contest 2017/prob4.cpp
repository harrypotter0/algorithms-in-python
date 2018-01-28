#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll y[4][2010], sz[4];

ll case1(int l, int r) {
  ll ans = 0;
  int i, j;
  for(i = 1; i <= sz[l]; ++i) {
    ll cur = 0, cnt = 0;
    for(j = 1; j <= sz[r]; ++j) {
      ll z = abs(r - l)*abs(y[r][j] - y[l][i]) + 2*abs(r - l)*min(y[r][j], y[l][i]);
      ans += cnt*z - cur;
      cur += z;
      cnt += 1;
    }
  }
  return ans;
}

int main() {
  int t, i, j;
  // freopen("in.txt", "r", stdin);
  scanf("%d", &t);
  while(t--) {
    int n, u, v;
    scanf("%d", &n);
    sz[1] = sz[2] = sz[3] = 0;
    for(i = 1; i <= n; ++i) {
      scanf("%d %d", &u, &v);
      sz[u]++;
      y[u][sz[u]] = v;
    }
    for(i = 1; i <= 3; ++i) {
      sort(y[i] + 1, y[i] + sz[i] + 1);
    }
    ll ans = 0;
    //Case 1 and 2
    ans += case1(1, 2);
    //Case 2 and 1
    ans += case1(2, 1);
    // Case 2 and 3
    ans += case1(2, 3);
    // Case 3 and 2
    ans += case1(3, 2);
    // Case 1 and 3
    ans += case1(1, 3);
    // Case 3 and 1
    ans += case1(3, 1);
    // cout << ans << endl;
    // Case 1, 2 and 3
    for(i = 1; i <= sz[1]; ++i) {
      ll cur = 0, cnt = 0, ptr = 1;
      for(j = 1; j <= sz[2]; ++j) {
        ll z = abs(y[2][j] - y[1][i]) + 2*min(y[2][j], y[1][i]);
        while(ptr <= sz[3] and y[3][ptr] < y[2][j] + y[2][j] - y[1][i])	ptr++;
        ans += (ptr - 1)*z - (sz[3] - ptr + 1)*z;
        // cout << "in " << ptr << endl;
      }
    }
    // cout << ans << endl;
    for(i = 1; i <= sz[3]; ++i) {
      ll cur = 0, cnt = 0, ptr = 1;
      for(j = 1; j <= sz[2]; ++j) {
        ll z = abs(y[2][j] - y[3][i]) + 2*min(y[2][j], y[3][i]);
        while(ptr <= sz[1] and y[1][ptr] < y[2][j] + y[2][j] - y[3][i])	ptr++;
        ans += (ptr - 1)*z - (sz[1] - ptr + 1)*z;
      }
    }
    // cout << ans << endl;
    for(i = 1; i <= sz[1]; ++i) {
      ll cur = 0, cnt = 0, ptr = 1;
      for(j = 1; j <= sz[3]; ++j) {
        ll z = 2*abs(y[3][j] - y[1][i]) + 2*2*min(y[3][j], y[1][i]);
        while(ptr <= sz[2] and y[2][ptr] + y[2][ptr] <= y[1][i] + y[3][j])	ptr++;
        ans += (ptr - 1)*z - (sz[2] - ptr + 1)*z;
      }
    }
    // cout << ans << endl;
    long double fin = (long double)ans/2.0;
    printf("%.3Lf\n", fin);
  }
  return 0;
} 
