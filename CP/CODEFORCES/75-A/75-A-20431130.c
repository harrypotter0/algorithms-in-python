#include"stdio.h"
int s(int n){
	int t=0,pw=1;
	while(n){
		t+=(n%10)*pw;
		if(n%10)pw*=10;
		n/=10;
	} return t;
}
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	puts(s(a+b)==s(a)+s(b)? "YES" : "NO");
	return 0;
}