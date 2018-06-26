#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int MaxN = 1 << 27;
const int Maxn = 100005;
const int Maxm = 19;
const int Maxk = 30;

int n;
vector <int> neigh[Maxn];
int cur, lef[Maxn];
int L[Maxn], P[Maxn][Maxm];
int k;
vector <ii> good;
int add[Maxk][Maxk];
int dp[MaxN];
int res;

void Traverse(int v)
{
  lef[v] = ++cur;
  for (int i = 0; i < neigh[v].size(); i++) {
    int u = neigh[v][i];
    if (P[v][0] == u) continue;
    L[u] = L[v] + 1; P[u][0] = v;
    Traverse(u);
  }
}

int getLCA(int a, int b)
{
  if (L[a] < L[b]) swap(a, b);
  for (int i = Maxm - 1; i >= 0; i--)
    if (L[a] - (1 << i) >= L[b])
      a = P[a][i];
  if (a == b) return a;
  for (int i = Maxm - 1; i >= 0; i--)
    if (P[a][i] != P[b][i])
      a = P[a][i], b = P[b][i];
  return P[a][0];
}

int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int a, b; scanf("%d %d", &a, &b);
    neigh[a].push_back(b);
    neigh[b].push_back(a);
  }
  Traverse(1);
  for (int j = 1; j < Maxm; j++)
    for (int i = 1; i <= n; i++)
      P[i][j] = P[P[i][j - 1]][j - 1];
  scanf("%d", &k);
  for (int i = 0; i < k; i++) {
    int a; scanf("%d", &a);
    good.push_back(ii(-lef[a], a));
  }
  sort(good.begin(), good.end());
  for (int i = 0; i < good.size(); i++)
    for (int j = i + 1; j < good.size(); j++)
      add[i][j] = L[good[i].second] - L[getLCA(good[i].second, good[j].second)];
  res = n - 1;
  for (int i = 1; i < 1 << int(good.size()); i++) {
    int lst = __builtin_popcount((i & -i) - 1);
    if (i == 1 << lst) dp[i] = L[good[lst].second];
    else {
      int cur = (i ^ 1 << lst);
      int lst2 = __builtin_popcount((cur & -cur) - 1);
      dp[i] = dp[cur] + add[lst][lst2];
    }
    res ^= (n - 1 - dp[i]);
  }
  printf("%d\n", res);
  return 0;
}
    
