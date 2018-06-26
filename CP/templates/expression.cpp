#include <bits/stdc++.h>
using namespace std;

int main()
{
      int t0;cin>>t0;
      while(t0--)
      {
          string s;
          cin>>s;
         //getline(cin,s);
          long long int a=0,b=0;
          vector<long long int> arr;
          vector<long long int> a1;
          int len=s.length();
          int f=0;
         // cout<<len;
          for(int i=0;i<=len;i++)
          {
            if(i!=len && s[i]>=48 && s[i]<=57 )
            a=(a*10)+(s[i]-48);
            else
            {
                if(f==1)a=-1*a;
              arr.push_back(a);
              if(s[i]=='-')f=1;
               else f=0;
              //cout<<"("<<a<<")";
              a=0;
            }
          }
          int j=0;
        // for(int i=0;i<arr.size();i++)cout<<"("<<arr[i]<<")";
          int fl=0;
          a1.push_back(arr[0]);j++;
          for(int i=0;i<len;i++)
          {
            if(s[i]=='*')
            { a1[((int)a1.size()-1)]*=arr[j];}
             else if(s[i]=='+' || s[i]=='-')
             {a1.push_back(arr[j]);}
              if(s[i]=='+' || s[i]=='-'|| s[i]=='*'){j++;}
          }
          long long sum=0;
          for(int i=0;i<a1.size();i++)
          {
          sum+=a1[i];
          }
          cout<<sum<<endl;
      }
    return 0;
}
