/*
 *
 ********************************************************************************************
 * AUTHOR : Akash Kandpal                                                                    *
 * Language: C++14                                                                          *
 * Motto : The master has failed more times than the beginner has even tried.               *                                                                *
 * IDE used: Atom                                                                           *
 * My Domain : http://harrypotter.tech/                                                     *
 ********************************************************************************************
 *
 */
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll          long long
#define pb          push_back
#define	endl		    '\n'
#define MOD         1000000007
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define prec(n) fixed<<setprecision(n)
#define mem(dp) memset(dp,-1,sizeof(dp))
const int inf =1e9;
#define MAX  100005
using namespace std;

int dad[100010];
int find(int x){
    if(dad[x]==x) return x;
    return dad[x]=find(dad[x]);
}
void uni(int x,int y){
    int X=find(x),Y=find(y);
    dad[X]=Y;
}

int main() {
  // your code goes here
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int n,m;
  scanf("%d%d",&n,&m);
  for(int k=1;k<=n;k++) dad[k]=k;
  for(int k=1;k<=m;k++){
      int x,y;
      scanf("%d%d",&x,&y);
      uni(x,y);
    //   for(int i =1;i<=n;i++){
    //     //   cout<<i<<" "<<dad[i]<<endl;
    //   }
    //   cout<<"--------"<<endl;
  }
  int q;
  scanf("%d",&q);
  while(q--){
      int x,y;
      scanf("%d%d",&x,&y);
      if(find(x)!=find(y)) puts("NO");
      else puts("YES");
  }
return 0;
}
