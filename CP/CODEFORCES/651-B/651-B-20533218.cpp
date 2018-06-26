#include <iostream>
#include <algorithm>
using namespace std;
main()
{
    long long n,t,i=0,a[2000],k=0;;
    cin>>n;
   while(i<n){
    cin>>t;
    a[t]++;
    k=max(a[t],k);
    i++;
 } 
cout<<n-k;
    return 0;
}