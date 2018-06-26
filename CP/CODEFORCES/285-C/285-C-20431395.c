#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void *a,const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int n,i;
	long long int t=0;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	qsort(a,n,sizeof(int),cmpfunc);
	for(i=0;i<n;i++)
		t += abs(i +1 - a[i]);
	printf("%I64d\n",t);
	return 0;
}