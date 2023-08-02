package TCT;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class 큰_수의_법칙 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);
        int K = Integer.parseInt(input[2]);
        String[] nums = br.readLine().split(" ");
        Integer[] arr = new Integer[N];
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(nums[i]);
        }
        Arrays.sort(arr);//배열 정렬

        int result = 0;
        int m = 0;
        while (true) {
            for (int j = 0; j < K; j++) {
                if (m == M) {
                    System.out.println(result);
                    return;
                }
                result += arr[N - 1];
                m++;
            }
            if (m == M) {
                System.out.println(result);
                return;
            }
            result += arr[N - 2];
            m++;
        }

    }
}