package TCT;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 바닥_공사 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] result = new int[n + 1];
        result[1] = 1;
        result[2] = 3;

        for (int i = 3; i <= n; i++) {
            result[i] = (result[i - 1] + result[i - 2] * 2) % 796796;
        }
        System.out.println(result[n]);
    }
}
