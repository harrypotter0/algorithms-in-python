#include<stdio.h>
int x,y,arr[10000],i,t;
main(){
	scanf("%d%d",&x,&y);
	for(i=1;i<=x;i++){
		if(y%i==0 && y/i<=x) t++; }
		printf("%d",t);
}