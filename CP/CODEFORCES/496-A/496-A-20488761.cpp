#include<iostream>
using namespace std;
int main(){
	int n,a[101],i,d=0,mx=30000;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=2;i<=n;i++) d=max(d,a[i]-a[i-1]);
	for(i=2;i<n;i++) mx=min(mx,max(d,a[i+1]-a[i-1]));
	cout<<mx;
}