// An efficient approach based implementation
// to find if a number can be written as sum
// of two squares.
#include <bits/stdc++.h>
using namespace std;

// function to check if there exist two
// numbers sum of whose squares is n.
bool sumSquare(int n)
{
	unordered_map<int, int> s;
	for (int i = 0; i * i <= n; ++i) {

		// store square value in hashmap
		s[i * i] = 1;
		if (s.find(n - i * i) != s.end()) {
			// cout << sqrt(n - i * i) << "^2 + "
			// 	<< i << "^2" << endl;
			return true;
		}
	}
	return false;
}

// driver Program
int main()
{
	int n;
	cin>>n;

	if (sumSquare(n))
		cout << "YES";
	else
		cout << "NO";
}
