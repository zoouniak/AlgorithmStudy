package BOJ.java;

import java.io.*;
import java.util.*;

public class BOJ7576 {
    static int[][] tomato;
    static boolean[][] visited;
    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, 1, -1};
    static int n, m;
    static Queue<int[]> q = new LinkedList();
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s = br.readLine().split(" ");
        m = Integer.parseInt(s[0]);
        n = Integer.parseInt(s[1]);
        tomato = new int[n][m];
        visited = new boolean[n][m];

        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");
            for (int j = 0; j < m; j++) {
                int x = Integer.parseInt(input[j]);
                tomato[i][j] = x;
                if(x==1) q.add(new int[] {i,j});
            }
        }
        bfs();
        int max = 0;
        //다 익었는 지 확인
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (tomato[i][j] == 0) {
                    System.out.println(-1);
                    return;
                }
                if (max < tomato[i][j]) max = tomato[i][j];
            }
        }
        System.out.println(max - 1);
    }

    static void bfs() {
        while (!q.isEmpty()) {
            int x = q.peek()[0];
            int y = q.peek()[1];
            q.poll();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && tomato[nx][ny] ==0) {
                        //인접한 것 중 덜익은 토마토 -> 토마토
                        tomato[nx][ny] = 1 + tomato[x][y];
                        visited[nx][ny] = true;
                        q.add(new int[]{nx, ny});
                }
            }

        }
    }
}