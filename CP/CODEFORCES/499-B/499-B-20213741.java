import java.util.*;

public class lecture
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		String s, t;
		HashMap<String, String> map = new HashMap<String, String>();
		int n = in.nextInt(), m = in.nextInt();
		for(int i = 0; i < m; i++)
		{
			s = in.next();
			t = in.next();
			map.put(s, (t.length() < s.length() ? t : s));
		}
		for(int i = 0; i < n; i++)
		{
			s = in.next();
			System.out.print(map.get(s)+" ");
		}
		in.close();
	}
}