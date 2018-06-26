import java.util.*;
public class Main{

public static void main (String[] Args){

Scanner s=new Scanner(System.in);
int score=0;
int[] arr1={500,1000,1500,2000,2500};
int[] arr2=new int[5];

for(int i=0; i<5;i++){
arr2[i]=s.nextInt();
}

for(int j=0;j<5;j++){
score+=Math.max(0.3*arr1[j],(((1.0)*(250-arr2[j]))/250)*arr1[j]-50*s.nextInt());
}
score+=s.nextInt()*100;
score-=s.nextInt()*50;
System.out.println(score);
}
}