package BOJ.java;

import java.io.*;

public class BOJ10989 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        int[] count = new int[10001];//수 범위 1~10000
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
            count[arr[i]]++;
        }
        //Arrays.sort(arr);

        //계수 정렬
        for (int i = 1; i < count.length; i++) {
            for (int j = 0; j < count[i]; j++)
                bw.write(i + "\n");
        }

        /*for (int i : arr) {
            bw.write(i+"\n");
        }*/
        bw.flush();
    }
}