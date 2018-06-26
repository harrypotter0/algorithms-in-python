#include<iostream>
#include<map>
using namespace std;
main()
{map<string,int>s;
int n,i,m=0;cin>>n;
string z;
for(i=0;i<n;i++){cin>>z;s[z]++;m=max(m,s[z]);}
cout<<m;
}