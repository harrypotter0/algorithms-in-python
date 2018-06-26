#include <stdio.h>
int main() {
	int a,b,c,x,n,z,y,ilk,son;
	scanf("%d %d %d %d %d %d %d",&c,&b,&a,&z,&y,&x,&n);
	ilk=a+b+c;
	son=x+y+z;
	printf((n>=((ilk)/5+((ilk)%5!=0))+((son)/10+((son)%10!=0)))?"YES":"NO");}