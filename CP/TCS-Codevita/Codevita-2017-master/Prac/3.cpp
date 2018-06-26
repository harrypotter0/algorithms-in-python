#include<bits/stdc++.h>
#define ll long long int
using namespace std;
bool checkprime(ll x){
if(x==0||x==1)
return false;
for(int i=2;i<=sqrt(x);i++)
if(x%i==0)
return false;
return true;

}
int main(){
ll n,count=0;
cin>>n;
ll sum=0;
ll i=2;
while(sum<=n){
if(checkprime(i)){
sum+=i;
//cout<<" "<<i<<" is prime\n";
if(sum<=n&&checkprime(sum))
count++;
}
i++;
}

cout<<count-1;
return 0;
}
