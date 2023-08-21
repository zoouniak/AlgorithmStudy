package BOJ.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class BOJ3187 {
    static char[][] farm;
    static boolean[][] visited;
    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    static int aliveWolf = 0;
    static int aliveSheep = 0;
    static int r;
    static int c;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s = br.readLine().split(" ");
        r = Integer.parseInt(s[0]);
        c = Integer.parseInt(s[1]);
        farm = new char[r][c];
        visited = new boolean[r][c];
        for (int i = 0; i < r; i++) {
            String input = br.readLine();
            for (int j = 0; j < c; j++) {
                farm[i][j] = input.charAt(j);
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (!visited[i][j] && farm[i][j] == '#') {
                    bfs(i, j);
                    System.out.println("[" + i + "," + j + "]");
                    System.out.println(aliveSheep + " " + aliveWolf);
                }
            }
        }
        System.out.println(aliveSheep + " " + aliveWolf);
    }

    static void bfs(int i, int j) {
        Queue<int[]> q = new LinkedList<>();
        visited[i][j] = true;
        q.add(new int[]{i, j});
        int wolf = 0;
        int sheep = 0;
        while (!q.isEmpty()) {
            int x = q.peek()[0];
            int y = q.peek()[1];
            q.poll();
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
                    if (farm[nx][ny] == 'v' && !visited[nx][ny]) {
                        wolf++;
                        visited[nx][ny] = true;
                        q.add(new int[]{nx, ny});
                    } else if (farm[nx][ny] == 'k' && !visited[nx][ny]) {
                        sheep++;
                        visited[nx][ny] = true;
                        q.add(new int[]{nx, ny});
                    } else if (farm[nx][ny] == '.' && !visited[nx][ny]) {
                        q.add(new int[]{nx, ny});
                        visited[nx][ny] = true;
                    }
                }
            }
        }
        if (wolf >= sheep) {
            aliveWolf += wolf;
        } else {
            aliveSheep += sheep;
        }
    }
}
