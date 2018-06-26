#include<bits/stdc++.h>
using namespace std;
int main()
{
string s;
cin>>s;
int u=0,d=0,l=0,r=0;
if(s.length()%2!=0){cout<<-1; return 0;}
for(int i=0;i<s.length();i++){if(s[i]=='U')u++; else if(s[i]=='D')d++; else if(s[i]=='L')l++; else r++;}
cout<<(abs(l-r)+abs(u-d))/2;
}