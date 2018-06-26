import java.util.*;
public class ColorfulStones {
	public static void main(String args[]){
		Scanner s=new Scanner(System.in);
		String a=s.next();
		String t=s.next();
		int i=0,j=0;
		while(j<t.length()){
			if(a.charAt(i)==t.charAt(j)){
				i++;
				j++;}
				else
					j++;
		}
		System.out.println(i+1);
	}

}