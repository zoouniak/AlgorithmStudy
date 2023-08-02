package TCT;

import java.util.Scanner;

public class 왕실의_나이트 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        int row = s.charAt(0) - 'a' + 1;
        int col = s.charAt(1) - '0';

        int result = 8;
        if (row <= 2 || row >= 7) {
            result -= 2;
            if (row == 1 || row == 8)
                result--;
        }
        if (col <= 2 || col >= 7) {
            result -= 2;
            if (col == 1 || col == 8)
                result--;
        }
        System.out.println(result);
    }
}
