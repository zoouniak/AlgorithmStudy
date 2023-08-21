package BOJ.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ2839 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] sugar = new int[5001];
        sugar[3] = 1;
        sugar[4] = 0;
        sugar[5] = 1;
        for (int i = 6; i <= n; i++) {
            if (sugar[i - 3] != 0 && sugar[i - 5] != 0) {
                sugar[i] = 1 + Math.min(sugar[i - 3], sugar[i - 5]);
            } else if (sugar[i - 3] != 0 && sugar[i - 5] == 0) {
                sugar[i] = 1 + sugar[i - 3];
            } else if (sugar[i - 3] == 0 && sugar[i - 5] != 0) {
                sugar[i] = 1 + sugar[i - 5];
            } else {
                sugar[i] = 0;
            }
        }
        System.out.println(sugar[n] == 0 ? -1 : sugar[n]);
    }
}
