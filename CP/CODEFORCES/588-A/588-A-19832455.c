#include<stdio.h>
main(){
	int x,z,i,y,a,b,min=200,top=0,j;
	scanf("%d",&x);
	for(i=0;i<x;i++){
		scanf("%d %d",&a,&b);
		if(b<min)
			min=b;
		top+=min*a;
	}
	printf("%d",top);
}