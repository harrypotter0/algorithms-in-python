#include<stdio.h>
int n,x,a,b,c,w;
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d",&x);
		if(x==25)      a++;
		else if(x==50) if(a) {b++; a--;} else w++;
   		else           if(b && a) {c++; a--; b--;} else if(a > 2) { c++; a -= 3;} else w++;
	}
	printf(w ? "NO" : "YES");
	return 0;
}