#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
	return (*(long long int*)a-*(long long int*)b);
}
int main()
{
	int a,i;
	long long int b,c[1000];
	float max=0;
	scanf("%d%I64d",&a,&b);
	for(i=0;i<a;i++)
	scanf("%I64d",&c[i]);
	qsort(c,a,sizeof(long long int),cmp);
	max=2*c[0];
	if(2*(b-c[a-1])>max)
	max=(b-c[a-1])*2;
	for(i=0;i<a-1;i++)
	if(c[i+1]-c[i]>max)
	max=c[i+1]-c[i];
	printf("%.10f",max/2);
	return 0;
}