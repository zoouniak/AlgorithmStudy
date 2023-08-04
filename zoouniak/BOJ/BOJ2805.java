package BOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ2805 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int k = Integer.parseInt(input[1]);
        String[] s = br.readLine().split(" ");
        int[] tree = new int[n];
        int max = -1;
        for (int i = 0; i < n; i++) {
            tree[i] = Integer.parseInt(s[i]);
            max = Math.max(tree[i], max);
        }

        long start = 1;
        long end = tree[n - 1];
        while (start <= end) {
            long mid = (start + end) / 2;
            long sum = 0;
            for (int i : tree) {
                if (i > mid)
                    sum += (i - mid);
            }
            if (sum < k) {
                //나무 부족. 덜 잘라야함.
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        System.out.println((start + end) / 2);
    }
}
