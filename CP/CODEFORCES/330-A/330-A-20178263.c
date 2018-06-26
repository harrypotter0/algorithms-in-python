#include<stdio.h>
int main(){
int r,c,i,j,sum=0;
char d;
scanf("%d %d",&r,&c);
d=getchar();
int a[r],b[c];
for(i=0;i<r;i++){
for(j=0;j<c;j++){
if((d=getchar())=='S')
{a[i]=1;b[j]=1;}}
d=getchar();}
for(i=0;i<r;i++){
for(j=0;j<c;j++){
if(a[i]==1&&b[j]==1)
continue;
sum++;}
}
printf("%d\n",sum);
return(0);
}