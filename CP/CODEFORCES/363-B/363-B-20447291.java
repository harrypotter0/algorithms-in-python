import java.util.Scanner;

public class main {
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int k=sc.nextInt();
		int arr[]=new int[n];
		for(int i=0;i<n;i++){
			arr[i]=sc.nextInt();
		}
		int m=0,h=0;
		for(int i=0;i<k;i++){
		h+=arr[i];
		}
		int x=h;
		for(int i=1;i<n-k+1;i++){
			x=x+arr[i+k-1]-arr[i-1];
			if(h>x){
				h=x;
				m=i;
			}
		}
		System.out.println(m+1);
	}
}