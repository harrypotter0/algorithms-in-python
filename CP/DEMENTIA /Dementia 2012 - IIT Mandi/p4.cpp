#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

long long fast_power(long long a, long long b, long long c)
{
     long long result = 1;
     while ( b > 0 ) {
           if ( b&1 ) result = ((result%c)*(a%c))%c;
           a = ((a%c)*(a%c))%c;
           b = b/2;
     }
     return result%c;
}

int main()
{
    long long n,x,i,sum,p,q,k;
    string s;

    scanf("%lld", &n);

    while ( n-- ) {
          cin >> s;
          reverse(s.begin(),s.end());
          scanf("%lld", &x);
          sum = 0;
          k = s.size();
          for ( i = 0; i < k; i++ ) {
              p = fast_power(11,i,x);
              q = fast_power(2,k-i-1,x);
            //   cout<<p<<" "<<q<<"pq";
              p = (p*q)%x;
              p = ((p%x)*((s[s.size()-i-1]-48)%x))%x;
              sum += p;
            //   cout<<sum<<"sum"<<endl;
          }
          printf("%lld\n", sum%x);
    }
    return 0;
}
 
