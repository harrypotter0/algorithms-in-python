#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

const int N = 5000;

vll graph[N+1];
int num[N+1];
bool four = false;

void dfs(int u,int c = 0)
{
  num[u] = c;

  for(int v : graph[u])
  {
    if(num[v] != 0)
    {
      if(abs(num[v] - num[u]) == 3)
        four = true;
    }else
    {
      dfs(v,c+1);
    }
  }
}

int main(void)
{
  int n,m;
  cin>>n>>m;

  for(int i=0;i<m;i++)
  {
    int u,v;
    cin>>u>>v;
    graph[u].pb(v);
    graph[v].pb(u);
  }

  for(int i=1;i<=n;i++)
    if(num[i] == 0)
      dfs(i);

  if(four)
    cout<<"Yes";
  else
    cout<<"No";
}
