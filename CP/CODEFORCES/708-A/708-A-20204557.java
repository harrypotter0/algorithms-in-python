import java.util.*;
public class test
{
	public static void main(String args[])
	{
		Scanner reader=new Scanner(System.in);

		StringBuffer s=new StringBuffer(reader.next());
		
		int flag=0;
		int pos=0;
		while(pos<s.length()&&s.charAt(pos)=='a')
			pos++;
		while(pos<s.length()&&s.charAt(pos)!='a')
		{
			flag=1;
			s.setCharAt(pos,(char)(s.charAt(pos)-1));
			pos++;
		}
		if(flag==0)
			s.setCharAt(s.length()-1,'z');
		System.out.println(s);
	}
}