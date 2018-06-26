#include<stdio.h>
main(){
	int x,i,y,z,f=0;;
	scanf("%d",&x);
	for(i=0;i<x;i++){
		scanf("%d %d",&y,&z);
		if(y!=z)
			f++;
	}
	printf((f)?"Happy Alex":"Poor Alex");
}