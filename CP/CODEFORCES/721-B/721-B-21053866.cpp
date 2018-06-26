#include<iostream>
#include<string>
using namespace std;
int main()
{
int n,k;
cin>>n>>k;
string s[n],x;
for(int i=0;i<n;i++)
{
cin>>s[i];
}
cin>>x;
int a=0,b=0;
for(int i=0;i<n;i++)
{
if(s[i].size()<x.size())
{a++;}
if(s[i].size()<=x.size())
{b++;}
}
b--;
cout<<a+((a/k)*5)+1<<' '<<b+((b/k)*5)+1<<endl;
}