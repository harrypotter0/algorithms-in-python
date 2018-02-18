#include<bits/stdc++.h>
using namespace std;
const int MAX=400005;
int timer,counter,n,m,disk[MAX],low[MAX],vis[MAX],scc[MAX];
stack<int> st;
vector<int> adj[MAX];
int neg(int a){ return (a>n ? a-n : a+n); }
void dfs_tarjan(int node){
  disk[node]=low[node]=++timer;
  vis[node]=1;
  st.push(node);
  for(int child : adj[node]){
    if(vis[child]==1){
      low[node]=min(low[node],disk[child]);
    }else if(vis[child]==0){
      dfs_tarjan(child);
      low[node]=min(low[node],low[child]);
    }
  }
  if(disk[node]==low[node]){
    counter++;
    while(st.top()!=node){
      scc[st.top()]=counter;
      vis[st.top()]=-1;
      st.pop();
    }
    scc[st.top()]=counter;
    vis[st.top()]=-1;
    st.pop();
  }
}
int main(){
  int test,a,b,i;
  scanf("%d",&test);
  while(test--){
    counter=timer=0;
    scanf("%d%d",&n,&m);
    for(i=1;i<=2*n;i++){
      vis[i]=disk[i]=low[i]=scc[i]=0;
      adj[i].clear();
    }
    for(i=1;i<=n;i++){
      adj[neg(n+i)].push_back(i);
      adj[neg(i)].push_back(n+i);
      adj[n+i].push_back(neg(i));
      adj[i].push_back(neg(n+i));
    }
    for(i=1;i<=m;i++){
      scanf("%d%d",&a,&b);
      adj[neg(a)].push_back(b);
      adj[neg(b)].push_back(a);
    }
    for(int node=1;node<=2*n;node++){
        if(vis[node]==0)
            dfs_tarjan(node);
    }
    for(i=1;i<=n;i++){
      if(scc[i]==scc[neg(i)])
        break;
    }
    if(i<=n){
      printf("boring\n");
    }else{
      printf("interesting\n");
    }
  }
  return 0;
}
/*

Input:
2
2 6
3 1
1 4
2 4
2 3
4 3
2 1
4 4
1 3
2 4
5 7
6 8

Output:
boring
interesting

*/
