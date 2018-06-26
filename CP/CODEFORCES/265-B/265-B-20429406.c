#include <stdio.h>

int main(){
	long n,h,o=-1,t=0;
	scanf("%ld",&n);

	while(n--){
		scanf("%ld",&h);
		o+=abs(t-h)+2;
		t=h;
	}
	printf("%ld",o);
	return 0;
}