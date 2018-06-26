#include <iostream>
#include <algorithm>
using namespace std;
main()
{
    long long n,m,t,l=1000,i=0,a[2000],k=0,r=1000;
    cin>>n>>m;
   while(i<n){
    cin>>t;
    r=min(t,r);
    k=max(t,k);
    i++;
 }i=0; 
 while(i<m){
    cin>>t;
    l=min(t,l);i++;
 }
 r=max(r*2,k);
 
 if(r<l)
cout<<r;
else
cout<<-1;
    return 0;
}