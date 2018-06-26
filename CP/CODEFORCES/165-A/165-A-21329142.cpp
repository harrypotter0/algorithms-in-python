#include<cstdio>
int n,a,b,c,d,i,j,k,x[256],y[256];
int main(){
	scanf("%d",&n);
	for(i=0;i<n;++i)scanf("%d%d",x+i,y+i);
	for(i=0;i<n;++i){
		for(j=a=b=c=d=0;j<n;++j){
			a|=x[i]==x[j]&&y[i]<y[j];
			b|=x[i]==x[j]&&y[i]>y[j];
			c|=y[i]==y[j]&&x[i]<x[j];
			d|=y[i]==y[j]&&x[i]>x[j];
		}
		if(a&b&c&d)++k;
	}
	printf("%d\n",k);
	return 0;
}