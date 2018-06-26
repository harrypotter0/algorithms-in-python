#include<stdio.h>
	int i,alf[30],t;
	char n;
main(){
	while(n!='}'){scanf("%c",&n);if(n!=' '&& n!=',')alf[n]++;}
	for(i='a';i<='z';i++) if(alf[i])t++;
	printf("%d",t);
}