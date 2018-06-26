#include<iostream>
using namespace std;

int main()
{
long long n,i;
cin>>n;
for(i=1;i*i<=n; i++)
if (n%(i*i)==0)
{
n=n/i;
i=1;
}
cout<<n<<endl;
}