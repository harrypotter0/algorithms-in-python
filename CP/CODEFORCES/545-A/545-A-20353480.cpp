#include<stdio.h>
main(){
	int x,i,j,a,h[105]={0},top=0,f=1;
	scanf("%d",&x);
	for(i=0;i<x;i++){
		for(j=0;j<x;j++){
			scanf("%d",&a);
			if(a==1||a==3)
				f=0;
		}
		if(f){
			top++;
			h[i]++;
		}
		f=1;
	}
	printf("%d\n",top);
	for(i=0;i<x;i++)
		if(h[i])
			printf("%d ",i+1);
}