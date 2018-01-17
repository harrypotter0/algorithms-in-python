#include <bits/stdc++.h>
using namespace std;


// Driver Program to test above function
int main()
{
  int t,n,j;
  int x1,y1,z1,w,x2,y2,z2,i,m;
  cin>>t;
  int arr[101][101][101];
  int test[1001][4];

  while(t>0)
  {
      cin>>n>>m;

      int k=0;
      while(m>0)
      {
          string s;
          cin>>s;
          if(s=="UPDATE")
          {
              cin>>x1>>y1>>z1>>w;
              int flag=0;
              for(i=0;i<k;i++)
              {
                  if(test[i][0]==x1 && test[i][1]==y1 && test[i][2]==z1)
                  {
                      test[i][3]=w;
                      flag=1;
                  break;
                  }
              }
              if(flag!=1)
              {
              test[k][0]=x1;
              test[k][1]=y1;
              test[k][2]=z1;
              test[k][3]=w;
              k++;
              }
          }
          else if(s=="QUERY")
          {
              cin>>x1>>y1>>z1>>x2>>y2>>z2;
              long long sum=0;
              for(i=0;i<k;i++)
              {
                  if((test[i][0]>=x1 && test[i][0]<=x2) && (test[i][1]>=y1 && test[i][1]<=y2) && (test[i][2]>=z1 && test[i][2]<=z2))
                sum=sum+test[i][3];
              }
              cout<<sum<<endl;
          }
          m--;
      }
      t--;
  }
} 
