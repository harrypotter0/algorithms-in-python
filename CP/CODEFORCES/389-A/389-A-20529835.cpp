#include <bits/stdc++.h>

using namespace std;

int main()
{
   int n,x,g;cin>>n;
   cin>>g;
   for(;cin>>x;)g=__gcd(g,x);
   cout<<g*n;
    return 0;
}