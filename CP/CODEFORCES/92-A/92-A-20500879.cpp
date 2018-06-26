#include <iostream>

int main(){
  int n,m;std::cin>>n>>m;
  for(int i=0;;++i,i%=n){
    if(m<=i)return std::cout<<m<<'\n',0;
    m-=i+1;
  }
}