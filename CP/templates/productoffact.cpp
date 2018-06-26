#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
#define ll long long
#define MAX 1000100

int n;
ll mod;

void input(){
  scanf("%d", &n);
}

ll mul(ll a,ll b){
  if(b == 0) return 0;
  if(b == 1) return a % mod;
  ll m = mul(a, b / 2);
  m = (m + m) % mod;
  if(b & 1) m = (m + a) % mod;
  return m;
}

void process(){
  if(n >= 587117){
    printf("0");
    return;
  }
  ll ans = 1, gt = 1;
    // mod = 109546051211;
    mod = 329885391853;
  for(ll i = 1; i <= n; i++){
    gt = mul(gt, i);
    ans = mul(ans, gt);
  }
  printf("%lld", ans);
}

int main(){
  //freopen("in.txt", "r", stdin);
  int t;
  cin>>t;
  while(t--){
    input();
  }
  process();
  return 0;
}
