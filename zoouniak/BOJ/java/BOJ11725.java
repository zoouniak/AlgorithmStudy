package BOJ.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class BOJ11725 {
    static LinkedList<Integer>[] tree;

    static int[] visited;
    static int n;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        tree = new LinkedList[n + 1];
        for (int i = 1; i < n + 1; i++) {
            tree[i] = new LinkedList<>();
        }
        visited = new int[n + 1];
        for (int i = 0; i < n - 1; i++) {
            String[] input = br.readLine().split(" ");
            int u = Integer.parseInt(input[0]);
            int v = Integer.parseInt(input[1]);
            tree[u].add(v);
            tree[v].add(u);
        }
        dfs(1);
        for (int i = 2; i < n + 1; i++)
            System.out.println(visited[i]);
    }

    private static void dfs(int u) {
        for (int i = 0; i < tree[u].size(); i++) {
            int x = tree[u].get(i);
            if (visited[x] == 0) {
                visited[x] = u;
                dfs(x);
            }
        }
    }

    private static void bfs(int u) {
        Queue<Integer> q = new LinkedList<>();
        q.add(u);
        while (!q.isEmpty()) {
            int x = q.poll();
            for (int i = 0; i < tree[x].size(); i++) {
                if (visited[tree[x].get(i)] == 0) {
                    visited[tree[x].get(i)] = x;
                    q.add(tree[x].get(i));
                }
            }
        }
    }
}
