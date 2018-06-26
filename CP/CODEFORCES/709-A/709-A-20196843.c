#include <stdio.h>
int n,ans,B,D;
int main()
{
    int i,x,tot = 0;
    scanf("%d%d%d",&n,&B,&D);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if(x>B) continue;
        tot += x;
        if(tot>D) { ans++; tot = 0;}
    }
    printf("%d",ans);
    return 0;
}