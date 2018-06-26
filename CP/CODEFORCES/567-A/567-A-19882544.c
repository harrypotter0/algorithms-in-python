#include <stdio.h>
#define min(x,y) x>y?y:x
#define max(x,y) x>y?x:y
long long int i,n,y[100005];
   main(){
	scanf("%I64d",&n);
	for(i=0;i<n;i++)
		scanf("%I64d",&y[i]);
	printf("%I64d %I64d\n",y[1]-y[0],y[n-1]-y[0]);
	for(i=1;i<n-1;i++)
			printf("%I64d %I64d\n",min(y[i]-y[i-1],y[i+1]-y[i]),max(y[i]-y[0],y[n-1]-y[i]));
	printf("%I64d %I64d\n",y[n-1]-y[n-2],y[n-1]-y[0]);
}