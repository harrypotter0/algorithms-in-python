#include <bits/stdc++.h>

using namespace std;

int main()
{
 int a,b;
 cin>>a>>b;
 cout<<(7-max(a,b))/__gcd(6,7-max(a,b))<<"/"<<6/__gcd(6,7-max(a,b));
 return 0;
}