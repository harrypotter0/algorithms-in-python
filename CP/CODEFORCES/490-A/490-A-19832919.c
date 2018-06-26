#include<stdio.h>
#define min(a,b) ((a)<(b)) ? (a) : (b)
int s[5004][5004],a[4],t,n,x,i;
main(){
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		s[x][++a[x]]=i;		
	}
	t=min(min(a[1],a[2]),a[3]);
	printf("%d\n",t);
	for(i=1;i<=t;i++)
		printf("%d %d %d\n",s[1][i]+1,s[2][i]+1,s[3][i]+1);
	
}