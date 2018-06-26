#include<stdio.h>
int A[100],n,a,t=2,x;
int main(){
	scanf("%d",&n);
	while(t--){
		scanf(" %d",&a);
		while(a--){
			scanf(" %d",&x);
			A[x-1]++;
		}}
	for(a=0;a<n;a++)
		if(!A[a])
		{printf("Oh, my keyboard!"); return 0;}

	printf("I become the guy.");
	return 0;
}