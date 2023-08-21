package BOJ.java;
import java.io.*;
public class BOJ2193 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Binary[] dp = new Binary[91];
        dp[1]= new Binary(1L,0L,1L);
        dp[2]=new Binary(0L,1L,1L);
        for(int i=3;i<=n;i++){
            dp[i]=new Binary();
            dp[i].count = (dp[i-1].zero*2)+dp[i-1].one;
            dp[i].zero = dp[i-1].zero+dp[i-1].one;
            dp[i].one=dp[i-1].zero;
        }
        System.out.println(dp[n].count);
    }
    public static class Binary {
        long zero;
        long one;
        long count;
        public Binary(){}
        public Binary(long one,long zero,long count){
            this.one=one;
            this.zero=zero;
            this.count=count;
        }
    }
}
