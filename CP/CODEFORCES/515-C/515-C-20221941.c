#include<stdio.h>
char A[10],B[15],x; int n;
int main(){
	scanf("%d %s",&n,B);
	while(n--)  A[B[n] - '0']++;

	for(n = 0; n < A[7] + A[8] + A[9]; n++)
		printf("7");

	for(n = 0; n < A[5] + A[6]; n++)
		printf("5");

	for(n = 0; n < A[3] + A[4] + A[6] + 2 * A[9]; n++)
		printf("3");

	for(n = 0; n < A[9] + 3 * A[8] + 2 * A[4] + A[2]; n++)
		printf("2");
	
	return 0;
}