import java.util.*;
public class cont {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);int n=sc.nextInt();int d=sc.nextInt();int x=0;int max=0;
		for(int i=0;i<d;++i){
			String s=sc.next();
			if(s.contains("0")){
				++x;
			}
			else{
				max = x>max?x:max;
				x=0;}
	}
		max = x>max?x:max;
		System.out.println(max);
	
	}
}