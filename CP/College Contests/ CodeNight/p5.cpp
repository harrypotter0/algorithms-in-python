#include<bits/stdc++.h>
using namespace std;
typedef long long lnt;
int a[100],b[100];
int n,maxi;
int ans[100],tmp[100];
void dfs(int x,int sum){
    if(x==n){
        // for(int k=1;k<=n;k++){
        //         if(tmp[k]==1)
        //         // cout<<b[k]<<" ";
        //         else
        //         // cout<<a[k]<<" ";
        //     }
        if(sum>maxi){
            maxi=sum;
            for(int k=1;k<=n;k++){
                ans[k]=tmp[k];
                // if(ans[k]==1)
                // cout<<b[k]<<" ";
                // else
                // cout<<a[k]<<" ";
            }
        }
        printf("%d\n",sum);
        return;
    }
    x++;
    tmp[x]=0;
    dfs(x,sum+a[x]);
    tmp[x]=1;
    dfs(x,sum+b[x]);
}
int main(){
    scanf("%d",&n);
    for(int k=1;k<=n;k++) scanf("%d",&a[k]);
    for(int k=1;k<=n;k++) scanf("%d",&b[k]);
    maxi=-1e9;
    dfs(0,0);
    printf("%d ",maxi);
    printf("[");
    for(int k=1;k<=n;k++){
        if(ans[k]==0) printf("'No Turn'");
        else printf("'Turn'");
        if(k!=n) printf(", ");
        else puts("]");
    }
} 
