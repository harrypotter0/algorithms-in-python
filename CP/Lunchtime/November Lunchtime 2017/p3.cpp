#include <bits/stdc++.h>
using namespace std;
int foo(int pos, int size, int x, int y) {
	int where = 1LL * size * x / y;
	if (pos < where + 1) {
		return 2 * pos - 1;
	} else if (pos < size) {
		return 2 * pos + 1;
	} else if (pos < where + size) {
		return 2 * (pos - size + 1);
	}
	return 2 * (pos - size + 1) + 2;
}

int main() {
	int t;
	scanf("%d", &t);
	assert (1 <= t && t <= 1000);
// 	int em = 0;
	while (t --> 0) {
		int m, x, y;
		scanf("%d%d%d", &m, &x, &y);
// 		em += m;
		int a = 1, b = 2;
		for (int size = 2; size <= m / 2; ++size) {
			a = foo(a, size, x, y);
			b = foo(b, size, x, y);
		}
		printf("%d\n", a ^ b);
	}
	return 0;
}
