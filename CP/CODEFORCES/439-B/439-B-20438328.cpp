#include<bits/stdc++.h>
using namespace std;
long long n,a[100005],ans;
int x,i;
main(){
	cin>>n>>x;
	for(i=0;i<n;i++){
		cin>>a[i];}
	sort(a,a+n);
	for(i=0;i<n;i++){
		ans+=a[i]*max(x-i,1);}
	cout<<ans;}