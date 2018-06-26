public class M{
	public static void main(String[] a) {
		String[] x = {
			"zero","one","two","three","four",
			"five","six","seven","eight","nine",
			"ten","eleven","twelve","thirteen","fourteen",
			"fifteen","sixteen","seventeen","eighteen","nineteen"
		};
		
		String[] y = {
			"" ,"",
			"twenty", "thirty","forty","fifty",
			"sixty","seventy","eighty","ninety"
		};
		int n = new java.util.Scanner(System.in).nextInt();
		System.out.println(n < 20 ? x[n] : n % 10 == 0 ?y[n/10]:y[n/10] + "-" + x[n%10]);
	}
}