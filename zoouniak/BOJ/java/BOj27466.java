package BOJ.java;

import java.lang.*;
import java.io.*;

public class BOj27466 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String[] s = br.readLine().split(" ");
        int n = Integer.parseInt(s[0]);
        int m = Integer.parseInt(s[1]);
        String str = br.readLine();
        int containA = 0;
        char c = 'a';
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == 'A') {
                containA++;
            } else if (str.charAt(i) == 'A' || str.charAt(i) == 'I' || str.charAt(i) == 'E' || str.charAt(i) == 'O' || str.charAt(i) == 'U') {
                c = str.charAt(i);
            }
        }
        if (containA == 0 || c == 'a') {
            System.out.print("NO");
            return;
        }
        for (int i = 0; i < m; i++) {
            if (i == m - 1) sb.append(c);
            else if (i == m - 2 || i == m - 3) sb.append("A");
            else {
                sb.append(str.charAt(0));
            }
        }
        System.out.print(sb);

    }
}