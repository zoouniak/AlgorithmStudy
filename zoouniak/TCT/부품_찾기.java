package TCT;

import java.io.*;
import java.util.Arrays;

public class 부품_찾기 {
    static int n;
    static int[] market;
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        market = new int[n];
        String[] input = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            market[i] = Integer.parseInt(input[i]);
        }
        int m = Integer.parseInt(br.readLine());
        int[] purchase = new int[m];
        String[] input2 = br.readLine().split(" ");
        for (int i = 0; i < m; i++) {
            purchase[i] = Integer.parseInt(input2[i]);
        }
        Arrays.sort(market);
        for (int i = 0; i < m; i++) {//purchase에 잇는거부터 하나씩 찾자!
            binarysearch(purchase[i]);
        }
        bw.flush();
    }

    private static void binarysearch(int find) throws IOException {
        int start = 0;
        int end = n - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (market[mid] == find) {
                bw.write("yes ");
                return;
            } else if (market[mid] > find) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        bw.write("no ");
    }
}
