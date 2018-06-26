#include <stdio.h>

int main() {
	int n,m,a;
	scanf("%d %d\n",&n,&m);
	if (m-1<n-m) a=m+1;
	else a=m-1;
	if (!a) a=m=1;
	if (a>n) a=m;
	printf("%i\n",a);
	return 0;
}