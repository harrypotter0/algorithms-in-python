#include <iostream>
#include <fstream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
//#include <windows.h>
//#include <unordered_map>
#include <set>
#include <stack>
#include <cstring>
#include <cmath>
#include <bitset>
 
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#define CTC(i) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
#define MN 1000010
#define EPS 0.0000001
#define INF 1000000000
#define PI 3.14159265359
#define E 2.718281828
#define pairr pair<ll, ll>
#define pairrr pair<ll, pairr>
#define pairrrr pair<pairr, pairr>
#define fr first
#define sc second
#define pb push_back
#define ll long long
#define dl double long
#define MOD 5000000
#define fll flush(cout)
#define IO ios_base::sync_with_stdio(false); cin.tie();
#define PQT int
#define PQL priority_queue<PQT, vector<PQT>, less<PQT> >
#define PQG priority_queue<PQT, vector<PQT>, greater<PQT> >
 
using namespace std;
 
int n,t;
int b[400020];
ll ans;
pairr T[4*400020],S,a[400020];
vector<pairr> ar;
 
void upd(int v, int tl, int tr, int l)
{
    if (l<tl || tr<=l) return;
    if (tl==tr-1)
    {
        T[v].fr=ar[tl-1].fr;
        T[v].sc=1;
        return;
    }
    upd(v+v,tl,tl+tr>>1,l);
    upd(v+v+1,tl+tr>>1,tr,l);
    T[v].fr=T[v+v].fr+T[v+v+1].fr;
    T[v].sc=T[v+v].sc+T[v+v+1].sc;
}
 
void upd1(int v, int tl, int tr, int l)
{
    if (l<tl || tr<=l) return;
    if (tl==tr-1)
    {
        T[v].fr=0;
        T[v].sc=0;
        return;
    }
    upd1(v+v,tl,tl+tr>>1,l);
    upd1(v+v+1,tl+tr>>1,tr,l);
    T[v].fr=0;
    T[v].sc=0;
}
 
void get(int v, int tl, int tr, ll val)
{
  if(S.fr+T[v].fr<=(S.sc+T[v].sc)*val)
  {
    S.fr+=T[v].fr;
    S.sc+=T[v].sc;
    return;
  }
  if(tl==tr-1)
    return;
  if(S.fr+T[v+v].fr<=(S.sc+T[v+v].sc)*val)
  {
    S.fr+=T[v+v].fr;
    S.sc+=T[v+v].sc;
    get(v+v+1, tl+tr>>1, tr, val);
    return;
  }
  get(v+v, tl, tl+tr>>1, val);
}
 
int main()
{
    scanf("%d",&t);
    while (t--)
    {
          scanf("%d", &n);
          for(int i=1; i<=n;++i)
            scanf("%lld %lld", &a[i].fr, &a[i].sc);
          sort(a+1, a+n+1);
          ar.clear();
          for(int i=1; i<=n;++i)
            ar.push_back(make_pair(a[i].sc, i));
          sort(ar.begin(), ar.end());
          for(int i=0; i<n;++i)
            b[ar[i].sc]=i+1;
          for(int i=n; i>=1;--i)
          {
            upd(1, 1, n+1, b[i]);
            S=make_pair(0ll, 0ll);
            get(1, 1, n+1, a[i].fr);
            ans=max(ans, S.sc);
          }
          cout<<ans<<endl;
          for(int i=n; i>=1;--i)
          {
            upd1(1, 1, n+1, b[i]);
          }
          ans=0;
    }
}