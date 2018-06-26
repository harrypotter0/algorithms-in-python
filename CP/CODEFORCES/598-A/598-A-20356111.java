import java.util.Scanner;

public class Main {

	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		while(t-- > 0){
		long n = in.nextInt(), sum = ((n+1)*n)/2, mul = 1;
		while(mul <= n){sum -= mul *= 2;}
			System.out.println(sum);
		}
		in.close();
	
	}
}