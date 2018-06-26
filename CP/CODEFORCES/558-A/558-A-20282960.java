import java.util.Scanner;

public class WA {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        
        int n = in.nextInt();
        int x;
        int a;
        int b[] = new int[200001];
        int plus=0;
        int minus=0;
        int max=0;

for (int i=0;i<n;i++) {
x = in.nextInt();
a = in.nextInt();
b[x+100000]=a;
if (x>0) {
plus++;
}
else
{
minus++;
}

}

x=Math.min(plus,minus);
if (plus>x) {
plus=x+1;
}
else if (minus>x) {
minus=x+1;
}

n=100000;

for (n=100000;minus>0;n--) {
if (b[n]>0) {
minus--;
max+=b[n];
}
}

for (n=100000;plus>0;n++) {
if (b[n]>0) {
plus--;
max+=b[n];
}
}

System.out.print(max);
        in.close();
    }
}