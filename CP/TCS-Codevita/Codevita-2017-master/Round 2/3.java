import java.util.Scanner;
import java.util.Stack;
class Codevita {
 
    public static void main(String[] args) {
        
  Scanner sc=new Scanner(System.in);
  int t=sc.nextInt();
   sc.nextLine();
  while(t-->0){
      try{
      Stack<String> stack = new Stack<>();
     
  String s=sc.nextLine();
     s= s.replaceAll("1", "");
     s=s.replaceAll("2","");

     s=s.replaceAll("@\\*", "1");
     s=s.replaceAll("\\*@", "2");
      s=s.replaceAll("1.*?2", ""); 
      s=s.replaceAll("[0-9.]", "");
       s=s.replaceAll("[a-z.]", "");
       s=s.replaceAll("[A-Z.]", "");
       s=s.replaceAll("[%,;]", "");
       s=s.replaceAll(" ", "");
       
     //  System.out.println(""+s);
       stack.add("hello");
    
   for(int i=0;i<s.length();i++){
       {
          char character = s.charAt(i);    
int ascii = (int) character;
if(ascii==40||ascii==41||ascii==47||ascii==92||ascii==91||ascii==93||ascii==123||ascii==125)
{
   // System.out.println(ascii);
//           System.out.println(stack.lastElement());
//           System.out.println("stack first ele"+stack.lastElement()+" and char "+s.charAt(i));
//           
           if(stack.lastElement().equals("(")&&s.charAt(i)==')')
               stack.pop();
           else
               if(stack.lastElement().equals("[")&&s.charAt(i)==']')
              stack.pop();
           else
                   if(stack.lastElement().equals("{")&&s.charAt(i)=='}')
               stack.pop();
           else
                       if(stack.lastElement().equals("<")&&s.charAt(i)=='>')
               stack.pop();
           else
                           
                       if(stack.lastElement().equals("/")&&s.charAt(i)=='\\')
               stack.pop();
           else
                stack.add(s.charAt(i)+"");
}
       }
   }
      
    if(stack.lastElement().equals("hello"))
          System.out.println("True");
    else
          System.out.println("False");
      
      }catch(Exception e){
          
      }
            
  }
  
  
    }
 }
