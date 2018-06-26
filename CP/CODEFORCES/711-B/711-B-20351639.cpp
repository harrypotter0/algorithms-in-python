#include <stdio.h>

int main() {
	int i, j, n, i0, j0, zero, good;
	long long sum, sum0, sum2, tmp;
	static long long a[500][500];

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			scanf("%lld", &a[i][j]);
		tmp = 0;
		zero = 0;
		for (j = 0; j < n; j++) {
			tmp += a[i][j];
			if (a[i][j] == 0) {
				i0 = i, j0 = j;
				zero = 1;
			}
		}
		if (zero)
			sum0 = tmp;
		else
			sum = tmp;
	}
	good = 1;
	a[i0][j0] = sum - sum0;
	for (i = 0; i < n; i++) {
		sum2 = 0;
		for (j = 0; j < n; j++)
			sum2 += a[i][j];
		if (sum2 != sum) {
			good = 0;
			break;
		}
	}
	for (j = 0; j < n; j++) {
		sum2 = 0;
		for (i = 0; i < n; i++)
			sum2 += a[i][j];
		if (sum2 != sum) {
			good = 0;
			break;
		}
	}
	sum2 = 0;
	for (i = 0; i < n; i++)
		sum2 += a[i][i];
	if (sum2 != sum)
		good = 0;
	sum2 = 0;
	for (i = 0; i < n; i++)
		sum2 += a[i][n - i - 1];
	if (sum2 != sum)
		good = 0;
	printf("%lld\n", !good || a[i0][j0] <= 0 || a[i0][j0] > 1e18
			? -1 : a[i0][j0]);
	return 0;
}