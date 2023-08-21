package BOJ.java;
import java.io.*;
import java.util.*;
public class BOJ2606 {
    static boolean[][] computer;
    static boolean[] visited;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int k = Integer.parseInt(br.readLine());
        computer = new boolean[n+1][n+1];
        visited = new boolean[n+1];
        for(int i=0;i<k;i++){
            String[] input = br.readLine().split(" ");
            int x = Integer.parseInt(input[0]);
            int y = Integer.parseInt(input[1]);
            computer[x][y]=computer[y][x]=true;
        }

        System.out.println(bfs(1));

    }
    static int bfs(int start){
        Queue<Integer> q = new LinkedList();
        q.add(start);
        int cnt=0;
        visited[start]=true;
        while(!q.isEmpty()){
            int x =q.poll();
            for(int i=1;i<computer[x].length;i++){
                if(computer[x][i]&&!visited[i]){
                    visited[i]=true;
                    q.add(i);
                    cnt++;
                }
            }
        }
        return cnt;
    }
}
