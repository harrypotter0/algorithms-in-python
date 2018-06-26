#include<iostream>
#include<algorithm>

using namespace std;
long long sum,n,a[100001];
int main(){
cin>>n;
for(int i=1;i<=n;i++)
	cin>>a[i];
sort(a+1,a+1+n);
for(int i=1;i<=n;i++){
	sum+=(a[i]*a[n-i+1]);
	sum%=10007;
}
cout<<sum;
return 0;
}