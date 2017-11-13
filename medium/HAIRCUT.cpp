   



   
    #include "bits/stdc++.h"
     
    using namespace std;
    #define MAX 151000
    #define INF 100000000
     
    int dpA[MAX];
    int T[MAX];
    int dp[MAX];
     
    deque<int> q;
     
    void solve()
    {
    	while(q.size())
    		q.pop_front();
    	int N,A,B;
    	scanf("%d%d%d", &N, &A, &B);
    	for(int i = 1 ; i <= N ; i++)
    		scanf("%d",T+i);
    	int maxGap = B - A + 1;
    	int minDistance = A;
    	dpA[0] = 0;
    	dp[0] = 0;
    	T[0] = 0;
    	for(int i = 1 ; i <= N ; i++)
    	{
    		if(T[i] - A >= 0)
    		{
    			int index = lower_bound(T, T + i, T[i] - A) - T;
    			if(T[i] - A <= T[index])
    				index--;
    //			printf("GO %d : %d\n",i,index);
    			dpA[i] = dp[index];
    		}
    		else
    			dpA[i] = -INF;
    		dp[i] = dp[i-1];
    		while(q.size() && T[i] - T[q.front()] + 1 > maxGap)
    			q.pop_front();
    		while(q.size() && i - q.back() + 1 + dpA[q.back()] < dpA[i] + 1)
    			q.pop_back();
    		q.push_back(i);
    		
    //		printf("OYO %d : %d\n", i, q.size()?q.front():-1);
    		if(q.size())
    		{
    			dp[i] = max(dp[i], dpA[q.front()] + i - q.front() + 1);
    		}
    		else
    		{
    //			dp[i] = max(dp[i], )
    		}
    	}
    //	for(int i = 0 ; i <= N ; i++)
    //		printf("HEY %d : %d %d\n", i, dpA[i], dp[i]);
    	printf("%d\n",dp[N]);
    }
     
    int main()
    {
    	int T;
    	scanf("%d",&T);
    	while(T--)
    	{
    		solve();
    	}
    	return 0;
    } 
