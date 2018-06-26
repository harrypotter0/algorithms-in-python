#include <stdio.h>
int main(){
	int n,m,arr[105]={0},f=1,p,r,s;
	scanf("%d %d",&n,&m);
	while(n--){
		scanf("%d",&p);
		while(p--){
			scanf("%d",&s);
			arr[s]++;
		}
	}
	while(m--)
		if(!(arr[m+1]))
			f=0;
	(f) ? printf("YES") : printf("NO");
}