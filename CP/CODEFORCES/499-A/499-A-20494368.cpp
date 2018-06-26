#include<iostream>
using namespace std;
int n,x,i,k=1,a,b,res;
main(){
	cin>>n>>x;
	while(i<n){
		cin>>a>>b;
		res+=(a-k)%x+(b-a+1);
		k=b+1;i++;}
	cout<<res;}