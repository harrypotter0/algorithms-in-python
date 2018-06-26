#include<bits/stdc++.h>
using namespace std;
int main (){
string text;

cin>>text;
int arr[8][8]{0};/*{{5,5,5,5,5,5,5,5},
{5,5,5,5,5,5,5,5},
{5,5,5,5,5,5,5,5},
{5,5,5,5,5,5,5,5},
{5,5,5,5,5,5,5,5},
{5,5,5,5,5,5,5,5},
{5,5,5,5,5,5,5,5},
{5,5,5,5,5,5,5,5}};*/
//5 means empty
//1 means w ka bishop
//2 measn b ka bishop
//8 means blockage
int i=0,j=0;
string :: iterator it;
it =text.end();
int bishopx1=-1,bishopy1=-1;
int bishopx2=-1,bishopy2=-1;
bool first=false;
string temp;
cin>>temp;
for(it=text.begin();it!=text.end();it++)
{
        if(*it=='1'||*it=='2'||*it=='3'||*it=='4'||*it=='5'||*it=='6'||*it=='7'||*it=='8')
                    {
                j=j+*it-48;
              //  cout<<"\nmove by "<<*it<<" "<<i<<" "<<j<<"\n";
                    }
            else
                if(*it=='b'||*it=='B'||*it=='p'||*it=='P'||*it=='r'||*it=='R'||*it=='n'||*it=='N'||*it=='b'||*it=='B'||*it=='q'||*it=='Q'||*it=='k'||*it=='K')
            {
            if(*it=='b'||*it=='B')
           { cout<<"bishop aaya "<<*it<<endl;

            if(temp=="w"&&(*it=='B')){
             if(first==true)
            {
            bishopx2=i;
            bishopy2=j;}
            else{
             bishopx1=i;
            bishopy1=j;
            first=true;
            }
           }
            else if(temp!="w"&&(*it=='b'))
            if(first==true)
            {
            bishopx2=i;
            bishopy2=j;}
            else{
             bishopx1=i;
            bishopy1=j;
             first=true;}
              }

              arr[i][j]=8;
              j++;
          }if(*it=='/')
            { i++;
             j=0;
              }

}
for(int i=0;i<8;i++){
for(int j=0;j<8;j++){
cout << arr[i][j]<< " ";
}cout<<endl;}

cout<<bishopx1 << " "<<bishopy1<<endl;
cout<<bishopx2 << " "<<bishopy2<<endl;
//position to move is 4
char choice='0';
if(bishopx2!=-1)
 choice='1';
int diff1=bishopy1-bishopx1;
int diff2=bishopy2-bishopx1;

switch(choice){
case '0':
for (int i=0;i<8;i++)
for (int j=0;j<8;j++)
{
if(diff1==j-i||diff1==i-j)
if(arr[i][j]==0)
arr[i][j]=4;

}
break;
case '1':
for (int i=0;i<8;i++)
for (int j=0;j<8;j++)
{
if(diff1==j-i||diff2==j-i||diff1==i-j||diff2==i-j)
if(arr[i][j]==0)
arr[i][j]=4;

}
break;

default :
cout<<"eroor";
}
for(int i=0;i<8;i++){
for(int j=0;j<8;j++){
cout << arr[i][j]<< " ";
}cout<<endl;}


return 0;
}
