#include<cstdio>
int n,x,y,s,X,f;
int main()
{
	scanf("%d",&n);
	for(;n--;)
		scanf("%d%d",&x,&y),
		s^=x^y,X^=x,
		f|=(x&1)!=(y&1);
	if((s&1)||(X&1)&&!f)
		printf("-1\n");
	else
		printf("%d\n",X&1);
}