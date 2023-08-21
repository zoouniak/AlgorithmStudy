//오주은
package BOJ.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ1149 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] cost = new int[3];
        int[][] homes = new int[n + 1][3];
        homes[0][0] = 0;
        homes[0][1] = 0;
        homes[0][2] = 0;
        for (int i = 1; i < n; i++) {
            String[] input = br.readLine().split(" ");
            for (int j = 0; j < 3; j++) {
                cost[j] = Integer.parseInt(input[j]);
            }
            homes[i][0] = Math.min(homes[i - 1][1], homes[i - 1][2]) + cost[0];
            homes[i][1] = Math.min(homes[i - 1][0], homes[i - 1][2]) + cost[1];
            homes[i][2] = Math.min(homes[i - 1][0], homes[i - 1][2]) + cost[2];
        }
        System.out.println(Math.min(homes[n][2], Math.min(homes[n][0], homes[n][1])));
    }

}