package TCT.java;

//오주은 코드

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class 볼링공_고르기 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s = br.readLine().split(" ");
        int n = Integer.parseInt(s[0]);
        int m = Integer.parseInt(s[1]);
        String[] b = br.readLine().split(" ");
        int[] balls = new int[n];
        for (int i = 0; i < n; i++) {
            balls[i] = Integer.parseInt(b[i]);
        }
        Arrays.sort(balls);
        int result = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (balls[i] == balls[j]) continue;
                result++;
            }
        }
        System.out.println(result);
    }
}