#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;int k,l;cin>>s>>k;
	if(s.size()%k){
		goto bad;
	}
	l=s.size()/k;
	for(int a=0;a<k;a++){
		for(int i=0;i<l;i++){
			if(s[a*l+i]!=s[a*l+l-i-1]){
				goto bad;
			}
		}
	}
	cout<<"YES\n";
	return 0;
	bad:
	cout<<"NO\n";
}