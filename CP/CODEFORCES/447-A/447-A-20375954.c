#include<stdio.h>

int i,j,p,n,a,H[305];

int main(){
   
	scanf("%d %d",&p,&n);
	
	for(i = 1; i <= n; i++){
		scanf("%d",&a);
		if(H[a%p]){
			printf("%d",i);
			return 0;
		}
		H[a%p] = 1;
	}   

	puts("-1");

	return 0;
}