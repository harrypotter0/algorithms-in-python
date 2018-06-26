#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

#define fi 				first
#define sec 			second
#define inchar			getchar_unlocked
#define outchar(x)		putchar_unlocked(x)

const int MAX = 1000001;
const int MAXN = 100001;
const int LIM = 78500;
const int BLK = 200;

vector<int> lp, primes;

void factor_sieve() {
  lp.resize(MAX);
  for (int i = 2; i < MAX; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      primes.emplace_back(i);
    }
    for (int j = 0; j < primes.size() && primes[j] <= lp[i]; ++j) {
      int x = i * primes[j];
      if (x >= MAX) break;
      lp[x] = primes[j];
    }
  }
}

int st[MAXN];
int en[MAXN];
int idx[MAXN];
int invp[MAX];
LL sum[LIM][MAXN/BLK+2];
vector<pii> a[MAXN];

int main() {
  factor_sieve();
  int ctr = 1, pos;
  invp[1] = 1;
  for(int i = 2; i < MAX; ++i) {
    int j = i;
    while(j < MAX && lp[j] != j) {
      j += 1;
    }
    for(int k = i; k <= j; ++k) {
      invp[k] = ctr;
    }
    ctr += 1;
    i = j;
  }
  int n, q, l, r;
  int x, y, u, v;
  inpos(n);
  ctr = 0, pos = 1;
  for(int i = 1; i <= n; ++i) {
    inpos(x);
    while(x != 1) {
      int p = lp[x], e = 0;
      while(x % p == 0) x /= p, e += 1;
      sum[invp[p]][pos] += e;
      a[i].push_back({p, e});
    }
    if (st[pos] == 0) {
      st[pos] = i;
    }
    idx[i] = pos;
    ctr += 1;
    if (ctr > BLK) {
      en[pos] = i;
      ctr = 0;
      pos += 1;
    }
  }
  for(int j = 1; j < pos; ++j) {
    for(int i = 1; i < LIM; ++i) {
      sum[i][j] += sum[i-1][j];
    }
  }
  inpos(q);
  while(q--) {
    inpos(l), inpos(r), inpos(x), inpos(y);
    LL ans = 0;
    int cmpx = invp[x], cmpy = invp[y];
    if (lp[y] != y) {
      cmpy -= 1;
    }
    if (cmpx <= cmpy) {
      int u = idx[l], v = idx[r];
      if (u == v) {
        for(int i = l; i <= r; ++i) {
          for(auto it : a[i]) {
            if (it.fi >= x && it.fi <= y) {
              ans += it.sec;
            }
          }
        }
      }
      else {
        if (st[u] != l) {
          for(int i = l; i <= en[u]; ++i) {
            for(auto it : a[i]) {
              if (it.fi >= x && it.fi <= y) {
                ans += it.sec;
              }
            }
          }
          u += 1;
        }
        if (en[v] != r) {
          for(int i = st[v]; i <= r; ++i) {
            for(auto it : a[i]) {
              if (it.fi >= x && it.fi <= y) {
                ans += it.sec;
              }
            }
          }
          v -= 1;
        }
        for(int i = u; i <= v; ++i) {
          ans += sum[cmpy][i] - sum[cmpx-1][i];
        }
      }
    }
    outpos(ans);
  }
  return 0;
}
