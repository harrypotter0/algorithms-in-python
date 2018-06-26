#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
int n,i,j=0;
string s;
cin>>n>>s;
sort(s.begin(),s.end());
for(i=0;i<s.length();i++)
{
if(i%n==0) j=i;
if(s[i]!=s[j]) break;
}
if(i<s.length() || s.length()%n) cout<<-1;
else
{
for(i=1;i<=n;i++)
{
for(j=0;j<s.length();j+=n)
{
cout<<s[j];
}
}
}
return 0;
}