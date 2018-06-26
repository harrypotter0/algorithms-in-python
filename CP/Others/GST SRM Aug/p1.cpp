#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k,arr[200202]={0};
  cin>>n>>k;
  for(int i =0;i<n;i++){
    cin>>arr[i];
  }
  int sum =0,f=0;
  for(int i =0;i<n;i++){
    sum+=arr[i];
    if(sum>=k){
      f=1;
      break;
    }
  }
    if(f==1)
        cout<<"YES\n";
    else
        cout<<"NO\n";

    }
    return 0;
}
