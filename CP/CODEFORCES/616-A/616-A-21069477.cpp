#include "bits/stdc++.h"
using namespace std;

int main(){
	string a, b;
	cin >> a >> b;
	string a2 = string(b.size(), '0') + a;
	string b2 = string(a.size(), '0') + b;
	cout << ">=<"[(a2 < b2) + (a2 <= b2)] << endl;
	return 0;
}