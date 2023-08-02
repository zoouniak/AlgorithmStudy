package BOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ1012 {
    static boolean[][] farm;
    static boolean[][] visited;
    static int n, m;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int t = Integer.parseInt(br.readLine());
        for (int T = 0; T < t; T++) {
            String[] input = br.readLine().split(" ");
            m = Integer.parseInt(input[0]);
            n = Integer.parseInt(input[1]);
            int k = Integer.parseInt(input[2]);
            farm = new boolean[m][n];
            visited = new boolean[m][n];

            for (int i = 0; i < k; i++) {
                String[] xy = br.readLine().split(" ");
                int x = Integer.parseInt(xy[0]);
                int y = Integer.parseInt(xy[1]);
                farm[x][y] = true;
            }
            int result = 0;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (farm[i][j] && !visited[i][j]) {//배추가 있고 방문하지 않은 밭이라면
                        dfs(i, j);
                        result++;
                    }
                }
            }
            sb.append(result).append("\n");
        }
        System.out.print(sb.toString());
    }

    static public void dfs(int x, int y) {
        visited[x][y] = true;
        int[] dx = {0, 0, -1, 1};
        int[] dy = {-1, 1, 0, 0};
        //방향을 배열로 나타내고
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            //방향에 따른 좌표를 구하
            if ((nx > -1 && nx < m) && (ny > -1 && ny < n) && farm[nx][ny] && !visited[nx][ny])
                //nx와 ny가 밭 안에 있고, 해당 밭에 배추가 있고, 방문하지 않은 배추일 경우
                //방문.
                dfs(nx, ny);
        }
    }
}