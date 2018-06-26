#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define pii pair<int,int>
#define vll vector<ll>
#define vi vector<int>
#define d0(x) cout<<x<<" "
#define d1(x) cout<<x<<"\n"
#define d2(x,y) cout<<x<<" "<<y<<"\n"
#define d3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define d4(x,y,z,w) cout<<x<<" "<<y<<" "<<z<<" "<<w<<"\n"
using namespace std;
const ll mod=1e9+7;

int main()
{
	//freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio ( false );
    int t;cin>>t;
    while(t--)
    {
              int g,b;cin>>g>>b;
              string s[g][b];int score[g][b];
              for(int i=0;i<g;i++)
              {
                  for(int j=0;j<b;j++)
                  {
                      string k;
                      cin>>s[i][j]>>k>>score[i][j];
                  }
              }
              string t1,t2;cin>>t1>>t2;
              int a1,b1,a2,b2;
              for(int i=0;i<g;i++)
              {
                  for(int j=0;j<b;j++)
                  {
                      if(t1==s[i][j]){a1=i;b1=j;}
                      if(t2==s[i][j]){a2=i;b2=j;}
                  }
              }
              swap(s[a1][b1],s[a2][b2]);
              swap(score[a1][b1],score[a2][b2]);
              for(int i=0;i<g;i++)
              {
                  for(int j=0;j<b;j++)
                  {
                      for(int k=0;k<b-1;k++)
                      {
                          if(score[i][k]<score[i][k+1])
                          {
                              swap(score[i][k],score[i][k+1]);
                              swap(s[i][k],s[i][k+1]);
                          }
                      }
                  }
              }
              for(int i=0;i<g;i++)
              {
                  cout<<s[i][0]<<"\n";
              }
    }
}
