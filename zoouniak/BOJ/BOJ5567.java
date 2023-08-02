package BOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class BOJ5567 {
    static boolean[][] friend;
    static boolean[] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());
        friend = new boolean[n + 1][n + 1];
        visited = new boolean[n + 1];
        ArrayList<Integer> friendlist = new ArrayList<>();
        int result = 0;
        for (int i = 0; i < m; i++) {
            String[] input = br.readLine().split(" ");
            int a = Integer.parseInt(input[0]);
            int b = Integer.parseInt(input[1]);
            friend[a][b] = friend[b][a] = true;
            if (a == 1) {
                friendlist.add(b);
            }
        }
        result = friendlist.size();

        for (Integer f : friendlist) {
            visited[f] = true;
        }
        for (Integer f : friendlist) {
            for (int i = 2; i < n + 1; i++) {
                if (friend[f][i] && !visited[i]) {
                    result++;
                    visited[i] = true;
                }
            }
        }
        System.out.println(result);
    }
}