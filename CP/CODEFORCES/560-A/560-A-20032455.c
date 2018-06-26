#include<stdio.h>
main(){
	int x,y,i;
	scanf("%d",&x);
	for(i=0;i<x;i++){
		scanf("%d",&y);
		if(y==1){
			printf("-1");
			return 0;
		}
	}
	printf("1");
}