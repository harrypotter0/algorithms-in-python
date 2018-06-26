#include<bits/stdc++.h>
long int phi[100007],n;
long int a[400007];
void compute()
{
    memset(phi,0,sizeof(phi));
    long int i,p;
    long int n=100001;
    for (i=1; i<=n; i++)
       {
         phi[i] = i;
       }
    for (p=2; p<=n; p++)
    {
        if (phi[p] == p)
        {
           phi[p]=p-1;
           for (i = 2*p; i<=n; i += p)
            {
               phi[i] = (phi[i]/p) * (p-1);
            }
        }
    }
};
long int maxm(long int a,long int b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
};

void buildtree()
{
  long int i;
  for(i=n-1;i>0;i--)
  {
      a[i]=maxm(a[2*i],a[2*i+1]);
  }
};
void update(long int p)
{
    while(p>1)
    {
        p>>=1;
        a[p]=maxm(a[2*p],a[2*p+1]);
    }
};

long int query(long int l,long int r)
{
    long int m=0;
    for(;l<r;l>>=1,r>>=1)
    {
        if(l&1) m=maxm(m,a[l++]);
        if(r&1) m=maxm(m,a[--r]);
    }
    return m;
};
int main()
{
    compute();
    int t,type;
    scanf("%d",&t);
    long int q,i,l,r,k;
    while(t--)
    {
        memset(a,0,sizeof(a));
        scanf("%ld %ld",&n,&q);
        for(i=n;i<2*n;i++)
        {
            scanf("%ld",&k);
            a[i]=phi[k];
        }
        buildtree();
        for(i=0;i<q;i++)
        {
            scanf("%d %ld %ld",&type,&l,&r);
            if(type==0)
            {
              printf("%ld ",query(l+n-1,r+n));
            }
            if(type==1)
            {
                a[l+n-1]=phi[r];
                update(l+n-1);
            }
        }
        printf("\n");
    }
    return 0;
}
