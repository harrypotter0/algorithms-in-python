#include <bits/stdc++.h>
    using namespace std;
    //CODE BY AKASH KANDPAL
    int main()
    {
        int t;
        cin>>t;
        while(t--)
        {
            int n,m;
            cin>>n>>m;
            char arr[n][m];
            int i,j;
            for(i=0;i<n;i++)
            {
                for(j=0;j<m;j++)
                {
                    //fflush(stdin);
                    cin>>arr[i][j];
                }
            }
            int cnt=1,ans=0;
            for(i=0;i<n;i++)
            {
                cnt=1;
                for(j=1;j<m;j++)
                {
                    if(arr[i][j]==arr[i][j-1])
                        cnt++;
                    else
                        cnt=1;
                    ans=max(ans,cnt);
                }
            }
            for(i=0;i<m;i++)
            {
                cnt=1;
                for(j=1;j<n;j++)
                {
                    if(arr[j][i]==arr[j-1][i])
                        cnt++;
                    else
                        cnt=1;
                    ans=max(ans,cnt);

                }
            }
            cout<<ans<<endl;
        }
        return 0;
    }    
