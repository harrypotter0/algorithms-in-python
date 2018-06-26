#include <iostream>
using namespace std;
int main ()
{
int n, m;
cin >> n >> m;
string x;
for (int i=0; i<n; i++)
{
cin >>x;
for (int y=0; y<m; y++)
{if (x[y]=='.')
{if (y%2==i%2)
     x[y]='B';
else x[y]='W';
}
}
cout << x<<endl;}}