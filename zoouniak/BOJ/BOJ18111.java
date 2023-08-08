package BOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ18111 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s = br.readLine().split(" ");
        int n = Integer.parseInt(s[0]);
        int m = Integer.parseInt(s[1]);
        int[][] land = new int[n][m];
        int b = Integer.parseInt(s[2]);
        int time = 2147483647;
        int height = 0;
        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");
            for (int j = 0; j < m; j++) {
                land[i][j] = Integer.parseInt(input[j]);
            }
        }
        for (int i = 0; i <= 256; i++) {
            int result = 0;
            int needblock = 0;
            int plus = 0;//뺀 블록들의 합을 저장
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < m; y++) {
                    if (land[x][y] > i) {//내가 더 높다. 빼야함 2초
                        plus += land[x][y] - i;
                        result += 2 * (land[x][y] - i);

                    } else if (land[x][y] < i) {//내가 더 낮다. 쌓아야함 1초
                        int minus = (i - land[x][y]);
                        needblock += minus;
                        result += minus;
                    }
                }
            }
            if (b + plus >= needblock) {//인벤토리에 필요한 만큼의 블록이 있고,
                if (result < time) {//더 짧은 시간이다
                    time = result;//더 짧은 시간으로
                    height = i;
                } else if (result == time) {//시간이 같다
                    height = i;//더 긴 높이를 채택
                }
            }
        }
        System.out.print(time + " " + height);
    }
}