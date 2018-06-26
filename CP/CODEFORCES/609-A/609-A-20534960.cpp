#include <iostream>
#include <algorithm>
using namespace std;
main()
{
    long long n,m,i=0,a[2000],c=0;
    cin>>n>>m;
   while(i<n){
    cin>>a[i];
    i++;
 }  sort(a,a+n);
 for(i=n-1;m>0;i--){m-=a[i];c++;}

cout<<c;
    return 0;
}