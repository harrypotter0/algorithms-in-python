import java.util.Scanner;

public class pie
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), ans = 0, keys[] = new int[26];
		char s[] = in.next().toCharArray();
		for(int i = 0; i < s.length; i += 2)
		{
			keys[s[i]-'a']++;
			if(keys[s[i+1]-'A'] == 0)
				ans++;
			else
				keys[s[i+1]-'A']--;
		}
		System.out.println(ans);
	}
}