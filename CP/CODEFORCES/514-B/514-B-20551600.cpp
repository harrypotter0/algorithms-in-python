#include<bits/stdc++.h>
using namespace std;
int main()
{
    long n; double x,y,a,b,k=0; set<double>s;cin>>n>>x>>y;
    for(long i=0;i<n;i++){cin>>a>>b;if(y!=b) s.insert((x-a)/(y-b)); else k=1;}
    cout<<s.size()+k;
}