#include<stdio.h>
int A[2000],n,k,i,j,x,t;
int main(){
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++){
		scanf("%d",&x);
	    for(j=i;j && x > A[j-1];j--)
			A[j] = A[j-1];
		A[j] = x;
    }
	for(i=0;i<n;i+=k)
		t += (A[i] - 1) * 2;

	printf("%d",t);
	return 0;
}