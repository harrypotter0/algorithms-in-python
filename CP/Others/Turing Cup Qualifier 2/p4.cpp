#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp setprecision(4)<<fixed
#define ss second
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forl(v) for(int l=0; l<v; l++)
#define fort(v) for(int t=0; t<v; t++)
#define forz(v) for(int z=0; z<v; z++)
#define lli long long int
#define MAX 1100
#define double long double
#define ch 400
int inf = pow(10,9);
lli modulo = pow(10,9)+7;
lli md = pow(10,9)+7;
double eps = 1e-13;
ifstream in;
ofstream out;
//#define cin in
//#define cout out
void deal(){
  int t;
  cin>>t;
  forl(t){
    int n;
    cin>>n;
    int arr[n];
    lli sum = 0;
    fori(n){
      cin>>arr[i];
      sum+=arr[i];
      for(int j=i-1; j>-1; j--){
        int mn = min(arr[i],arr[j]);
        if(mn<=(arr[i]&arr[j]))
          sum+=mn;
      }
    }
    cout<<sum<<'\n';
  }
}
int main() {
  deal();
}
