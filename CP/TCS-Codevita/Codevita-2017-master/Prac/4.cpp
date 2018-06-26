#include<bits/stdc++.h>
using namespace std;
int main (){
string text;
cin>>text;
int arr[8][8]{0};
//0 means empty
//1 means w ka bishop
//2 measn b ka bishop
//8 means blockage
int i=0,j=0;
string :: iterator it;
it =text.end();
int bishopx1=-1,bishopy1=-1;
int bishopx2=-1,bishopy2=-1;
bool chance;//true for white
string temp;
cin>>temp;
if(temp=="w")
chance=true;
for(it=text.begin();it!=text.end();it++)
{
        if(*it=='1'||*it=='2'||*it=='3'||*it=='4'||*it=='5'||*it=='6'||*it=='7'||*it=='8')
                    {
                j=j+*it;
                    }
            else
                if(*it=='b'||*it=='B'||*it=='p'||*it=='P'||*it=='r'||*it=='R'||*it=='n'||*it=='N'||*it=='b'||*it=='B'||*it=='q'||*it=='Q'||*it=='k'||*it=='K')
            {
        if(chance){
                if(*it=='b')
                    if(bishopx1!=-1)
                        {
                        bishopx2=i;
                        bishopy2=j;
                        }
                    else{
                        bishopx1=i;
                        bishopy1=j;
                        }
                }
                else{
                    if(*it=='B')
                        if(bishopx1!=-1)
                        {
                            bishopx2=i;
                            bishopy2=j;
                        }
                        else{
                            bishopx1=i;
                            bishopy1=j;
                            }

                    }

              arr[i][j]=8;
              j++;
          }if(*it=='/')
             i++;


}
for(int i=0;i<8;i++){
for(int j=0;j<8;j++){
cout << arr[i][j]<< " ";
}cout<<endl;}


return 0;
}
