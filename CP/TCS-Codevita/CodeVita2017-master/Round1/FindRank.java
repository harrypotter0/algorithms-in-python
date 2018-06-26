import java.util.Scanner;
import java.math.BigInteger;

public class FindRank
{
    private static long fact(long n)
    {
        return (n <= 1) ? 1 : n * fact(n - 1);
    }

    private static int findSmallerInRight(String str, int low, int high)
    {
        int countRight = 0;

        for (int i = low + 1; i <= high; i++)
            if (str.charAt(i) < str.charAt(low))
                countRight++;

        return countRight;
    }

    private static long findRank(String str)
    {
        int len = str.length();
        long mul = fact(len);

        long rank = 1;

        int countRight;

        for (int i = 0; i < len; i++)
        {
            mul /= len - i;

            countRight = findSmallerInRight(str, i, len - 1);
            rank += countRight * mul;
        }

        return rank;
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        int n = Integer.parseInt(sc.nextLine().trim());
        BigInteger r = BigInteger.valueOf(1l);

        for (int i = 0; i < n; i++)
        {
            String line = sc.nextLine().trim();
            r = r.multiply(BigInteger.valueOf(findRank(line)));
        }

        r = r.mod(BigInteger.valueOf(23456));

        System.out.println(r);

        sc.close();
    }
}
