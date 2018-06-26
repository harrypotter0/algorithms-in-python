#include<bits/stdc++.h>
using namespace std;
int main(){

  multiset< int > s;
  multiset< int >::iterator it;

   int T , N;
   cin >> T >> N;
   for(int i = 1  ; i <= N ;++i ){
     int x;
     cin >> x;
     s.insert(x);
   }
   while(T--){
     int ch , l;
     cin >> ch >> l;
     if(ch == 1)
     s.insert(l);
     else
     if(ch==2)
     s.erase(l);
     else {
      if(s.size()  <  2 )
      cout << "-1" << endl;
      else
      {
      it = s.end();
      it--;
      int A = *it;
      --it;
      int B = *it;
      cout << (A+B) << endl;
      }
     }
   }
}
