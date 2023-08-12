package BOJ;

import java.io.*;

public class BOJ16967 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String[] s = br.readLine().split(" ");
        int h = Integer.parseInt(s[0]);
        int w = Integer.parseInt(s[1]);
        int x = Integer.parseInt(s[2]);
        int y = Integer.parseInt(s[3]);

        int[][] a = new int[h][w];
        int[][] b = new int[h + x][w + y];
        for (int i = 0; i < h + x; i++) {
            String[] input = br.readLine().split(" ");
            for (int j = 0; j < w + y; j++) {
                int n = Integer.parseInt(input[j]);
                if (i < x && i < h&&j<w) {//1행 /1열은 a,b동일.
                    a[i][j] = n;
                }else if(j<y&&j<w&&i<h){
                    a[i][j]=n;
                }
                b[i][j] = n;
            }
        }

        for (int i = x; i < h; i++) {
            for (int j = y; j < w; j++) {
                a[i][j] = b[i][j] - a[i - x][j - y];
            }
        }

        for (int[] arr : a) {
            for (int i : arr) {
                bw.write(i+" ");
            }
            bw.write("\n");
        }

        bw.flush();
    }
}
