#include<iostream>
using namespace std;
main()
{
int n,c,q=0,x=0,y;
cin>>n>>c;
for(int i=0; i<n; i++)
{
cin>>y;
if(y-x>c)
q=0;
q++;
x=y;
}
cout<<q;
return 0;
}