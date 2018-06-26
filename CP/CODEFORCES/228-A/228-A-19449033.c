#include<stdio.h>
int main()
{
	int a,b,c,d,s=0;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(a==b || a==c || a==d) s++;
	if(b==c || b==d) s++;
	if(c==d) s++;
	printf("%d\n",s);
	return 0;
}