#include<stdio.h>
int A[100],n,i,a,b,t,w;
int main(){
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
		t += A[i];
	}
	scanf("%d %d",&a,&b); if(a > b) { i = a; a = b; b = i; }
	for(i=a-1;i<b-1;i++)
		w += A[i];

	printf("%d",w < t - w ? w : t - w);
	return 0;
}