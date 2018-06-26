#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int n , e , w , u , v;
int a[N];
bool seen [N];
vector < int > X[N];
void solve(int u) {
    if(seen[u] | a[u] < w) {
        return;
    }
    seen[u] = true;
    for(int i = 0; i < (int) X[u].size(); ++i) {
        solve(X[u][i]);
    }
}

int main() {
    int tt , t = 0;
    scanf("%d" , &tt);
    while(tt--) {
        memset(seen , false , sizeof seen);
        for(int i = 0; i < N; ++i) X[i].clear();
        scanf("%d %d %d" , &n, &e, &w);
        for(int i = 1; i <= n; ++i) {
            scanf("%d" , a + i);
        }
        for(; e; --e) {
            scanf("%d %d" , &u , &v);
            X[u].push_back(v);
            X[v].push_back(u);
        }
        solve(1);
        printf("Case #%d: " , ++t);
        printf(seen[n] ? "YES\n" : "NO\n");
    }
    return 0;
}
