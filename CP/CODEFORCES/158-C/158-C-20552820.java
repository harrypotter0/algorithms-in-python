import java.util.*;

public class Main {

	public static void main(String[] args){
		Scanner obj = new Scanner(System.in);
		int n = Integer.parseInt(obj.nextLine());
		String[] s = new String[n];
		for (int i = 0; i < n; i++)
			s[i] = obj.nextLine();
		String pwd = "/";
		for (int i = 0; i < n; i++) {
			if (s[i].startsWith("pwd"))
				System.out.println(pwd);
			else {
				String arg = s[i].substring(3);
				if (!arg.endsWith("/"))
					arg += "/";
				if (arg.startsWith("/"))
					pwd = arg;
				else
					pwd += arg;

				while (pwd.contains(".."))
					pwd = pwd.replaceAll("[/]\\w+[/][.][.]", "");
			}
		}
	}
}