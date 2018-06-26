#include<cstdio>
#include<iostream>
int n,a;
main(){
	char c;
	while(std::cin>>c)++n,a^=1<<(c-'a');
	if(!a||n%2)puts("First");
	else puts("Second");
}