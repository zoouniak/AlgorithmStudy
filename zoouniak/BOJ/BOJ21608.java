package BOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class BOJ21608 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int N = n*n;
        STUDENT[] student = new STUDENT[N + 1];
        int[][] s = new int[n + 1][n + 1];
        int[] dx = {1, -1, 0, 0};
        int[] dy = {0, 0, 1, -1};
        for (int i = 0; i < N; i++) {
            String[] input = br.readLine().split(" ");
            int num = Integer.parseInt(input[0]);
            student[num]=new STUDENT();
            for (int j = 0; j < 4; j++) {
                student[num].like.add(Integer.parseInt(input[j + 1]));
            }
            if (i == 0) {
                //첫번째 학생은 항상 (2,2)자리
                student[num].setSeat(2, 2);
                s[2][2] = num;
                continue;
            }
            //끝에서부터 돌면서 좋아하는 사람이 가장 많이 인접한 칸을 찾자
            int maxLike = 0; int maxVacant=0;
            int R=0;int C=0;
            for (int x = n; x > 0; x--) {
                for (int y = n; y > 0; y--) {
                    int k = 0;
                    int vacant=0;
                    if(s[x][y]==0) {
                        for (int z = 0; z < 4; z++) {
                            int nx = x + dx[z];
                            int ny = y + dy[z];
                            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
                                if(student[num].like.contains(s[nx][ny]))
                                //자리 범위 내, 좋아하는 친구가 잇다묜...
                                k++;
                                else if(s[nx][ny]==0)
                                    vacant++;//비어있는 칸
                            }
                            //인접 4칸 다 돌기.
                        }
                        if (maxLike < k ) {
                            maxLike = k;
                            maxVacant=vacant;
                            R=x;C=y;
                        }
                        else if(maxLike==k && vacant>maxVacant){
                            R=x;C=y;
                            maxVacant=vacant;
                        }
                        else if(maxLike ==k && maxVacant==vacant){
                            R=x;C=y;
                        }
                    }
                }
            }
            student[num].setSeat(R,C);
            student[num].setSatisfy(maxLike);
            s[R][C]=num;
        }
        int result=0;
        for(int i=1;i<N+1;i++){
            int k=0;
            int r = student[i].getSeat().r;
            int c = student[i].getSeat().c;
            for(int j=0;j<4;j++) {
                int nx = r + dx[j];
                int ny = c + dy[j];
                if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && student[i].like.contains(s[nx][ny])) {
                    k++;
                }
            }
            switch (k) {
                case 1 -> result += 1;
                case 2 -> result += 10;
                case 3 -> result += 100;
                case 4 -> result += 1000;
            }

        }

        System.out.println(result);
    }

    public static class Seat {
        int r;
        int c;

        public Seat() {
        }
    }

    public static class STUDENT {
        //좋아하는 학생
        ArrayList<Integer> like = new ArrayList<>(4);
        Seat seat=new Seat();
        int satisfy=0;

        public void setSeat(int r, int c) {
            this.seat.r = r;
            this.seat.c = c;
        }

        public Seat getSeat() {
            return seat;
        }

        public void setSatisfy(int satisfy) {
            this.satisfy = satisfy;
        }
    }
}
