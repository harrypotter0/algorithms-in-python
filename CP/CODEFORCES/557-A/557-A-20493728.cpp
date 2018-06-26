#include<iostream>
#include<algorithm>
using namespace std;
main()
{int m,k,a,b,c,d,e,f,n;cin>>n>>a>>b>>c>>d>>e>>f;
k=min(b,n-c-e);
n=n-k;
m=min(d,n-e);
cout<<k<<" "<<m<<" "<<n-m;}