#include<cstdio>
#include<algorithm>
int a[4],b;
main(){
	for(int &x:a)scanf("%d",&x);
	std::sort(a,a+4);
	b=std::max(a[0]+a[1]-a[2],a[1]+a[2]-a[3]);
	puts(b>0?"TRIANGLE":b?"IMPOSSIBLE":"SEGMENT");
}