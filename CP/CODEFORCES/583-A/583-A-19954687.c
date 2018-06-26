#include<stdio.h>
main(){
	int x,i,j,a,b,arr[52]={0},art[52]={0};
	scanf("%d",&x);
	for(i=0;i<x*x;i++){
		scanf("%d %d",&a,&b);
		if(!arr[a] && !art[b]){
			printf("%d ",i+1);
			arr[a]++;
			art[b]++;
		}
	}
}