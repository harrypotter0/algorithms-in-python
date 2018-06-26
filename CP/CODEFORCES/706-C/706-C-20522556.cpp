#include <bits/stdc++.h>
using namespace std;
typedef pair<string, int> si;
typedef long long ll;

const int N = 212345;
si v[N];
ll c[N], dp[N];

int main(){
	int n;
	string s;
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> c[2 * i + 1];
		dp[i] = 1e18;
	}
	for(int i = 0; i < n; ++i){
		cin >> s;
		v[2 * i] = {s, 2 * i};
		reverse(s.begin(), s.end());
		v[2 * i + 1] = {s, 2 * i + 1};
	}
	sort(v, v + 2 * n);
	for(int i = 0; i < 2 * n; ++i){
		int id = v[i].second >> 1;
		dp[id] = min(dp[id], c[v[i].second] + (id ? dp[id - 1] : 0));
	}
	cout << (dp[n - 1] >= 1e18 ? -1 : dp[n - 1]);
}