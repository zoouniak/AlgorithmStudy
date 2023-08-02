package TCT;

// 오주은의 코드

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 일이_될_때까지 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int k = Integer.parseInt(input[1]);
        int cnt = 0;
        while (n != 1) {
            if (n % k == 0) {
                cnt++;
                n /= k;
            } else {
                cnt++;
                n -= 1;
            }
        }
        System.out.println(cnt);
    }
}