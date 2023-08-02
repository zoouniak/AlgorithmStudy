package TCT;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class 만들_수_없는_금액 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] input = br.readLine().split(" ");
        int[] num = new int[n];
        for (int i = 0; i < n; i++) {
            num[i] = Integer.parseInt(input[i]);
        }
        Arrays.sort(num);
        int target = 1;
        for (int i = 0; i < n; i++) {
            if (target < num[i]) break;//만들 수 없음
            target += num[i];
        }
        System.out.println(target);
    }
}