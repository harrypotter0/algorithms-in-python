import java.util.Scanner;
public class WoodCutters {
  public static void main(String [] args){
  Scanner scan = new Scanner(System.in);
  int n = scan.nextInt();
  int [] a = new int [2*n];
  for(int i = 0; i<2*n;i++){
  a[i] = scan.nextInt();
  }
  if(n==1){
  System.out.println(1);
  }
  else{
  int count = 2;
  for(int i=2;i<2*n-2;i = i+2){
    if(a[i]-a[i+1]>a[i-2]){
    count++;
    }
    else if(a[i]+a[i+1] < a[i+2]){
    a[i] = a[i]+a[i+1];
    count++;
    }
  }
  System.out.println(count);
  }
  }
}