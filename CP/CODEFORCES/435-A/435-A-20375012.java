import java.util.Scanner;


public class QueueOnTheBusStop {
	public static void main(String ... lovatics){
		Scanner scn=new Scanner(System.in);
		int n=scn.nextInt(); int m=scn.nextInt();
		int sum=0; int c=0;
		for(int i=0;i<n;i++){
			int x=scn.nextInt();
			sum+=x;
			if(sum>m){
				sum=x;c++;
			}
		}
		System.out.println(c+1);
	}
}