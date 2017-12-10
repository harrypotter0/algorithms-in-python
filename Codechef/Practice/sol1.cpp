/*
     Contest  :
     Task    :
     https://www.codechef.com/problems/WEICOM
*/

#include <bits/stdc++.h>
using namespace std;

//typedef map<int,int>  mii;
typedef pair<int,int> pii;

#define pb  push_back
#define mp  make_pair
#define F   first
#define S   second
#define itr ::iterator it

const int MAX=1e3+99;

long long N,org,K,tot,dup,mn[MAX],sc[MAX],mark[MAX][MAX];

void fill(int N)
{
  int J;
  if(N%2==0)
  N++;
  for(int A=1;A<=N;A++)
  for(int B=1;B<=N;B++)
  mark[A][B]=0;
  for(int A=1;A<=N;A++)
  for(int B=0;B<(N-1)/2;B++)
  {
      if(A+B+((N+1)/2)>N)
      J=(A+B+((N+1)/2))%N;
      else
      J=(A+B+((N+1)/2));
      mark[A][J]=1;
      mark[J][A]=0;
  }

  return ;
}

void erase(int N)
{
  mark[N][N]=0;
  for(int A=1;A<N;A++)
  mark[N][A]=1,mark[A][N]=0;
  return ;
}

long long score(int N)
{
  long long res=0;
  for(int A=1;A<=N;A++)
  {
    sc[A]=0;
    for(int B=1;B<=N;B++)
    if(mark[A][B]==1)
    sc[A]++;
  }
  for(int A=1;A<=N;A++)
  res+=sc[A]*sc[A];
  return res;
}

long long sum(int X)
{
  long long res=0;
  for(int A=0;A<X;A++)
  {
    res+=A*A;
    if(res>K)
    break;
    }
  return res;
}

int main()
{
  ios_base::sync_with_stdio(false);
  /*cin.tie(0);
  cout.tie(0);*/
  for(long long A=1;A<=1001;A++)
  {
    if(A%2)
    mn[A]=(A/2)*(A/2)*(A);
    else
    mn[A]=(A/2)*(A/2)*(A/2)+((A-1)/2)*((A-1)/2)*(A/2);
  }
    int tc;
    cin>>tc;
    while(tc--)
    {
      tot=0;
      cin>>N>>K;
      if(K<mn[N]||K>sum(N))
      {
        cout<<"-1\n";
        continue;
    }
    dup=N;
    while(dup>1&&tot+((dup-1)*(dup-1))+mn[dup-1]<=K)
    {
      tot+=(dup-1)*(dup-1);
      sc[dup]=(dup-1);
      dup--;

    }
    fill(dup);
    tot+=mn[dup];
    for(int A=1;A<=dup;A++)
      {
        sc[A]=0;
      for(int B=1;B<=dup;B++)
          sc[A]+=mark[A][B];
    }
    while(tot<K)
    {
      int br=0;
      for(int A=1;A<=dup&&tot<K;A++)
      {
          for(int B=1;B<=dup&&tot<K;B++)
          {
            if(A==B)
            continue;
            if(sc[A]==sc[B])
            {
              if(mark[A][B]==0)
              {
                mark[A][B]=1;
                mark[B][A]=0;
                sc[A]++;
                sc[B]--;
              }
              else if(mark[A][B]==1)
              {
                mark[A][B]=0;
                mark[B][A]=1;
                sc[A]--;
                sc[B]++;
              }
              br=1;
              tot+=2;
            }
          }
      }
      if(!br)
      break;
    }
    for(int A=dup+1;A<=N;A++)
    {
      mark[A][A]=0;
      for(int B=A-1;B>=1;B--)
      mark[A][B]=1,mark[B][A]=0;
    }
    if(tot==K)
    for(int A=1;A<=N;A++)
    {
      for(int B=1;B<=N;B++)
      cout<<mark[A][B];
      cout<<"\n";
    }
    else
    cout<<"-1\n";
  }
  return 0;
}
