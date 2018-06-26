#include<bits/stdc++.h>
using namespace std;
string s,t;
map<string,string>m;
int main()
{
    int n;cin>>n;
    while(n--){
      cin>>s>>t;
      m[t]=(m[s]!=""?m[s]:s);
      m.erase(s);
    }
    cout<<m.size()<<endl;
    for(auto i: m)cout<<i.second<<" "<<i.first<<endl;
    return 0;
}