#include<stdio.h>
int A[111],B[111];
int main()
{
	int q,n;
	for(scanf("%d",&q);q--;++A[n])scanf("%d",&n);
	for(scanf("%d",&q);q--;++B[n])scanf("%d",&n);
	for(q=0,n=1;n<=100;++n)
	{
		while(A[n]&&B[n-1])++q,--A[n],--B[n-1];
		while(A[n]&&B[n])++q,--A[n],--B[n];
		while(A[n]&&B[n+1])++q,--A[n],--B[n+1];
	}
	printf("%d\n",q);
	return 0;
}