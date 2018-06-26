#include <stdio.h>

int main()
{
	int i, j, n;
	char s[500][500];

	scanf("%d\n", &n);
	for (i = 0; i < n; ++i)
		gets(s[i]);

	if (s[0][0] == s[0][1]) {
		puts("NO");
		return 0;
	}

	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			if (j == i || j == n - 1 - i) {
				if (s[i][j] != s[0][0]) {
					puts("NO");
					return 0;
				}
			} else {
				if (s[i][j] != s[0][1]) {
					puts("NO");
					return 0;
				}
			}
		}
	}

	puts("YES");
	return 0;
}