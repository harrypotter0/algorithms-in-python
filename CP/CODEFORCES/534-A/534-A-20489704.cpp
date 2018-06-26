#include <iostream>

using namespace std;

int main()
{int n;cin>>n;
if(n==1 or n==2)
  {cout <<1<<endl<<"1";
  return 0;
  }
if(n==3)
 {cout<<2<<endl<<"1 3";
 return 0;
 }
cout<<n<<endl;
for (int i=2;i<=n;i+=2)cout<<i<<" ";
for (int i=1;i<=n;i+=2)cout<<i<<" ";


}