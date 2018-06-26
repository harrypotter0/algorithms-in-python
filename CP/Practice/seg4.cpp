#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

#define LL long long
#define mod 1000000007
#define MAX 263000
#define inchar getchar_unlocked

inline LL inPos()
{
  LL n = 0;
  register LL ch = inchar();
  while (ch < '0' || ch > '9') ch = inchar();
  while (ch >= '0' && ch <= '9')
  {
    n = (n << 3) + (n << 1) + (ch - '0');
    ch = inchar();
  }
  return n;
}

LL A[MAX];

LL lazy_add[MAX];

LL lazy_multiply[MAX];

typedef struct
{
    LL l, r, ans;
}node;

node segment_tree[MAX];

LL  build(LL t,LL i,LL j)
{
    segment_tree[t].l = i;
    segment_tree[t].r = j;
    LL left = t<<1;
    LL right = left|1;
    LL mid = (i + j)>>1;
    if(i==j)
        segment_tree[t].ans = A[i]%mod;
    else
        segment_tree[t].ans = (build(left+1, i, mid) + build(right+1, mid+1, j)) % mod;
    return segment_tree[t].ans % mod;
}

void propagate(LL t)
{
    LL a = segment_tree[t].l;
    LL b = segment_tree[t].r;
    if(lazy_add[t] != 0 || lazy_multiply[t] != -1)
    {
        if(lazy_multiply[t]!=-1)
        segment_tree[t].ans = ((segment_tree[t].ans * lazy_multiply[t]) % mod + ((b - a + 1) * lazy_add[t] + mod) % mod) % mod;
        else
            segment_tree[t].ans = (segment_tree[t].ans + ((b - a + 1) * lazy_add[t]) % mod) % mod;
    if(a != b)
    {
            LL left = t<<1;
            LL right = left|1;
            if(lazy_multiply[t]!=-1)
            {
                if(lazy_multiply[left+1] == -1)
                    lazy_multiply[left+1] = 1;
                lazy_multiply[left+1] = (lazy_multiply[left+1] * lazy_multiply[t]) % mod;
                if(lazy_multiply[right+1] == -1)
                    lazy_multiply[right+1] = 1;
                lazy_multiply[right+1] = (lazy_multiply[right+1] * lazy_multiply[t]) % mod;
                lazy_add[left+1] = ((lazy_add[left+1] * lazy_multiply[t]) % mod + lazy_add[t]) % mod;
                lazy_add[right+1] = ((lazy_add[right+1] * lazy_multiply[t]) % mod + lazy_add[t]) % mod;
            }
            else
            {
                lazy_add[left+1] = (lazy_add[left+1] + lazy_add[t]) % mod;
                lazy_add[right+1] = (lazy_add[right+1] + lazy_add[t]) % mod;
            }
    }
    lazy_add[t] = 0;
        lazy_multiply[t] = -1;
  }
}

void update1(LL t, LL ul, LL ur, LL v)
{
    LL a = segment_tree[t].l;
    LL b = segment_tree[t].r;
    propagate(t);
    if(a>ur || b<ul)
        return ;
    LL left = t<<1;
    LL right = left|1;
    if(a>=ul && b<=ur)
    {
        segment_tree[t].ans = (segment_tree[t].ans + ((b - a + 1) * v) % mod) % mod;
        if(a!=b)
        {
            lazy_add[left+1] = (lazy_add[left+1] + v) % mod;
            lazy_add[right+1] = (lazy_add[right+1] + v) % mod;
        }
        return ;
    }
    update1(left+1, ul, ur, v);
    update1(right+1, ul, ur, v);
    segment_tree[t].ans = (segment_tree[left+1].ans + segment_tree[right+1].ans) % mod;
}

void update2(LL t, LL ul, LL ur, LL v)
{
    LL a = segment_tree[t].l;
    LL b = segment_tree[t].r;
    propagate(t);
    if(a>ur || b<ul)
        return;
    LL left = t<<1;
    LL right = left|1;
    if(a>=ul && b<=ur)
    {
        segment_tree[t].ans = (segment_tree[t].ans * v) % mod;
        if(a!=b)
        {
            lazy_add[left+1] = (lazy_add[left+1] * v) % mod;
            lazy_add[right+1] = (lazy_add[right+1] * v) % mod;
            if(lazy_multiply[left+1] == -1)
                lazy_multiply[left+1] = 1;
            lazy_multiply[left+1] = (lazy_multiply[left+1]* v + mod) % mod;
            if(lazy_multiply[right+1] == -1)
                lazy_multiply[right+1] = 1;
            lazy_multiply[right+1] = (lazy_multiply[right+1] * v) % mod;
        }
        return ;
    }
    update2(left+1, ul, ur, v);
    update2(right+1, ul, ur, v);
    segment_tree[t].ans = (segment_tree[left+1].ans + segment_tree[right+1].ans) % mod;
}

void update3(LL t, LL ul, LL ur, LL v)
{
    LL a = segment_tree[t].l;
    LL b = segment_tree[t].r;
    propagate(t);
    if (a>ur || b<ul)
        return;
    LL left = t<<1;
    LL right = left|1;
    if (a>=ul && b<=ur)
    {
        segment_tree[t].ans = ((b-a+1) * v) % mod;
        if(a!=b)
        {
            lazy_multiply[left+1] = 0;
            lazy_multiply[right+1] = 0;
            lazy_add[left+1] = v;
            lazy_add[right+1] = v;
        }
        return ;
    }
    update3(left+1, ul, ur, v);
    update3(right+1, ul, ur, v);
    segment_tree[t].ans = (segment_tree[left+1].ans + segment_tree[right+1].ans) % mod;
}

LL query(LL t, LL sl, LL sr)
{
    LL a = segment_tree[t].l;
    LL b = segment_tree[t].r;
    if(a>sr || b<sl)
        return 0;
    propagate(t);
    if (a>=sl && b<=sr)
        return segment_tree[t].ans;
    else
        return (query((t<<1)+1, sl, sr) % mod + query((t<<1)+2, sl, sr) % mod) % mod;
}

int main()
{
    int Q, type;
    LL N, V, X, Y;
    scanf("%lld %d\n", &N, &Q);
    for(int i=0; i<N; i++)
        A[i] = inPos();
    memset(lazy_add, 0, sizeof(lazy_add));
    memset(lazy_multiply, -1, sizeof(lazy_multiply));
    build(0, 0, N-1);
    while(Q--)
    {
        scanf("%d %lld %lld", &type, &X, &Y);
        if (type==1)
        {
            V = inPos();
            update1(0, X-1, Y-1, V);
        }
        else if (type==2)
        {
            V = inPos();
            update2(0, X-1, Y-1, V);
        }
        else if (type==3)
        {
            V = inPos();
            update3(0, X-1, Y-1, V);
        }
        else
        {
            printf("%lld", query(0, X-1, Y-1));
            putchar_unlocked('\n');
        }
    }
    return 0;
} 
