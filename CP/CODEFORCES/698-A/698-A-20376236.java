import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(), count = 0, cur, prev = 3;
        for (int i = 0; i < n; i++) {
            cur = scanner.nextInt();
            if (cur == prev && cur != 3) cur = 0;
            else if (cur == 3 && prev != 3) cur -= prev;
            if (cur == 0) count++;
            prev = cur;
        }
        System.out.println(count);
    }
}