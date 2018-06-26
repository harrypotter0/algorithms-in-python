#include<bits/stdc++.h>
using namespace std;
#define pb push_back
vector<int> g[200000];
int st[200000],en[200000];
int co[200005],co1[200005];

int block=448;

struct query{
    int l,r,id,fd;
}Q[200000];

int ind=0;
vector<int> ord;

void dfs(int v,int par){
    ord.pb(v);
    st[v]=ind++;
    for(int x:g[v]){
        if(x==par)continue;
        dfs(x,v);
    }
    en[v]=ind;
}

bool cmp(query x, query y)
{
    if (x.l/block != y.l/block)
        return x.l/block < y.l/block;
    return x.r < y.r;
}

int main(){
int n;
cin>>n;
int col[n],luc[n];
set<int> c;
for(int i=0;i<n;i++){scanf("%d",&col[i]);c.insert(col[i]);}
// for(auto iter=c.begin(); iter!=c.end();++iter){
//     cout<<*iter<<" ";
// }
// cout<<endl;
int val=0;
map<int,int> my;
for(auto it=c.begin();it!=c.end();it++)my[*it]=val++;
// for(auto elem : my)
// {
//    std::cout << elem.first << " " << elem.second << " " ;
// }
// cout<<endl;

for(int i=0;i<n;i++)col[i]=my[col[i]];
// for(int i=0;i<n;i++)cout<<col[i]<< " ";
// cout<<endl;
for(int i=0;i<n;i++)scanf("%d",&luc[i]);
for(int i=0;i<n-1;i++){
    int a,b;
    scanf("%d %d",&a,&b);
    a--;b--;
    g[a].pb(b);
    g[b].pb(a);
}
dfs(0,0);
for(int i=0;i<n;i++)cout<<st[i]<< " ";
cout<<endl;
for(auto iter=ord.begin(); iter!=ord.end();++iter){
    cout<<*iter<<" ";
}
cout<<endl;
for(int i=0;i<n;i++)cout<<en[i]<< " ";
cout<<endl;

for(int i=0;i<n;i++){
    Q[i].l=st[i];
    Q[i].r=en[i]-1;
    Q[i].id=i;
    Q[i].fd=luc[i];
}
for(int i=0;i<ind;i++)ord[i]=col[ord[i]];
sort(Q,Q+n,cmp);
//  for(int x:ord)cout<<x<<" ";cout<<endl;
int ans[n];
int currL = 0, currR = 0;
for (int i=0; i<n; i++)
{

    int L = Q[i].l, R = Q[i].r;

    while (currL < L)
    {
        //currSum -= a[currL];
        co1[co[ord[currL]]]--;
        co[ord[currL]]--;
        co1[co[ord[currL]]]++;
        currL++;
    }

    while (currL > L)
    {
       // currSum += a[currL-1];
        co1[co[ord[currL-1]]]--;
        co[ord[currL-1]]++;
        co1[co[ord[currL-1]]]++;
        currL--;
    }
    while (currR <= R)
    {
       // currSum += a[currR];
        co1[co[ord[currR]]]--;
        co[ord[currR]]++;
        co1[co[ord[currR]]]++;
        currR++;
    }

    while (currR > R+1)
    {
      //  currSum -= a[currR-1];
        co1[co[ord[currR-1]]]--;
        co[ord[currR-1]]--;
        co1[co[ord[currR-1]]]++;
        currR--;
    }
if(Q[i].fd>200000)ans[Q[i].id]=0;
    else ans[Q[i].id]=co1[Q[i].fd];
}
for(int i=0;i<n;i++)printf("%d ",ans[i]);
return 0;
}
