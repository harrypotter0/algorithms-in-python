import java.util.*;
public class _567B_Berland_National_Library {
	public static void main(String[] args) {
		Scanner leer = new Scanner (System.in);
		int n = leer.nextInt();
		boolean E []= new boolean[1000001];
		int min =0,c=0;
		for (int i = 0; i < n; i++) {
			String s = leer.next();
			int r = leer.nextInt();
			if(s.charAt(0)=='-'){
				if(!E[r])min++;
				else c--;
			}
			else c++;
			E[r]=true;
			if(c>min)min=c;
		}
System.out.println(min);
	}
}