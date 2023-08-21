package BOJ.java;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class BOJ1699 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        int[] dp = new int[n+1];
       for(int i=1;i<=n;i++){
           dp[i]=i;
       }
        dp[1]=1;
        for (int i = 1; i <= n; i++) {
            for(int j=1;j<=Math.floor(Math.sqrt(i));j++){
               dp[i]= Math.min(dp[i],dp[i-(j*j)]+1);
            }
        }
        System.out.println(dp[n]);

    }
}