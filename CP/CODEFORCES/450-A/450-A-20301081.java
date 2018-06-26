import java.util.Scanner;

public class CF
{
	public static void main(String[] args)
	{
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int m = scan.nextInt();
		int max = 0, child = 0;
		for (int i = 0; i < n; i++)
		{
			int c = scan.nextInt();
			if ((c+m-1)/m >= max)
			{
				child = i+1;
				max = (c+m-1)/m;
			}
		}
		System.out.println(child);

		scan.close();
	}
}