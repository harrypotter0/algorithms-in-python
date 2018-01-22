#include <bits/stdc++.h>

using namespace std;

const int oo = 1000000000;

const int N = 100005;

int a[N], val[N][2], f[N][2], g[N][2];

void solve() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", a+i);
    }

    if (n == 1) {
        printf("0\n");
        return;
    }

    for (int i = 1; i <= n; i++) {
        val[i][0] = a[i];
        val[i][1] = a[n+1-i];
    }

    int m = n/2;
    for (int i = 1; i <= m; i++)
    for (int k = 0; k < 2; k++)
        f[i][k] = g[i][k] = oo;
    f[1][0] = g[1][0] = 0;
    f[1][1] = g[1][1] = 1;
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                int c1 = val[i][j];
                int c2 = val[i+1][k];
                if (((i & 1) && (c1 <= c2)) || (((i & 1) == 0) && c1 >= c2)) continue;
                int t = n+1-i;
                c1 = val[t][j];
                c2 = val[t-1][k];
                if (((t & 1) && (c1 <= c2)) || (((t & 1) == 0) && c1 >= c2)) continue;
                f[i+1][k] = min(f[i+1][k], f[i][j] + k);
            }
            for (int k = 0; k < 2; k++) {
                int c1 = val[i][j];
                int c2 = val[i+1][k];
                if (((i & 1) && (c1 >= c2)) || (((i & 1) == 0) && c1 <= c2)) continue;
                int t = n+1-i;
                c1 = val[t][j];
                c2 = val[t-1][k];
                if (((t & 1) && (c1 >= c2)) || (((t & 1) == 0) && c1 <= c2)) continue;
                g[i+1][k] = min(g[i+1][k], g[i][j] + k);
            }
        }
    }

    int ans = oo;

    if (n % 2 == 0) {
        for (int j = 0; j < 2; j++) {
            int c1 = val[m][j];
            int c2 = val[m+1][j];
            if (((m&1) && (c1 > c2)) || ((m&1) == 0 && (c1 < c2)))
                ans = min(ans, f[m][j]);
            if (((m&1) && (c1 < c2)) || ((m&1) == 0 && (c1 > c2)))
                ans = min(ans, g[m][j]);
        }
    }
    else {
        int c1 = a[m];
        int c2 = a[m+2];
        int b = a[m+1];
        if ((((m+1)&1) && b > c1 && b > c2) || (((m+1)&1) == 0 && b < c1 && b < c2))
            ans = min(ans, min(f[m][0], f[m][1]));
        if ((((m+1)&1) && b < c1 && b < c2) || (((m+1)&1) == 0 && b > c1 && b > c2))
            ans = min(ans, min(g[m][0], g[m][1]));
    }

    if (ans >= oo) ans = -1;
    printf("%d\n", ans);
}

int main() {
    int ct;
    scanf("%d", &ct);

    while (ct--) solve();
}
