#include<bits/stdc++.h>
using namespace std;
int n,i;
main()
{
    cin>>n;
    for (i=0;i<n*n/2;i++)
        cout<<i+1<<' '<<n*n-i<<"\n";
}