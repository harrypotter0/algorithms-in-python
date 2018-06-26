using System;

public class RationalCount
{
    private static int Gcd(int x, int y)
    {
        if (y > x)
            return Gcd(y, x);

        return y == 0 ? x : Gcd(y, x % y);
    }

    public static void Main(string[] args)
    {
        int n, m, i, j, flag, count;

        string line = Console.ReadLine();

        n = int.Parse(line.Split('/')[0].Trim());
        m = int.Parse(line.Split('/')[1].Trim());

        i = Gcd(n, m);

        n /= i;
        m /= i;

        i = 1; j = 1; flag = 1;
        count = 0;

        while (true)
        {
            if (Gcd(i, j) == 1)
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

        Console.WriteLine(count);
    }
}
