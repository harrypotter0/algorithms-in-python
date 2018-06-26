#include<bits/stdc++.h>
using namespace std;

int main(){
long long int n;
double p;
cin>>n>>p;
long long count=0;
for(long long int i=2;i<=n;i++)
{

    for(long long int j=2;j<=i;j++)
    {
        long long int num=j*(j-1),denom=i*(i-1);
        double result=(double)num/denom;
        if(result==p){
            count++;
              //cout<<result<<" ";
              }

    }
}
cout<<count<<endl;
return 0;
}
