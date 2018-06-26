#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, t[110], i=0, j;
	cin>>n;
	for(int i=0; i<n; i++) cin>>t[i];
	sort(t, t+n);
	j=n-1; i=0;
	cout<<"1 "<<t[i++]<<endl;(t[j]>0)? cout<<"1 "<<t[j--]<<endl: cout<<"2 "<<t[i++]<<" "<<t[i++]<<endl;
	cout<<j-i+1<<" ";
	for( ; i<=j; i++) cout<<t[i]<<" ";
	cout<<endl;
	return 0;
}