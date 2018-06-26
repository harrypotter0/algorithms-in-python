#include<bits/stdc++.h>
using namespace std;
typedef long long lnt;
int a[110],b[110];
int x[110],y[110],ok[110];
int main(){
    int n;
    scanf("%d",&n);
    for(int k=1;k<=n;k++) scanf("%d%d",&a[k],&b[k]);
    for(int k=1;k<=n;k++){
        if(k<=n/2) x[k]=a[k]-b[k];
        else y[k-n/2]=b[k];
    }
    sort(x+1,x+n/2+1);
    sort(y+1,y+n/2+1);
    int ans=0;
    for(int k=n/2;k>=1;k--){
        for(int i=n/2;i>=1;i--){
            if(ok[i]) continue;
            if(y[k]<=x[i]){
                ans++;
                ok[i]=1;
                break;
            }
        }
    }
    printf("%d\n",ans);
}
