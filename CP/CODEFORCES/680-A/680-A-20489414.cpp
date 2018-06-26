#include <bits/stdc++.h>
using namespace std;
int a[101],t,s,m,i;
int main(){
	while(i<5){
		cin >> t;
		s+=t, i++, a[t]++;
		if(a[t]>1)  m=max(m,t*min(3,a[t])); }
	cout << s-m; 
	}