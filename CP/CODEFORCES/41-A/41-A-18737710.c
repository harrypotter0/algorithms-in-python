#include<stdio.h>
#include<string.h>
int main()
{
 char a[500],b[500];
 gets(a);
 gets(b);
 strrev(b);
 if(strcmp(a,b))
 {
  printf("NO");
 }
 else
 {
  printf("YES");
 }
 return 0;
}