#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define io ios::sync_with_stdio
int main()
{
   io(false);
   cin.tie(0);
   int t;
   cin>>t;
   while(t--)
   {
      int m,n;
      cin>>m>>n;
      int a[m][n];
      int dp[m][n];
      for(int i=0;i<m;i++)
      {
         for(int j=0;j<n;j++)
         {
            cin>>a[i][j];
            dp[i][j]=0;
         }
      }
      dp[m-1][0]=1;
      for(int i=m-1;i>=0;i--)
      {
         for(int j=0;j<n;j++)
         {
            if(i==m-1 && j>=1)
            {
               if(dp[i][j-1] == 1 && a[i][j]==1)
               {
                  dp[i][j]=1;
               }
            }
            else if(j==0 && i!=m-1)
            {
               if(dp[i+1][j]==1 && a[i][j]==1)
               {
                  dp[i][j]=1;
               }
            }
            else
            {
               if((dp[i][j-1]==1 || dp[i+1][j] == 1) && a[i][j]==1)
                  dp[i][j]=1;
            }
         }
      }
      if(dp[0][n-1]==1)
         cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
   }
} 
/*
2
5 5
0 1 1 1 1
1 1 0 1 0
1 1 0 1 1
1 0 1 1 1
1 1 1 0 1
4 4
1 1 0 1
1 1 1 0
1 1 1 1
1 1 1 1

Output:
YES
NO
*/
