#include <bits/stdc++.h>

using namespace std;

int main()
{
  int a[100],d,i=0,n;
  cin>>n;
  while(i<n){
      cin>>a[i];i++;}
      d=a[n-1]-a[n-2];
     
       if(a[n-1]==15){cout<<"DOWN"<<endl;return 0;}
       if(a[n-1]==0){cout<<"UP"<<endl;return 0;} 
        if(n==1){cout<<"-1"<<endl;return 0;}
      if(d>0)cout<<"UP"<<endl;
      else cout<<"DOWN"<<endl;
 return 0;
}