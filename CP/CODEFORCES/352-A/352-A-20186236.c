#include<stdio.h>

int main(void){
  int n,five,zero,i,num;
  scanf("%d",&n);
  five=zero=0;
  for(i=0;i<n;i++){
    scanf("%d",&num);
    if(!num) zero++;
    else five++;
  }
  five/=9;
  // printf("%d\n",(five*5)%9);
  if(!zero) printf("-1");
  else if(!five) printf("0");
  else{
    for(i=0;i<five*9;i++) putchar('5');
    for(i=0;i<zero;i++) putchar('0');
  }
  putchar('\n');
  return 0;
}