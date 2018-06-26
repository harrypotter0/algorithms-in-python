import java.util.Scanner;

public class LuckyTicket {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		String s = scan.next();
		if(!s.matches("[4|7]+")){System.out.println("NO"); return;}
		int left = 0, right = 0;
		for(int i = 0; i < n/2; i++){
			left+=s.charAt(i);
			right+=s.charAt(n-i-1);
		}
		System.out.println(left==right?"YES":"NO");
	}

}