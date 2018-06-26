#include<stdio.h>
typedef unsigned u;
char S[111];
int main()
{
	u m,s,i,j,k;
	scanf("%u%u",&m,&s);
	if(s==0)
	{
		if(m==1)printf("0 0\n");
		else printf("-1 -1\n");
		return 0;
	}
	if(s>m*9){printf("-1 -1\n");return 0;}
	for(S[i=m]='\0',j=s-1;i--;)
	{
		k=j>9?9:j;
		j-=k;S[i]=k|'0';
	}
	++S[0];printf("%s ",S);
	for(j=s,i=m;i--;)
	{
		k=j>9?9:j;
		j-=k;putchar(k|'0');
	}
	putchar('\n');
	return 0;
}