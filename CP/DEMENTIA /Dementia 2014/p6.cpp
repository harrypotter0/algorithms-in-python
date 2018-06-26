# include <iostream>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long n,ans=0;
        scanf("%lld",&n);
        while(n>0)
        {
            ans^=n; // gray code to binary
            n>>=1;
            // std::cout << ans << "ans"<< n << "n"<<" ";
        }
        printf("%lld\n",ans);
    }
}
