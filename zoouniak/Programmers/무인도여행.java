package Programmers;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class 무인도여행 {
    static int[][] m;
    static boolean[][] visited;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] maps = new String[4];

        for (int i = 0; i < 4; i++) {
            maps[i] = scanner.nextLine();
        }
        m = new int[maps.length][maps[0].length()];
        for (int i = 0; i < maps.length; i++) {
            for (int j = 0; j < maps[i].length(); j++) {
                if (maps[i].charAt(j) == 'X') {
                    m[i][j] = 0;
                } else {
                    m[i][j] = maps[i].charAt(j) - '0';
                }
            }
        }
        visited = new boolean[maps.length][maps[0].length()];
        int result = 0;
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < m.length; i++) {
            for (int j = 0; j < m[0].length; j++) {
                if (m[i][j] != 0 && !visited[i][j]) {
                    result = bfs(i, j);
                    if (result != 0) {
                        q.add(result);
                    }
                }
            }
        }
        int[] answer;
        if (!q.isEmpty()) {
            answer = q.stream().mapToInt(Integer::intValue).toArray();
            Arrays.sort(answer);
        } else answer = new int[]{-1};


        for (int i = 0; i < m.length; i++) {
            for (int j = 0; j < m[0].length; j++) {
                if (m[i][j] != 0 && !visited[i][j]) {
                    result = bfs(i, j);
                    if (result != 0) {
                        answer[answer.length] = result;
                    }
                }
            }
        }

        if (answer.length > 0) {
            Arrays.sort(answer);
        } else answer[0] = -1;
        System.out.println(answer);
    }

    public static int bfs(int i, int j) {
        int result = 0;
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{i, j});
        visited[i][j] = true;
        result += m[i][j];
        int[] x = {1, -1, 0, 0};
        int[] y = {0, 0, 1, -1};
        while (!q.isEmpty()) {
            int X = q.peek()[0];
            int Y = q.peek()[1];
            q.poll();
            for (int k = 0; k < 4; k++) {
                int dx = X + x[k];
                int dy = Y + y[k];
                if (dx >= 0 && dx < m.length && dy >= 0 && dy < m[0].length && m[dx][dy] != 0 && !visited[dx][dy]) {
                    visited[dx][dy] = true;
                    result += m[dx][dy];
                    q.add(new int[]{dx, dy});
                }
            }
        }
        return result;
    }
}