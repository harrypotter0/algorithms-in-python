#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

#define sd(x) scanf("%d",&x)
#define MP make_pair
#define PB push_back
#define MOD 329885391853LL
#define M 1000000
#define F first
#define S second
#define ll long long int
#define LL long long int

#define MAXN 1000

bool vis[MAXN];
int c[MAXN];
int ans, n;
string s[MAXN];

void dfs(int u){
    if(vis[u] == true){
        return;
    }
    // cout<<ans<<"before";
    ans |= c[u];
    // cout<<ans<<"after"<<"\n";
    vis[u] = true;
    for(int i = 0; i < n; i++){
        if(s[u][i] == 'Y'){
            dfs(i);
        }
    }
    return;
}

int main()
{
    int i;
    cin>>n;
    for(i = 0; i < n; i++){
        cin>>c[i]; //vertices
    }
    for(i = 0; i < n; i++){
        cin>>s[i];// edges
    }
    ans = 0;
    dfs(0);
    cout<<ans<<endl;
    return 0;
}
