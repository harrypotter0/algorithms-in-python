#include<stdio.h>
main(){
	int x,i,s=1;
	char arr[200005];
	scanf("%d %s",&x,arr);
	for(i=1;i<x;i++){
		(arr[i]==arr[0])?s++:s--;
	}
	printf("%d",(s<0)?s*-1:s);
}