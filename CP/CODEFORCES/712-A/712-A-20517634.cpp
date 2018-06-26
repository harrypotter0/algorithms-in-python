#include <bits/stdc++.h>
using namespace std;
int main(){
int n,i;long long a,b,c=0;
 cin>>n;
 cin>>a;
 for(i=0;i<n-1;i++){
 	cin>>b;
 	c=a+b;
 	cout << c<<'\t';
 	a=b;
    }
    cout << b<<'\t';
	return 0;
}