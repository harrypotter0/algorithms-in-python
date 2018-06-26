import java.util.*;

public class ProC {
	static int n,m,p;
	static long ans,inf=(long)1e14;
	static int[] cc=new int[105];
	static int[][] pp=new int[105][105];
	static long[][][] dp=new long[105][105][105];

	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		n=in.nextInt();m=in.nextInt();
		p=in.nextInt();
		for(int i=1;i<=n;i++)
			cc[i]=in.nextInt();
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			pp[i][j]=in.nextInt();
		for(int j=1;j<=m;j++)
		{
			for(int k=0;k<=p;k++)
				dp[1][j][k]=inf;
			if(cc[1]==0) dp[1][j][1]=pp[1][j];
			else if(cc[1]==j) dp[1][j][1]=0;
		}
		for(int i=2;i<=n;i++)
		for(int j=1;j<=m;j++)
		for(int k=0;k<=p;k++)
		{
			dp[i][j][k]=inf;
			if(cc[i]>0&&cc[i]!=j) continue;
			if(i<k||p-k>n-i||k==0) continue;
			dp[i][j][k]=Math.min(dp[i][j][k],dp[i-1][j][k]);
			for(int a=1;a<=m;a++)
				if(a!=j) dp[i][j][k]=Math.min(dp[i][j][k],dp[i-1][a][k-1]);
			if(cc[i]==0) dp[i][j][k]+=pp[i][j];
		}
		ans=inf;
		for(int i=1;i<=m;i++)
			ans=Math.min(ans,dp[n][i][p]);
		if(ans>=inf) ans=-1;
		System.out.println(ans);
	}
}