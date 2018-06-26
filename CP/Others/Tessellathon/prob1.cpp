#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Max=5001;

vector<ll> adj[Max];
bool mark[Max];

bool dfsrec(ll cur,ll s,ll k)
{
    if(k==0&&cur==s)  return true;
    if(k==0)          return false;
    if(mark[cur])   return false;
    mark[cur]=true;
    bool state=false;
    ll ss=adj[cur].size();
    for(ll i=0;i<ss;i++)
    {
        if(dfsrec(adj[cur][i],s,k-1))   {state=true;break;}
    }
    mark[cur]=false;
    return state;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m,i,j,k,u,v;
    cin>>n>>m;
    bool flg=false;
    for(i=0;i<m;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(i=1;i<=n;i++)
    {
        memset(mark,0,sizeof mark);
        if(dfsrec(i,i,4))  {flg=true;break;}
    }
    if(flg) cout<<"Yes";
    else    cout<<"No";
    return 0;
} 
