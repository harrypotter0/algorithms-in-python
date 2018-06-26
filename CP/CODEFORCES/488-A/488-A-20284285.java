import java.util.*;

public class Giga_Tower{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int b = 1;
		while(("" + (n + b)).indexOf("8") == -1)
			b++;
		System.out.println(b);
	}
}