#include<bits/stdc++.h>
int main(){
	int n, k, i, test;
	scanf("%d%d", &n, &k);
	for(i=1; k>i; i++)
		k -=i;
	for(i=1; i<=k; i++)
		scanf("%d", &test);
	printf("%d\n", test);
	return 0;
}