package BOJ.java;
import java.util.*;
import java.io.*;

public class BOJ2667 {
    static int[][] map;
    static boolean[][] visited;
    static int[] dx = {1,-1,0,0};
    static int[] dy = {0,0,1,-1};
    static int n;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        n = Integer.parseInt(br.readLine());
        map = new int[n][n];
        visited = new boolean[n][n];
        for(int i=0;i<n;i++){
            String input = br.readLine();
            for(int j=0;j<n;j++){
                int x = input.charAt(j)-'0';
                if(x==1)
                    map[i][j]=1;
                else map[i][j]=0;
            }
        }
        ArrayList<Integer> count = new ArrayList<>();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(map[i][j]==1&&!visited[i][j]){
                    count.add(bfs(i,j));
                }
            }
        }
        bw.write(count.size()+"\n");
        count.sort(Comparator.naturalOrder());
        for(int i:count){
                bw.write(i + "\n");
        }
        bw.flush();
    }
    static int bfs(int start,int end){
        int cnt=1;
        Queue<int[]> q = new LinkedList();
        q.add(new int[] {start,end});
        visited[start][end]=true;
        while(!q.isEmpty()){
            int x = q.peek()[0];
            int y = q.peek()[1];
            q.poll();
            for(int i=0;i<4;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx>=0&&nx<n&&ny>=0&&ny<n&&!visited[nx][ny]&&map[nx][ny]==1){
                    visited[nx][ny]=true;
                    q.add(new int[] {nx,ny});
                    cnt++;
                }
            }
        }
        return cnt;
    }


}