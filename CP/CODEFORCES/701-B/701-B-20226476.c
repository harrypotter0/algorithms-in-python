#include<stdio.h>
int x[100010];
int y[100010];
int main(){
    int i,j,l,h;
    long long int n,m;
    scanf("%I64d %I64d",&n,&m);
    h=n;
    for(l=0;l<m;l++){
        scanf("%d %d",&i,&j);
        n-=!x[i];
        h-=!y[j];
        x[i]=1;
        y[j]=1;
        printf("%I64d ",n*h);
    }
    return 0;
}