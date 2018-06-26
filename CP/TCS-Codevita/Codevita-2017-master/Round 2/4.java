
package java3;

import java.util.Scanner;

public class Java3 {


    public static void main(String[] args) {
       int n;
       Scanner sc=new Scanner(System.in);
       n=sc.nextInt();
       int k=2;
       while(true){
           int no=n*k;
           String hex = Integer.toHexString(no);
          int i=0;
          while(hex.charAt(i)==hex.charAt(i+1)&&(i+1)<hex.length())
              i++;
          int j=hex.length();
          j=j-1;
          while(hex.charAt(j)==hex.charAt(j-1)&&(j-1)>=0)
              j--;
          if(i+1==j)
          {
              System.out.println(hex);
              break;
          } 
           
           if(hex.length()>7)
               break;
           
           k++;
       }
    }
    
}

