import java.util.*;
public class Main
{
	public static void main(String[]args)
	{
		Scanner i=new Scanner(System.in);
		int n=i.nextInt();
		long w=1,w1=1;
		for(int q=0;q<3*n;q++,w=(w*3)%(1000000007));
		for(int q=0;q<n;q++,w1=(w1*7)%(1000000007));
		w-=w1;
		if(w<0)
			w+=1000000007;
		System.out.println(w);
	}
}