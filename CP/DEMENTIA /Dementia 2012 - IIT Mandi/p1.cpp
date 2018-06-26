#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 2000000009;
int a[1000009];
int longest;
void find(int x)
{
    int left = 1, right = longest;
    while(left <= right)
    {
        int mid = (left + right) >> 1;
        if(a[mid] <= x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
        // cout<<left<<" "<<right<<endl;
    }
    // cout<<right<<"right"<<endl;
    a[++right] = x;
    if(right > longest)
        longest = right;
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    a[i] = inf;
    longest = 0;
    for(int i = 1; i <= n; ++i)
    {
        int x;
        scanf("%d", &x);
        if((x -= i) >= 0)
            find(x);
        // for(int j =0;j<n;j++)cout<<a[j]<<" ";
        // cout<<"\n";
    }
    printf("%d\n",n - longest);
   //system("pause");
    return 0;
}
