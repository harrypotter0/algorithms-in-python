#include <bits/stdc++.h>
using namespace std;
 main()
{
    long long r,a,b,c,d;
    cin>>r>>a>>c>>b>>d;
    cout<<ceil(sqrt((b-a)*(b-a)+(d-c)*(d-c))/(2*r));
}