#include <stdio.h>

int main () {
	long long sum=0;
	int n,min=1000000001;
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		int a;
		scanf("%d",&a);
		sum+=a;
		if(a%2 && a< min) min = a;
	}
	if(sum%2) sum-=min;
	printf("%I64d\n",sum);
}