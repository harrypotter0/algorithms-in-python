#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, t;
	cin >> n >> t;
	int o = 0;
	int sum = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++)
	{
		while (sum <= t)
		{
			ans = max(ans, o - i);
			if (o == n) break;
			sum += a[o];
			o++;
		}
		sum -= a[i];
	}
	cout << ans << endl;
	return 0;
}