#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
#define fast {ios_base::sync_with_stdio(false);cin.tie(NULL);}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
       ll n,d=0;
       cin>>n;
       while(n)
       {
           if(!(n&1))
           d++;
           n=n>>1;
       }
       ll xx=pow(2,d);
       cout<<xx<<endl;
    }
}


/*

Example-1

Input:
1
5

Output:
2


Example-2

Input:
1
10

Output:
4

*/
