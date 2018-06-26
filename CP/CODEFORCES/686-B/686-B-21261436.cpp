#include <bits/stdc++.h>
using namespace std;
int a[105],n;
int main() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		for(int j=i;j&&a[j]<a[j-1];j--)
	{
		
		swap(a[j],a[j-1]);
		cout<<j-1<<" "<<j<<"\n";
	}}
	return 0;
}