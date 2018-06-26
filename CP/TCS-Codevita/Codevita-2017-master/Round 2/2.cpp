#include<bits/stdc++.h>
using namespace std;
bool checkprime(int x){
    if(x==0||x==1)
        return false;
for(int i=2;i<x;i++)
if(x%i==0)
return false;
return true;
}
int main(){
int t;
cin>>t;
while(t--){
    string st;
    vector<int> no;
    cin>>st;
 vector<int> count;
    for( int i=0;i<2;i++)
    {
      //  cout<< st[i];
    if(st[i]>=48&&st[i]<=57)
        no.push_back((int)(st[i]-48));
        else
            no.push_back(10+((int)st[i]-65));
    }
       int minbase=*max_element(no.begin(),no.end());
     /*cout<<" min base is "<<minbase<<endl;
       for(int x=0;x<no.size();x++)
        cout<<no[x]<<" ";
        cout<<endl;*/
minbase+=1;
//cout<<minbase<<endl;
        for(int i=minbase;i<=36;i++)
        {
            int newno=no[0]*i+no[1];
           // int base=i;

             /*for(int x=no.size()-2;x>=0;x--)
                        {
                            newno+=no[x]*base;
                            base=base*i;
                                        }
*/

            if(checkprime(newno)){
               count.push_back(i);
            // cout<<"new NO is "<<newno<<endl;
            }

        }
vector<int>::iterator it;
if(count.size()==0)
cout<<"NONE\n";
else
for(it=count.begin();it!=count.end();it++)
    cout<<*it<<" ";
    cout<<endl;
    count.clear();
}
return 0;
}
