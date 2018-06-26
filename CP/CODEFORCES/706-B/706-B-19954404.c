#include <stdio.h>

int main(void) {
	int n, b[1000001] = { 0 }, tmp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &tmp), b[tmp]++;
	for (int i = 1; i < 100001; i++) b[i] += b[i-1];
	scanf("%d", &n);
	while (n--) scanf("%d", &tmp), printf("%d\n", b[tmp <= 100000 ? tmp : 100000]);
	return 0;
}