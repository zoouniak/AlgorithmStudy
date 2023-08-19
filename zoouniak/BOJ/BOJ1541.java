package BOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ1541 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        String[] nums = s.split("[+\\-]");
        int numCnt = 0;
        int sum = 0;
        sum += Integer.parseInt(nums[numCnt++]);

        char lastOp = '+';
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '+') {
                if (lastOp == '-') {
                    sum -= Integer.parseInt(nums[numCnt++]);
                } else {
                    //뒤에 숫자가 0으로 시작하면 0만 더하고 괄호를 쳐버리자?
                    sum += Integer.parseInt(nums[numCnt++]);
                    lastOp = '+';
                }

            } else if (s.charAt(i) == '-') {
                //빼기인 경우
                sum -= Integer.parseInt(nums[numCnt++]);
                lastOp = '-';
            }
        }
        System.out.println(sum);
    }
}
