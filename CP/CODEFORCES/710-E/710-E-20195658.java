import java.util.Scanner;

public class R368E {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		long[] dp = new long[n+1];
		int x = scan.nextInt();
		int y = scan.nextInt();
		dp[1] = x;
		for(int i = 2; i <= n; i++){
			dp[i] = Math.min(dp[i-1]+x, dp[(i+1)/2]+y+(i%2)*x);
		}
		System.out.println(dp[n]);
	}
}