#include <stdio.h>
int main()
{
int s,i,s1,s2,s3,count=0;
scanf("%d",&s);
for(i=1;i<=s;i++){
scanf("%d%d%d",&s1,&s2,&s3);
if(s1==1&&s2==1||s2==1&&s3==1||s1==1&&s3==1)
count++;


}

printf("%d",count);




return 0;
}