#include <stdio.h>
const int N=5050;
int n,m,w[N],c[N],d[N],a;
char g[N][N];
int main(){
  scanf("%d%d",&n,&m);
  for(int i=0;i<n;++i){
    scanf("%s",g[i]);
    for(int j = 0; j < m; ++j) {
        if(g[i][j] == 'C')
            g[i][j] = '1';
        else
            g[i][j] = '0';
    }
}
  for(int i=0;i<m;++i){
    for(int j=0;j<n;++j){
      --c[w[j]];
      ++c[w[j]='1'==g[j][i]?w[j]+1:0];
    }
    d[m+1]=0;
    for(int j=m+1;j-->0;)if((d[j]=d[j+1]+c[j])*j>a)a=d[j]*j;
  }
  printf("%d\n",a);
} 
