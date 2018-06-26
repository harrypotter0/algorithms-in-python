#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
using namespace std;

typedef double coord_t;         // coordinate type
typedef double coord2_t;  // must be big enough to hold 2*max(|coordinate|)^2

class Point {
   public:
       coord_t x, y;
       Point(){}
       Point(double a, double b){x=a; y=b;};
       bool operator <(const Point &p) const {
               return x < p.x || (x == p.x && y < p.y);
       }
};

coord2_t cross(const Point &O, const Point &A, const Point &B)
{
       return (A.x - O.x) * (coord2_t)(B.y - O.y) - (A.y - O.y) *
(coord2_t)(B.x - O.x);
}

vector<Point> convex_hull(vector<Point> P)
{
       int n = P.size(), k = 0;
       vector<Point> H(2*n);

       // Sort points lexicographically
       sort(P.begin(), P.end());

       // Build lower hull
       for (int i = 0; i < n; i++) {
               while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
               H[k++] = P[i];
       }

       // Build upper hull
       for (int i = n-2, t = k+1; i >= 0; i--) {
               while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
               H[k++] = P[i];
       }

       H.resize(k);
       return H;
}

int main(){
   vector<Point> q, a;
   double x, y;

   int count;
   cin>>count;
   while(count--){
       cin>>x>>y;
       q.push_back(Point(x+1, y+1));
       q.push_back(Point(x+1, y-1));
       q.push_back(Point(x-1, y-1));
       q.push_back(Point(x-1, y+1));
   }

   a=convex_hull(q);
   double sum=0;
   for(int i=1; i<a.size(); i++)
       sum+=sqrt(((a[i-1].x-a[i].x)*(a[i-1].x-a[i].x)) +
((a[i-1].y-a[i].y)*(a[i-1].y-a[i].y)));

   printf("%f", sum);
   return 0;
}  
