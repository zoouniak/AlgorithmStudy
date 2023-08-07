package BOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class BOJ11053 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        String[] input = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(input[i]);
        }
        int[] result = new int[n];
        result[0] = 1;
        int answer = 1;

        for (int i = 1; i < n; i++) {
            result[i] = 1;
            for (int j = 0; j < i; j++) {
                //내 이전의 값 중. 나보다 작은 거 중에 가장 큰 거
                if (arr[j] < arr[i]) {
                    result[i] = Math.max(1 + result[j], result[i]);
                }
            }
            answer = Math.max(answer, result[i]);
        }
        System.out.println(answer);
    }
}
