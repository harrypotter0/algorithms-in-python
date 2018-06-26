#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#define LL long long
using namespace std;
const int M=3e5+7;
int read(){
    int ans=0,f=1,c=getchar();
    while(c<'0'||c>'9'){if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9'){ans=ans*10+(c-'0'); c=getchar();}
    return ans*f;
}
int n,m,v,top;
LL ans;
struct note{int d,T,w;}e[M];
bool cmp(note a,note b){return a.d>b.d;}
struct node{
    int w,pos;
    bool operator <(const node&x)const {return w<x.w;}
};
priority_queue<node>q;
int main()
{
    v=read();
    while(v--){
        q=priority_queue<node>();
        n=read(); m=read();
        top=n; ans=0;
        for(int i=1;i<=n;i++) e[i].d=read(),e[i].T=read(),e[i].w=read(),ans=ans+(LL)e[i].T*e[i].w;
        sort(e+1,e+1+n,cmp);
        for(int i=1;i<=m;i++){
                cout<<"------------i = "<<i<<"--------------------\n";
            while(top&&i>=e[top].d){
                     cout<<"Pushing in queue = "<<e[top].w<<" , "<<top<<" \n";
             q.push((node){e[top].w,top});
             top--;}
            node x=q.top();

            while(!e[x.pos].T){
                     cout<<"Emptying in queue = "<<e[x.pos].T<<" \n";
                q.pop();
                if(q.empty()) break;
                x=q.top();
            }
            if(q.empty()) {
                    cout<<"ANS NOT UPDATED - ---------------------------\n";
            continue;
            }
            ans=ans-x.w;
             cout<<" UPDATED ------------"<<ans<<"----------------\n";
            e[x.pos].T--;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
