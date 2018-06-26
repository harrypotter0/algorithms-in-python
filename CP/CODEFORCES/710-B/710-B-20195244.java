import java.util.Scanner;
import java.util.Arrays;

public class B {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		Integer[] a = new Integer[n];
		for(int i = 0; i < n; i++)a[i] = scan.nextInt();
		Arrays.sort(a);
		System.out.println(a[(n-1)/2]);
	}

}