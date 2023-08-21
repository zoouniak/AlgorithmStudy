package TCT.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class 배열_원소_교체 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s = br.readLine().split(" ");
        int n = Integer.parseInt(s[0]);
        int k = Integer.parseInt(s[1]);
        int[] a = new int[n];
        int[] b = new int[n];
        String[] anum = br.readLine().split(" ");
        String[] bnum = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(anum[i]);
            b[i] = Integer.parseInt(bnum[i]);
        }
        Arrays.sort(a);
        Arrays.sort(b);
        for (int i = 0; i < k; i++) {
            int x = a[i];
            int y = b[n - 1 - i];
            if (x < y) //b배열의 원소가 a배열의 원소보다 클 때만 교
                a[i] = y;
            else break;
        }
        int result = 0;
        for (int i : a) {
            result += i;
        }
        System.out.println(result);
    }
}