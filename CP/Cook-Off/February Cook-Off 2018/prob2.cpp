#include <bits/stdc++.h>

using namespace std;

/* O(sqrt(N)). */
vector<int> divisors(int n){
  vector<int> d;
  int i;

  // For every i up to sqrt(n).
  for (i = 1; i * i <= n; i++){
    // If i divides n.
    if (n % i == 0){
      if (i * i == n){
        // Pushing i.
        d.push_back(i);
      }
      else{
        // Pushing i and n / i.
        d.push_back(i);
        d.push_back(n / i);
      }
    }
  }
  return d;
}


int main(){
  int t, n, ans, a, b, c, i, j, x, y, z;
  vector<int> dx, dy;

  scanf("%d", &t);

  while (t--){
    scanf("%d%d%d%d", &n, &a, &b, &c);

    dx = divisors(n);
    ans = 0;

    for (i = 0; i < (int)dx.size(); i++){
      x = dx[i];

      dy = divisors(n / x);

      for (j = 0; j < (int)dy.size(); j++){
        y = dy[j];
        z = n / (x * y);

        if (x <= a and y <= b and z <= c){
          ans++;
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
