package BOJ.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ1260 {
    public static int[][] graph;
    public static boolean[] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);
        int v = Integer.parseInt(input[2]);

       graph = new int[n+1][n+1];
       visited = new boolean[n+1];
       for(int i=0;i<m;i++){
           input = br.readLine().split(" ");
           int a = Integer.parseInt(input[0]);
           int b = Integer.parseInt(input[1]);
           graph[a][b]=1;
           graph[b][a]=1;
       }

        dfs(v);
        System.out.println();
        visited = new boolean[n+1];
        bfs(v);
    }

    public static void dfs(int v) {
        //깊이 우선
        System.out.print(v + " ");
        visited[v] = true;
        for(int i=1;i<graph[v].length;i++){
            if(graph[v][i]==1 && !visited[i]){
                dfs(i);
            }
        }
    }
    public static void bfs(int v){
        Queue<Integer> q = new LinkedList<>();
        visited[v]=true;
        q.add(v);
        System.out.print(v+" ");
        while (!q.isEmpty()){
            int x = q.poll();
            for(int i=1;i<graph[x].length;i++){
                if(graph[x][i]==1 && !visited[i]){
                    visited[i]=true;
                    System.out.print(i+" ");
                    q.add(i);
                }
            }
        }
    }
}
