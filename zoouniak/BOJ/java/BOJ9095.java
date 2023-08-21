package BOJ.java;

import java.io.*;

public class BOJ9095 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int t = Integer.parseInt(br.readLine());
        int[] result = new int[11];
        result[1] = 1;//1
        result[2] = 2;//11 2
        result[3] = 4;//111 12 21 3
        //4-3 4-2 4-1
        for (int i = 4; i < 11; i++) {
            result[i] = result[i - 1] + result[i - 2] + result[i - 3];
        }
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(br.readLine());
            bw.write(result[n] + "\n");
        }
        bw.flush();
    }
}
