#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i;
    cin>>n;
    string s[1000];
    for(i=0;i<n;i++)
        cin>>s[i];
    sort(s,s+n);
    cout<<s[n/2]<<endl;

}