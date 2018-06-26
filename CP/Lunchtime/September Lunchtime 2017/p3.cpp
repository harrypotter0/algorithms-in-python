#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void gi(int &x) {char ch = getchar(); x = 0; while (ch < '0' || ch > '9') ch = getchar(); while (ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();}
#define fi first
#define se second
#define mp make_pair

ll S(int x) {return (1ll * x * (x + 1)) >> 1;}
int N, l, K;
int str[1010101], R[1010101], pfx[1010101], l1[1010101], r1[1010101];
//char >= 0: real char
//char < 0: a block of -c 0's
pair <int, int> pos[1010101];
void add_block(int x) {
  if (x <= 0) return;
  if (x == 1) str[++l] = 0;
  else {
    str[++l] = -(x >> 1);
    if (x & 1) str[++l] = 0;
    str[++l] = -(x >> 1);
  }
}

void manacher() {
  int k = 0, mk = 0;
  for (int i = 1; i <= l; i++) {
    int j = k + k - i;
    for (R[i] = max(0, min(R[j], mk - i)); R[i] < i && i + R[i] <= l && str[i + R[i]] == str[i - R[i]]; R[i]++); R[i]--;
    if (i + R[i] > mk) k = i, mk = i + R[i];
  }
}
#define count(l, r) (pfx[r] - pfx[(l) - 1])

void doit() {
  int i, j, k;
  ll ans = 0;
  gi(N); gi(K); l = 0;
  for (i = 1; i <= K; i++) gi(pos[i].fi), gi(pos[i].se);
  sort(pos + 1, pos + K + 1);
  pos[K + 1].fi = N + 1; add_block(pos[1].fi - 1);
  for (i = 1; i <= K; i++) {
    str[++l] = pos[i].se; add_block(pos[i + 1].fi - pos[i].fi - 1);
  }
  for (i = 1; i <= l; i++) pfx[i] = pfx[i - 1] + (str[i] >= 0 ? 1 : -str[i]);
  for (i = 1; i <= l; i++) l1[i] = (str[i] > 0 ? 0 : l1[i - 1] + (str[i] == 0 ? 1 : -str[i]));
  for (r1[l + 1] = 0, i = l; i; i--) r1[i] = (str[i] > 0 ? 0 : r1[i + 1] + (str[i] == 0 ? 1 : -str[i]));
  manacher();
  for (i = 1; i <= l; i++) {
    if (str[i] >= 0) {
      ans += count(i, i + R[i]);
      int _l = i - R[i] - 1, _r = i + R[i] + 1;
      if (_l > 0 && _r <= l) ans += min(l1[_l], r1[_r]);
    } else ans += S(-str[i]);
  }
  cout << ans << endl;
}

int main() {int T; gi(T); while (T--) doit(); return 0;}
