#include <bits/stdc++.h>

using namespace std;

const int MaxN = (int)1e4 + 10;
const int MaxA = (int)1e8 + 10;
const int INF = 1e9;
const int MOD = 1000000007;

int t[MaxN][MaxN];
int pre[MaxA], a[MaxN], n, q;

inline void relax(int &a, int b) {
	if (a < b) {
		a = b;
	}
}

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &q);
	srand(time(NULL));
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		assert (a[i] >= 1 && a[i] <= 100000000);
		for (int d = 1; d * d <= a[i]; ++d) {
			if (a[i] % d == 0) {
				if (pre[d] != 0) {
					relax(t[pre[d]][i], d);
				}
				pre[d] = i;
				if (d * d != a[i]) {
					if (pre[a[i] / d] != 0) {
						relax(t[pre[a[i] / d]][i], a[i] / d);
					}
					pre[a[i] / d] = i;
				}
			}
		}
	}
	for (int l = 2; l <= n; ++l) {
		for (int i = 1; i + l - 1 <= n; ++i) {
			int j = i + l - 1;
			relax(t[i][j], t[i + 1][j]);
			relax(t[i][j], t[i][j - 1]);
		}
	}
	for (int it = 1; it <= q; ++it) {
		int l, r;
		scanf("%d%d", &l, &r);
		assert (1 <= l && l < r && r <= n);
		printf("%d\n", t[l][r]);
	}
	return 0;
}
 
