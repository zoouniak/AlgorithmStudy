package BOJ;

import java.io.*;
import java.util.*;

public class BOJ2178 {
    static int[][] map;
    static int[] dx = {1,-1,0,0};
    static int[] dy = {0,0,1,-1};
    static int n,m;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s = br.readLine().split(" ");
        n = Integer.parseInt(s[0]);
        m = Integer.parseInt(s[1]);
        map = new int[n][m];
        for(int i=0;i<n;i++){
            String input = br.readLine();
            for(int j=0;j<m;j++){
                int b = input.charAt(j)-'0';
                if(b==1){
                    map[i][j]=1;
                }
                else map[i][j]=0;
            }
        }
        bfs(0,0);
        System.out.println(map[n-1][m-1]);
    }
    public static void bfs(int x,int y){
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[] {x,y});
        while(!q.isEmpty()){
            int X = q.peek()[0];
            int Y = q.peek()[1];
            q.poll();
            for(int i=0;i<4;i++){
                int nx = X+dx[i];
                int ny = Y+dy[i];
                if(nx>=0&&nx<n&&ny>=0&&ny<m&&map[nx][ny]==1){
                    q.add(new int[] {nx,ny});
                    map[nx][ny]=map[X][Y]+1;
                }
            }
        }
    }
}