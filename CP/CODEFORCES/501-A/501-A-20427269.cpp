#include<stdio.h>
typedef unsigned u;
int main()
{
	u a,b,c,d,A,B;
	scanf("%u%u%u%u",&a,&b,&c,&d);
	A=a-a/250*c;
	if(10*A<3*a)A=3*a/10;
	B=b-b/250*d;
	if(10*B<3*b)B=3*b/10;
	printf(A==B?"Tie\n":A<B?"Vasya\n":"Misha\n");
	return 0;
}