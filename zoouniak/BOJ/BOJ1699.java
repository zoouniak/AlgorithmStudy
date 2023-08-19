package BOJ;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class BOJ1699 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        int[] dp = new int[n+1];
        dp[1]=1;
        for (int i = 1; i <= n; i++) {
            int min=1000001;
            for(int j=1;j<=Math.floor(Math.sqrt(i));j++){
                if(j*j==i){
                    min=1;break;
                }
                if(min>dp[i-(j*j)]+1) min=dp[i-(j*j)]+1;
            }
            dp[i]=min;
        }
        System.out.println(dp[n]);

    }
}