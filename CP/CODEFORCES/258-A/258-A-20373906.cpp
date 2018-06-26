#include<stdio.h>

char s[100500];

int main(){
	gets(s);
	int n=0;
	while(s[n]=='1')
		n++;
	if(!s[n])
		n--;
	s[n]=0;
	printf("%s%s",s,s+n+1);
}