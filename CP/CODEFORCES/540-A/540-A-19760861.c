#include<stdio.h>
int mod(int n)
{
	if(n<0)
		return -n;
	return n;
}
int main()
{
	int n,i;
	char s1[1020];
	char s2[1020];
	scanf("%d",&n);
	scanf("%s",s1);
	scanf("%s",s2);
	int total=0;
	for(i=0;i<n;i++)
	{
		if(mod(s2[i]-s1[i])>5)
			total+=10-mod(s2[i]-s1[i]);
		else
			total+=mod(s2[i]-s1[i]);
	}
	printf("%d\n",total);
	return 0;
}