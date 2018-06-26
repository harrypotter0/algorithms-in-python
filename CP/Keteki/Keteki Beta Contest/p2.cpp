#include <bits/stdc++.h>

using namespace std;

#define mem0(arr) memset(arr , 0 , sizeof arr)
#define memf(arr) memset(arr , false , sizeof arr)
#define memdp(arr) memset(arr , -1 , sizeof arr)
#define rep(i , n) for(int i = 1; i <= n; i++)
#define loop(i , n) for(int i = 0; i < n; i++)
#define pb push_back
#define fi first
#define se second
#define cs(y) cout << "Case " << y << ": "
#define cs2(y) cout << "Case " << y << ":" << "\n"

typedef long long ll;
int arr [10 + 10][10 + 10];



int main()
{
    //ios::sync_with_stdio(false);cin.tie(0);

    int n , m  , k , d , t , tem1 , tem2 , tem3 , tem4 , y = 1, sum = 0 , ans = 0;
    string s , c;


    cin >>    t            ;


    while(t--){

        cin >> n >> m;

        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                if(i == j) arr[i][j] = 0;
                else arr[i][j] = 1e9;
            }
        }

        for(int i = 0; i < n; i++){
            cin >> s;
            for(int j = 0; j < s.size(); j++){
                if(s[j] == '1') arr[i][j] = 1;
            }
        }
        // for(int i=0;i<n;i++){
        // for(int j=0;j<n;j++){
        // cout<<arr[i][j]<<" ";
        // }
        // cout<<endl;
        // }

        loop(k , n){
            loop(i , n){
                loop(j , n){
                    arr[i][j] = min( arr[i][j], arr[i][k] + arr [k][j] );
                }
            }
        }
        // for(int i=0;i<n;i++){
        // for(int j=0;j<n;j++){
        // cout<<arr[i][j]<<" ";
        // }
        // cout<<endl;
        // }

        cout << arr[0][m] << "\n";
    }

    return 0;
}
