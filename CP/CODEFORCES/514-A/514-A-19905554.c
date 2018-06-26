#include<stdio.h>
#include<string.h>
int main()
{
	char arr[20];
	scanf("%s",arr);
	int i,u=strlen(arr);
	for (i=0; i<u; i++)
		if(arr[i]>='5' && !(arr[i]=='9' && i == 0))
			arr[i]='9'-arr[i]+'0';
	printf("%s",arr);
	return 0;
}