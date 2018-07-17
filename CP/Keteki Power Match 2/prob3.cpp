#include<bits/stdc++.h>
using namespace std;
#define pb push_back

int main(){
  int i,j,a[10][10],counter,n,m,x,y,t;
  cin>>t;
  while(t--){
    int vis[10][10]={0};
    cin>>n>>m;

    for(i=0;i<n;i++){
      for(j=0;j<m;j++)
         cin>>a[i][j];
    }

    for(i=0,counter=1;i<n;i++){
      for(j=0;j<m;j++){
        if(!vis[i][j]){
          deque<pair<int,int>> d;
          d.pb({i,j});
          while (!d.empty()) {
            x = d.front().first;
            y = d.front().second;
            d.pop_front();
            vis[x][y] = counter;
            if(x>0 && !vis[x-1][y] && a[x-1][y]==a[x][y])
              d.pb({x-1,y});
            if(y>0 && !vis[x][y-1] && a[x][y-1]==a[x][y])
              d.pb({x,y-1});
            if(x<n && !vis[x+1][y] && a[x+1][y]==a[x][y])
              d.pb({x+1,y});
            if(y<m && !vis[x][y+1] && a[x][y+1]==a[x][y])
              d.pb({x,y+1});
          }
          counter++;
        }
      }
    }

    cout<<(counter-1)<<"\n";
  }
  return 0;
}
