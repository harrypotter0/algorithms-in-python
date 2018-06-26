#include <stdio.h>

int d[2][101];

int main() {
	int c,i,a,n;
	scanf("%d\n",&n);
	c=0;
	while (n--)
		for (i=0;i<2;i++) {
			scanf("%d\n",&a);
			c+=d[!i][a];
			d[i][a]++;
		}
	printf("%d\n",c);
}