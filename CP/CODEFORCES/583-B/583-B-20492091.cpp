#include <bits/stdc++.h>
using namespace std;
int n,a[1001],ans,cur,v[1001];
int main(){
	cin>>n;
	for(int i=0;i<n;++i)
		cin>>a[i];
	int di=1;
	for(int i=0;cur<n;i+=di){
		if(i==n) { di=-1; ++ans; }
		else if(i==-1) { di=1; ++ans; }
		else if(a[i]<=cur&&!v[i]){
			v[i]=1;
			++cur;
		}
	}
	cout<<ans<<endl;
}