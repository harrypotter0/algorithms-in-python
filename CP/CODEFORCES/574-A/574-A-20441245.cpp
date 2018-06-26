#include <iostream>
#include <algorithm>
using namespace std;
int main(){int n,a[1001],i,p;cin>>n;for(i=0;i<n;i++)cin>>a[i];p=a[0];sort(a+1,a+n);
while (a[0]<=a[n-1]){a[0]++;a[n-1]--;sort(a+1,a+n);}cout<<a[0]-p;}