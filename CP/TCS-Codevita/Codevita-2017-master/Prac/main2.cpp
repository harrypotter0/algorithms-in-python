#include<bits/stdc++.h>

using namespace std;
int visited[99999]{0};
vector<long long int> vec;
int dfs(multimap<long long int,pair<long long int,long long int>,greater<long long int>> mp,long long int u,long long int v,long long k,bool flag,long long int prev)
{
if(u==v||u==99999)
    {

        return 0;
    }
vec.push_back(u);
cout<<"pushed "<<u<<" \n";
visited[u]=1;
    pair <multimap<long long int,pair<long long int,long long int>> ::iterator,multimap<long long int,pair<long long int,long long int>> ::iterator> rg;
    multimap<long long int,pair<long long int,long long int>> ::iterator it,jt;
 rg=mp.equal_range(u);

    if(distance(rg.first,rg.second)>0)
    {      bool fg=false;
        for ( jt=rg.first; jt!=rg.second; ++jt)
        {  cout<<"vertex adjacent to "<<u<<" == "<<jt->second.first<<" \n";
           fg=true;
             if(visited[jt->second.first]==0)
            dfs(mp,jt->second.first,v,k,flag,prev);
        }
        if(fg==false)
        return 0;

        }
        else
        return 0;

visited[u]=0;
vec.pop_back();
cout<<"popped "<<u<<"\n";

}
int main()
{
    long long int t;

    cin >> t;

    while (t--)
    {

        long long int n;
        cin>>n;

        long long int sum=0;
        multimap<long long int,pair<long long int,long long int>,greater<long long int>> mp;
        multimap<long long int,pair<long long int,long long int>> ::iterator it,jt;
        pair <multimap<long long int,pair<long long int,long long int>> ::iterator,multimap<long long int,pair<long long int,long long int>> ::iterator> rg;
        long long int vertices=n;
        n=n-1;
        while(n--)
        {

            long long int fv,sv,wt;
            cin>>fv>>sv>>wt;
            mp.insert(make_pair(sv,make_pair(99999,wt)));
            mp.insert(make_pair(fv,make_pair(99999,wt)));
            mp.insert(make_pair(sv,make_pair(fv,wt)));
            mp.insert(make_pair(fv,make_pair(sv,wt)));
        }
        long long int queries;
        cin>>queries;

        while(queries--)
        {
            long long int u,v,k;
            cin>>u>>v>>k;
            long long int sum=0;
            bool flag=false;
            long long int prev=0;
            int cd=dfs(mp,u,v,k,flag,prev);
           for(int l=0;l<vec.size();l++)
            cout<<vec[l]<<" ";

        }
    }
    return 0;
}

