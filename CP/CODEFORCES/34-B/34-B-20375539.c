#include<stdio.h>
int cmp(const void * a, const void * b)
{  return ( *(int*)a - *(int*)b ); }
int main(){
	int t=0,m,n,i,arr[105];
	scanf("%d%d",&m,&n);
	for(i=0;i<m;i++)scanf("%d",&arr[i]);
	qsort(arr,m,sizeof(int),cmp);
	for(i=0;n--;i++)if(arr[i]<0)t+=arr[i];
	printf("%d",-t);
	return 0;
}