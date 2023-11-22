package BOJ.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.Queue;

public class BOJ1260 {
    //인접 리스트로 구현
    public static ArrayList<Integer>[] graph;
    public static boolean[] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);
        int v = Integer.parseInt(input[2]);

        graph = new ArrayList[n + 1];
        visited = new boolean[n + 1];
        for (int i = 1; i <= n; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            input = br.readLine().split(" ");
            int a = Integer.parseInt(input[0]);
            int b = Integer.parseInt(input[1]);
            graph[a].add(b);
            graph[b].add(a);
        }
        for (int i = 1; i <= n; i++) {
            graph[i].sort(Comparator.naturalOrder());
        }

        dfs(v);
        System.out.println();
        visited = new boolean[n+1];
        bfs(v);
    }

    public static void dfs(int v) {
        //깊이 우선..
        System.out.print(v + " ");
        visited[v] = true;
        for (int vertex : graph[v]) {
            if (!visited[vertex]) {
                dfs(vertex);
            }
        }
    }
    public static void bfs(int v){
        //내 인접한 것 먼저..
        Queue<Integer> q = new LinkedList<>();
        visited[v]=true;
        q.add(v);
        System.out.print(v+" ");
        while (!q.isEmpty()){
            int x = q.poll();
            for (Integer vertex : graph[x]) {
                if(!visited[vertex]){
                    visited[vertex]=true;
                    q.add(vertex);
                    System.out.print(vertex+" ");
                }
            }
        }
    }
}
