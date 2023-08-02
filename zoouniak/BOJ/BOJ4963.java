package BOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class BOJ4963 {
    static boolean[][] map;
    static boolean[][] visited;
    static int[] dx = {1, -1, 0, 0, 1, 1, -1, -1};
    static int[] dy = {0, 0, 1, -1, 1, -1, -1, 1};
    static int w, h;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        while (true) {
            String[] input = br.readLine().split(" ");
            w = Integer.parseInt(input[0]);
            h = Integer.parseInt(input[1]);
            map = new boolean[w][h];
            visited = new boolean[w][h];
            if (w == 0 && h == 0) break;
            for (int i = 0; i < h; i++) {
                String[] s = br.readLine().split(" ");
                for (int j = 0; j < w; j++) {
                    if (Integer.parseInt(s[j]) == 1)
                        map[j][i] = true;
                }
            }
            int result = 0;
            for (int i = 0; i < w; i++) {
                for (int j = 0; j < h; j++) {
                    if (map[i][j] && !visited[i][j]) {
                        bfs(i, j);
                        result++;
                    }
                }
            }
            sb.append(result).append("\n");
        }
        System.out.print(sb.toString());
    }

    private static void bfs(int u, int v) {
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{u, v});
        visited[u][v] = true;
        while (!q.isEmpty()) {
            int x = q.peek()[0];
            int y = q.peek()[1];
            q.poll();
            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < w && ny >= 0 && ny < h) {
                    if (!visited[nx][ny] && map[nx][ny]) {
                        visited[nx][ny] = true;
                        q.offer(new int[]{nx, ny});
                    }
                }
            }
        }
    }
}