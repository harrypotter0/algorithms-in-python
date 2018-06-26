#include<stdio.h>
int main()
{
	long long int k,w[26],i,d=0,max=-1,j=0;
	char s[1001],*p;
	scanf("%s %lld",s,&k);
	for(i=0;i<26;i++)
	{
		scanf("%lld",&w[i]);
		if(w[i]>max)
			max=w[i];
	}
	p=s;
	while(*p!='\0')
	{
		j++;
		d=d+j*w[(long long int)(*p)-97];
		p++;
	}
	printf("%lld\n",d+(2*j+k+1)*k*max/2);
	return 0;
}