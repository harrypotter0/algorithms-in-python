#include <bits/stdc++.h>
using namespace std;
int n, x, u[10000];
int main(){
	cin >> n;
	for(int i=1; i<=n; i++) {
		int mx = -1;
		for(int j=1; j<=n; j++) {
			cin >> x;
			mx = max(mx,x);
		}
		cout << mx + u[mx] << " ";
		u[mx] = 1;
	}
	
}