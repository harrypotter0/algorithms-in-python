import java.util.Scanner;

public class RationalCount
{
    private static int gcd(int x, int y)
    {
        if (y > x)
            return gcd(y, x);

        return y == 0 ? x : gcd(y, x % y);
    }

    public static void main(String[] args)
    {
        int n, m, i, j, flag, count;

        Scanner sc = new Scanner(System.in);
        sc.useDelimiter("\\s|/");

        n = sc.nextInt();
        m = sc.nextInt();

        i = gcd(n, m);

        n /= i;
        m /= i;

        i = 1; j = 1; flag = 1;
        count = 0;

        while (true)
        {
            if (gcd(i, j) == 1)
                count++;

            if (i == n && j == m)
                break;

            if (flag == 1)
            {
                if (j == 1)
                {
                    i++;
                    flag = -1;
                }
                else
                {
                    i++;
                    j--;
                }
            }
            else
            {
                if (i == 1)
                {
                    j++;
                    flag = 1;
                }
                else
                {
                    i--;
                    j++;
                }
            }
        }

        System.out.println(count);

        sc.close();
    }
}
