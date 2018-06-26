#include<bits/stdc++.h>
using namespace std;
int n,i;
int main(){
  string s;
  for(cin>>n;s.size()<n;s+=to_string(++i));
  cout<<s[n-1];
}