#include "iostream"
using namespace std;
int f =-1,s,k,d,i,c;
int main(){cin>>c;while(cin>>c){if(c<1)k++;
else{if(k>1&&f>-1)d+=k;if(f<0)f=i;s=i;k=0;}i++;}
cout<<(f==-1?0:s-f-d+1);}