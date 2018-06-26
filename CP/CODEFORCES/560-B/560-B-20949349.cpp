#include<bits/stdc++.h>
#define f(i,a,b) for(i=a;i<b;i++)
using namespace std;
int main()
{
    int a,b,c,d,e,f,i;cin>>a>>b>>c>>d>>e>>f;
    f(i,0,4){
        if(c+e<=a&&d<=b&&f<=b||c<=a&&e<=a&&d+f<=b){cout<<"YES";return 0;}
        if(i%2)swap(c,d);
        swap(e,f);
    }
    cout<<"NO";
}