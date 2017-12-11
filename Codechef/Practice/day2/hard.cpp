#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
#define SZ(a) ((int)((a).size()))
#define printCase() "Case #" << caseNum << ": "
#define pb push_back
#define mp make_pair
#define EPS (1e-9)
#define PI 3.1415926535
#define inf ((int)1e9)
#define INF ((ll)9e18)
#define mod (1000000000 + 7)
#define newl '\n'
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int N = 5e4 + 5, LOGN = 20;
vvi g(N);
bitset<N> bs; vi primes;
int ans = 0, n, q, a, b, cnt[N] = {}, lvl[N] = {}, par[N], sz[N];
void dfs(int u, int pre) {
    sz[u] = 1;
    for(int v : g[u]) {
        if(v != pre && !lvl[v]) {
            dfs(v, u);
            sz[u] += sz[v];
        }
    }
}
int centroid(int u, int pre, int tot) {
    for(int v : g[u]) {
        if(v != pre && !lvl[v] && sz[v] > tot/2) {
            return centroid(v, u, tot);
        }
    }
    return u;
}
template<typename Lambda>
int dfs1(int u, int pre, int dep, Lambda op) {
    op(dep);
    for(int v : g[u]) {
        if(v != pre && !lvl[v]) {
            dfs1(v, u, dep + 1, op);
        }
    }
}
void solve(int u) {
    for(int v : g[u]) {
        if(!lvl[v]) {
            dfs1(v, u, 1, [&](int x) {cnt[x]++;});
        }
    }
    for(int v : g[u]) {
        if(!lvl[v]) {
            dfs1(v, u, 1, [&](int x) {cnt[x]--;});
            dfs1(v, u, 1, [&](int x) {
                for(int p : primes) {
                    if(p - x > 0 && p - x < n) ans += cnt[p-x];
                }
                if(bs[x]) ans++;
            });
        }
    }
}
void decompose(int u) {
    if(!u) {
        dfs(1, 0); u = centroid(1, 0, sz[1]);
        par[u] = 0;
    }
    lvl[u] = lvl[par[u]]+1;
    solve(u);
    for(int v : g[u]) {
        if(lvl[v]) continue;
        dfs(v, 0); v = centroid(v, 0, sz[v]);
        par[v] = u;
        decompose(v);
    }
}
void sieve() {
    bs.set(); bs[0] = bs[1] = 0;
    FOR(i, 2, n) {
        if(!bs[i]) continue;
        primes.pb(i);
        for(ll j = i * 1LL *  i; j < n; j += i) bs[j] = 0;
    }
}
int main() {
    SYNC
    cin >> n;
    sieve();
    FOR0(i, n - 1) {
        cin >> a >> b;
        g[a].pb(b); g[b].pb(a);
    }
    lvl[0] = 0;
    decompose(0);
    cout << fixed << setprecision(10) << ans/(0.5 * n * (n - 1));
} 
