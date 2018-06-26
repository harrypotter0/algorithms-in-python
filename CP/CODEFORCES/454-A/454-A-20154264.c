#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i,j,k,l;
	scanf("%d",&n);
	l=(n+1)/2-1;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			k=l-abs(l-i)-abs(l-j);
			if(k>=0)
				printf("D");
			else
				printf("*");
		}
		printf("\n");
	}
	return 0;
}