#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, c=0;
	string b = "1", t;
	cin >> n;
	for(int i=0; i<n; ++i)  {
		cin >> t;
		if (t == "0") {b = t; break;}
		while(t[t.size()-1]  == '0') c++, t = t.substr(0, t.size()-1);
		if (b == "1") b = t;
	}
	cout << b;
	if (b != "0") while(c--) cout << 0;
	cout << endl;
	return 0;
}