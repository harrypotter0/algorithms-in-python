import java.util.Scanner;

public class A {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int n = scan.nextInt();
		int m = scan.nextInt();

		for (int i = 0; i < n * m; i++) {
			String s = scan.next();
			if (s.contains("C") || s.contains("M") || s.contains("Y")) {
				System.out.println("#Color");
				return;
			}
		}
		System.out.println("#Black&White");
	}
}