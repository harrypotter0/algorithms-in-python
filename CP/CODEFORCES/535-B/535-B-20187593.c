#include<stdio.h>


int indx(int n){
	if(n==0)
	return 0;
	else if(n%10==4)
	 return 2*indx(n/10)+1;
	else
	return 2*indx(n/10)+2;
}

int main(void){

	int n,q,r;
	scanf("%d",&n);
	n=indx(n);
	printf("%d",n);
	return 0;
}