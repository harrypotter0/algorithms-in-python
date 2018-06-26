import java.io.*;

public class CF476B {
	static int choose(int n, int k) {
		return k == 0 ? 1 : n * choose(n - 1, k - 1) / k;
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		char[] aa = br.readLine().toCharArray();
		char[] bb = br.readLine().toCharArray();
		int n = aa.length, pa = 0, pb = 0, q = 0;
		for (int i = 0; i < n; i++) {
			if (aa[i] == '+')
				pa++;
			if (bb[i] == '+')
				pb++;
			else if (bb[i] == '?')
				q++;
		}
		int p = pa - pb;
		System.out.println(p > q || p < 0 ? 0 : (double) choose(q, p) / (1 << q));
	}
}