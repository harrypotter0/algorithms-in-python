#include<stdio.h>
#include<string.h>
int main ()
{
	char arr[2];
	gets(arr);
	if(arr[1]=='8' || arr[1]=='1' ||arr[0]=='h'|| arr[0]=='a')
	{
		if((arr[1]=='8' &&arr[0]=='a')||(arr[1]=='8' &&arr[0]=='h')||(arr[1]=='1' &&arr[0]=='a')||(arr[1]=='1' &&arr[0]=='h'))
	      	printf("3\n");
	      	else
	        printf("5\n");
	}
	else{
		printf("8\n");
	}
	return 0;
}