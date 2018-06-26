#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
 int a[505];
  int b[7][7];
  string p[16]={
                "532614","546213","564312","632541","645231","654321","214365","215634","216543",
                "341265","351624","361542","432165","456123","465132"};

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

  int i,j,k,n,t,f=1,c;
    cin>>t;


  while(t--)
  {
   cin>>n;




 if(n==1)
 {
  cin>>a[0];
  cout<<"2 1 4 3 6 5\n";
 }
 else
 {
  cin>>a[0];
  f=0;


  for(i=1;i<n;i++)
    {cin>>a[i];
      if(a[i]==a[i-1])
        f=1;
    }

      if(f==1)
      {
        cout<<"-1\n";
      }
      else
      {
        for(i=0;i<15;i++)
        {
          for(j=1;j<n;j++)
          {
            //cout<<p[i][a[j]]<<" ";
            if(((p[i][a[j]-1]))==(char)(a[j-1]+48))
              break;
            if(((p[i][a[j-1]-1]))==(char)(a[j]+48))
              break;
          }
          if(j==n)
          {
            for(k=0;k<6;k++)
              {cout<<p[i][k]<<" ";}
            f=1;
            cout<<"\n";
            break;
          }

        }
        if(f==0)
          cout<<"-1\n";
      }

}
      }
return 0;
} 
