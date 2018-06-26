#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int sz=1<<18+1;

int pr[sz][23];
int ob[sz],h[sz];
int bit,cur,n,x,y,res,root;
int d[30][30];
int a[sz];
int k;
int rez[1<<27];
int rez1[1<<27];
int st[1<<27];
vector <int> v[sz];


  int read_int(){
  char r;
  bool start=false,neg=false;
  long long int ret=0;
  while(true){
    r=getchar();
    if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
      continue;
    }
    if((r-'0'<0 || r-'0'>9) && r!='-' && start){
      break;
    }
    if(start)ret*=10;
    start=true;
    if(r=='-')neg=true;
    else ret+=r-'0';
  }
  if(!neg)
    return ret;
  else
    return -ret;
}


void dfs(int x, int pred)
{
    ob[x]=1;
    h[x]=h[pred]+1;
    pr[x][1]=pred;

    for (int i=0;i<v[x].size();i++)
    if (ob[v[x][i]]==0)
       dfs(v[x][i],x);
}

void fill_sparse()
{
    for (int i=1;i<=n;i++)
        pr[i][0]=i;

    for (int j=2;j<=21;j++)
        for (int i=1;i<=n;i++)
          pr[i][j]=pr[pr[i][j-1]][j-1];

    return;
}

int fajnd(int x, int y)
{
    cur=pr[x][0];
    bit=1;
    while (y>0)
    {
        if (y%2==1)
            cur=pr[cur][bit];
            y=y/2;
            bit++;
    }
    return cur;
}

int lca(int x,int y)
{
 int  l=-1;
 int  r=sz;

    while (l<r-1)
    {
        int tr=(l+r)/2;
        int u=fajnd(x,tr);
        if (h[y]>=h[u])
        {
          if (fajnd(y,h[y]-h[u])!=u) l=tr; else r=tr;
        } else l=tr;
    }
  return fajnd(x,r);
}
int main()
{
    scanf("%d",&n);
    root=1;
    for (int i=0;i<28;i++)
        st[1<<i]=i;
    for (int i=0;i<n-1;i++)
    {
        x=read_int();
        y=read_int();
        v[x].push_back(y);
        v[y].push_back(x);
    }

    dfs(root,0);
    fill_sparse();

    cin>>k;

    for (int i=0;i<k;i++)
        scanf("%d",&a[i]);

    for (int i=0;i<k;i++)
        for (int j=i+1;j<k;j++)
        if (h[i]<h[j])
         swap(a[i],a[j]);

        for (int i=0;i<k;i++)
          for (int j=0;j<k;j++)
            {
               int x= lca(a[i],a[j]);
               d[i][j]=h[a[i]]-h[x];
            }

   int ans=0;
   rez[0]=n-1;
   ans=rez[0];

  st[0]=-1;
    for (int i=1;i<1<<k;i++)
    {

        int poz=st[i&(-i)];

        int val=i xor (1<<poz);

        int poz1=st[val&(-val)];

        if (poz1==-1) rez1[i]=h[a[poz]]-1; else {

        int val2= i-(1<<poz1);

        rez1[i]=min(rez1[val2],d[poz][poz1]);
        }

        rez[i]=rez[val]-rez1[i];
        ans^=rez[i];
    }

    printf("%d\n",ans);
return 0;
}
