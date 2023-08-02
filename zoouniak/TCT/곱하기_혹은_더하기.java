package TCT;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 곱하기_혹은_더하기 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s = br.readLine().split("");
        int[] nums = new int[s.length];
        for (int i = 0; i < nums.length; i++) {
            nums[i] = Integer.parseInt(s[i]);
        }
        int result = 0;
        for (int num : nums) {
            if (result <= 1 || num <= 1) {
                result += num;
            } else result *= num;
        }
        System.out.println(result);
    }
}