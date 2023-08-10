package BOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ5212 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s = br.readLine().split(" ");
        int r = Integer.parseInt(s[0]);
        int c = Integer.parseInt(s[1]);
        int maxr = -1;
        int maxc = -1;
        int minr = 11;
        int minc = 11;
        char[][] map = new char[r][c];
        char[][] after = new char[r][c];
        for (int i = 0; i < r; i++) {
            String input = br.readLine();
            for (int j = 0; j < c; j++) {
                map[i][j] = input.charAt(j);
                after[i][j] = '.';
            }
        }
        int[] dx = {1, -1, 0, 0};
        int[] dy = {0, 0, 1, -1};
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (map[i][j] == 'X') {
                    //섬 인접한 부분 확인
                    int sea = 0;
                    for (int k = 0; k < 4; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
                            //범위안
                            if (map[nx][ny] == '.') {
                                //바다임
                                sea++;
                            }
                        } else sea++;
                    }
                    if (sea >= 3) after[i][j] = '.';//잠겨버림
                    else {
                        if (maxr < i) maxr = i;
                        if (minr > i) minr = i;
                        if (maxc < j) maxc = j;
                        if (minc > j) minc = j;
                        after[i][j] = 'X';
                    }
                }
            }
        }
        for (int i = minr; i <= maxr; i++) {
            for (int j = minc; j <= maxc; j++) {
                System.out.print(after[i][j]);
            }
            System.out.println();
        }
    }
}
