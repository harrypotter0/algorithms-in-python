#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node
{
    int l,r,ind;
};
const int block=500;
int a[200011];
ll c[1000111]={0LL},answer,ans[200011];
node q[200011];
bool cmp(node a,node b)
{
    if(a.l/block!=b.l/block)
        return a.l/block<b.l/block;
    return a.r<b.r;
}
void add(int i)
{
    answer=answer+(2LL*a[i]*c[a[i]])+(ll)a[i];
    c[a[i]]++;
}
void remove(int i)
{
    answer=answer-(2LL*a[i]*c[a[i]])+(ll)a[i];
    c[a[i]]--;
}
int main()
{
    int n,m,i,j;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&q[i].l,&q[i].r);
        q[i].l--;
        q[i].r--;
        q[i].ind=i;
    }
    sort(q,q+m,cmp);
    answer=0;
    for(i=q[0].l;i<=q[0].r;i++)
        add(i);
    int cl=q[0].l,cr=q[0].r;
    ans[q[0].ind]=answer;
    for(i=1;i<m;i++)
    {
        while(cl<q[i].l)remove(cl),cl++;
        while(cl>q[i].l)add(cl-1),cl--;
        while(cr>q[i].r)remove(cr),cr--;
        while(cr<q[i].r)add(cr+1),cr++;
        ans[q[i].ind]=answer;
    }
    for(i=0;i<m;i++)
        printf("%lld\n",ans[i]);
    return 0;
}
