package BOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class BOJ11724 {
    //static boolean[][] graph;
    static LinkedList<Integer>[] graph;
    static boolean[] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s = br.readLine().split(" ");
        int n = Integer.parseInt(s[0]);
        int m = Integer.parseInt(s[1]);

        //graph = new boolean[n+1][n+1];
        graph = new LinkedList[n + 1];
        visited = new boolean[n + 1];

        for (int i = 1; i <= n; i++)
            graph[i] = new LinkedList<>();

        for (int i = 0; i < m; i++) {
            String[] input = br.readLine().split(" ");
            int u = Integer.parseInt(input[0]);
            int v = Integer.parseInt(input[1]);
            graph[u].add(v);
            graph[v].add(u);
            //graph[u][v]=graph[v][u]=true;
        }
        int result = 0;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                dfs(i);
                result++;
            }
        }
        System.out.println(result);
    }

    private static void dfs(int u) {
        if (visited[u])
            return;
        visited[u] = true;
        for (int i : graph[u]) {
            if (!visited[i])
                dfs(i);
        }
        /*for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u].get(i);
            if (!visited[v]) {
                dfs(v);
            }
        }*/
    }

    private static void bfs(int u) {
        Queue<Integer> q = new LinkedList<>();
        q.add(u);
        visited[u] = true;
        while (!q.isEmpty()) {
            int n = q.poll();
            for (int i = 0; i < graph[n].size(); i++) {
                int v = graph[n].get(i);
                if (!visited[v]) {
                    visited[v] = true;
                    q.offer(v);
                }
            }
        }
    }

}