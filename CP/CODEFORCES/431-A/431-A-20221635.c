#include<stdio.h>
char A[100000]; int B[4],i,t;
int main(){
	scanf("%d %d %d %d %s",&B[0],&B[1],&B[2],&B[3],A);
	for(i=0;A[i];i++)
		t += B[A[i] - '1'];

	printf("%d",t);
	return 0;
}