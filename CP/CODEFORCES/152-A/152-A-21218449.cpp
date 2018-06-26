#include<cstdio>
int i,j,n,m,k,a,t;char s[128][128];
int main(){
	scanf("%d%d ",&n,&m);
	for(;i<n;++i)gets(s[i]);
	for(i=0;i<n;++i)
	for(j=0;j<m;++j){
		t=1;
		for(k=0;k<n;++k)
			if(s[i][j]<s[k][j])t=0;
		if(t){++a;break;}
	}
	printf("%d\n",a);
	return 0;
}