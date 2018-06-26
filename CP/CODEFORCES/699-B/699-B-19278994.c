#include <stdio.h>

char field[1000][1001];
int cnt_i[1000], cnt_j[1000];

int main(void) {
	int i, j;
	int n, m;
	int sum;

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%s", field[i]);

	sum = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (field[i][j] == '*') {
				sum++;
				cnt_i[i]++;
				cnt_j[j]++;
			}

	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (cnt_i[i] + cnt_j[j] - (field[i][j] == '*') == sum) {
				printf("YES\n%d %d\n", i + 1, j + 1);
				return 0;
			}

	puts("NO");

	return 0;
}