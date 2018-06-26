#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;

inline void upd(int &a, int b) {
  a = max(a, b);
}


void solve(){
  int n,k,arr[35][35][35][35];
  cin>>k>>k;
  for(int i=0;i<=k+1;i++)for(int j=0;j<=k+1;j++)
  for(int l=0;l<=k+1;l++)for(int s=0;s<=k+1;s++)
    arr[i][j][l][s]= -1e9;

  arr[0][0][0][0]=0;

  string st;
  cin>>st;

  for(auto c:st)
  for(int i=k+1;i>=0;i--)for(int j=k+1;j>=0;j--)
  for(int l=k+1;l>=0;l--)for(int s=k;s>=0;s--){
      if(c=='c'){
          upd(arr[min(i+1,k+1)][j][l][s],arr[i][j][l][s]+1);
      }else
      if(c=='h'){
          upd(arr[i][min(i+j,k+1)][l][s],arr[i][j][l][s]+1);
      }else
      if(c=='e'){
          upd(arr[i][j][min(j+l,k+1)][s],arr[i][j][l][s]+1);
      }else
      if(s+l<=k){
          upd(arr[i][j][l][s+l],arr[i][j][l][s]+1);
      }
  }

  int res=0;
  for (int i=0;i<=k+1;i++) for (int j=0;j<=k+1;j++)
  for (int l=0;l<=k+1;l++){
    //   if (arr[i][j][l][k]!=-1e9)
      upd(res,arr[i][j][l][k]);
  }
  if (res==0)
    cout<<-1<<'\n';
  else
    cout<<st.size()-res<<'\n';

}

int main(){
  int t;
  cin>>t;
  while(t--){
    solve();
  }
}
/*

5
7 3
chehefc
8 4
chehefch
19 24
ccccchhhhheeeeeffff
20 5
echhhfhfcecfhechfcch
99 27
ffhffhffcfechchccccfhhhfhhhhhhehhhehhhhheeeeefeeeeeeheeheeeeffcfffffffffffhffffchffeffcefefhhfcehfe

*/
