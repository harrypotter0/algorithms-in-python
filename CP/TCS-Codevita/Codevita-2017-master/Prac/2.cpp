#include<bits/stdc++.h>
using namespace std;
int main(){
int s,k;
int temp;
cin>>s>>k;
vector<int> arr1,arr2;
for(int i=0;i<s;i++)
{cin>>temp;
arr1.push_back(temp);}
for(int i=0;i<s;i++)
{
cin>>temp;
arr2.push_back(temp);}
int maxelementindex,minelementindex;
maxelementindex=distance(arr2.begin(),max_element(arr2.begin(),arr2.end()));
minelementindex=distance(arr2.begin(),min_element(arr2.begin(),arr2.end()));
int  flag=0;//0 means addition in first,1 means subtraction in first 2 means further check
if(abs(arr2[maxelementindex])<abs(arr2[minelementindex]))
flag=0;
else
flag=1;


if(flag==0)
arr1[minelementindex]+=2*k;
else if(flag==1)
arr1[maxelementindex]-=2*k;
int sum=0;
for(int i=0;i<s;i++){
sum+=arr1[i]*arr2[i];}
cout<<sum;





return 0;}

