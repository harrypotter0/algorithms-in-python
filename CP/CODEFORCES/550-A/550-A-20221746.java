import java.util.*;
public class overlapping 
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		if(s.contains("AB") &&  s.substring(s.indexOf("AB")+2).contains("BA") || s.contains("BA")  && s.substring(s.indexOf("BA")+2).contains("AB"))
			System.out.println("YES");
		else
			System.out.println("NO");
	}
}