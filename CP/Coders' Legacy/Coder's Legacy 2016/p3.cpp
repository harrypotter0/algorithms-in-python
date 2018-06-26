#include <bits/stdc++.h>
using namespace std;

int a[200], b[200];
int n, m;

void get(int &n, int c[]) {
  int p, q, f, x;
  scanf("%d%d%d", &n, &p, &q);
  f = q; x = q;
  for (int i = 2; i * i <= x; ++i) {
    if (x % i == 0) {
      f = f / i * (i - 1);
      while (x % i == 0) x /= i;
    }
  }
  if (x > 1) f = f / x * (x - 1);
	cout<<f<<"f"<<endl;
  if (n <= 100000) {
    int r = 1;
    for (int i = 0; i < n; ++i) {
      r = r * p % q;
      c[r]++;
    }
  } else {
    int m = n / f, r = 1;
    for (int i = 0; i < f; ++i) {
      r = r * p % q;
      c[r] += m;
    }
    for (int i = 0; i < n % f; ++i) {
      r = r * p % q;
      c[r]++;
    }
  }
}

int main() {
  get(n, a);
  get(m, b);
  double r = 0;
  for (int i = 100, j = 100; i >= 0 && j >= 0;) {
    int s = min(a[i], b[j]);
    a[i] -= s; b[j] -= s;
    r += double(i - j) * s;
    if (a[i] == 0) --i;
    if (b[j] == 0) --j;
  }
  printf("%.1f\n", r / max(n, m));
  return 0;
}
