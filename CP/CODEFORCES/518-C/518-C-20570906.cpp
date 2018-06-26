#include <iostream>
using namespace std;

long long n,m,k,a,b,x,y,i,p[100005],t[100005];

main(){
	cin>>n>>m>>k;
	
	while(i<n){
		cin>>p[i];
		t[p[i]]=i;
		i++;
	}i=0;
	
	while(i<m){
		cin>>x;
		if(t[x]!=0){
			y+=t[x]/k;
			t[x]--;
			t[p[t[x]]]++;
			swap(p[t[x]],p[t[x]+1]);
		}
		i++;
	}
	cout<<y+m;
}