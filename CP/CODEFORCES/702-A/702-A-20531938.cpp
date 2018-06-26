#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n,i,a=0,b,c=0,p=0;
    cin>>n;
while(cin>>b){
 if(a<b)c++;
 else
 c=1;
     p=max(c,p);a=b;
 } 
cout<<p;
    return 0;
}