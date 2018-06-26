#include<iostream>
using namespace std;
int i;
string a;
main()
{
cin>>a;
for(i=0; i<a.size();i++)
{
if(a[i]=='r') 
cout<<i+1<<" ";
}
for(i=a.size()-1;i>=0;i--)
{
if(a[i]=='l') 
cout<<i+1<<" ";
}
}