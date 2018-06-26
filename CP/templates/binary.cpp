#include <iostream>
using namespace std;
int a[1002];
int main() {
for(int i=0;i<1002;i++)
   a[i]=i*i;
int t;
cin>>t;
while(t--){
   int n;
   cin>>n;
   int ans=0;
   for(int i=n;i>=2;i--){
      int l = 0;
      int r = i-1;
      while (l < r){
          if (a[l] + a[r] == a[i])
               ans=max(ans,l+r+i);
          (a[l] + a[r] < a[i])?  l++: r--;
      }
   }
    cout<<ans<<endl;
}
return 0;
}
