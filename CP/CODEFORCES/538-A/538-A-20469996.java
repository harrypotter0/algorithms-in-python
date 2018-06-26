import java.util.Scanner;

public class A {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String s = in.next();
		String me = "CODEFORCES";
		for(int i=0;i<s.length();i++) {
			for(int j=i+1;j<=s.length();j++) {
				if((s.substring(0,i) + s.substring(j,s.length())).equals(me)) {
					System.out.println("YES");
					return;
				}
			}
		}
		System.out.println("NO");
	}
}