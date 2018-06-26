#include <stdio.h>

int q[10];

int main() {
	int i,n;
	scanf("%d\n",&n);
	int b=1;
	int m=0;
	while (n) {
		for (i=0;i<n%10;i++) q[i]+=b;
		if (n%10>m) m=n%10;
		b*=10;
		n/=10;
	}
	printf("%i\n",m);
	printf("%i",q[0]);
	for (i=1;i<m;i++) printf(" %i",q[i]);
	printf("\n");
}