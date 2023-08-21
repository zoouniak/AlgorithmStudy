package TCT.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 미래_도시 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s = br.readLine().split(" ");
        int n = Integer.parseInt(s[0]);
        int[][] company = new int[n + 1][n + 1];
        int m = Integer.parseInt(s[1]);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) company[i][j] = 0;
                else company[i][j] = 54321;
            }
        }//거리 초기화
        for (int i = 0; i < m; i++) {
            String[] input = br.readLine().split(" ");
            int x = Integer.parseInt(input[0]);
            int y = Integer.parseInt(input[1]);
            company[x][y] = company[y][x] = 1;
        }
        String[] s1 = br.readLine().split(" ");
        int x = Integer.parseInt(s1[0]);
        int k = Integer.parseInt(s1[1]);
        //1->x->k의 최단 경로
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int z = 1; z <= n; z++) {
                    company[j][z] = Math.min(company[j][z], company[j][i] + company[i][z]);
                    //j->z바로 가는 길, i를 거쳐 가는 길 중 최단 경로 채택
                }
            }
        }
        System.out.print(company[1][k] + company[k][x]>=54321? -1:company[1][k] + company[k][x]);
    }

}
