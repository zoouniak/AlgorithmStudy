package BOJ.java;

// 오주은 코드

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ1439 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        int[] count = new int[2];
        int[] num = new int[s.length()];
        int now = s.charAt(0) - '0';
        for (int i = 0; i < s.length(); i++) {
            num[i] = s.charAt(i) - '0';
            if (now != num[i]) {
                count[now]++;
                now = now == 0 ? 1 : 0;
            }
        }
        count[num[s.length() - 1]]++;
        System.out.println(count[0] > count[1] ? count[1] : count[0]);
    }
}