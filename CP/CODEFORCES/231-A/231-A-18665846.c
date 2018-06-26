#include<stdio.h>
int main(){
	int n,x=0,a,b,c;
	scanf("%d",&n);
	while(n--){
		scanf("%d%d%d",&a,&b,&c);
		if((a+b+c)>1) x++;
	}
	printf("%d",x);
}