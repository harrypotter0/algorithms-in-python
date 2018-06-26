#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    long long n,i,a=0,b,c=0,p=0,s=0;
    cin>>n;
while(cin>>b){
 s+=abs(a-b);
    a=b;
 } 
cout<<s;
    return 0;
}