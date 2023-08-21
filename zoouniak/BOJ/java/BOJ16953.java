package BOJ.java;

import java.io.*;
public class BOJ16953 {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s = br.readLine().split(" ");
        int a = Integer.parseInt(s[0]);
        int b = Integer.parseInt(s[1]);
        int cnt=1;
        while(a<b){
            if(b%10==1){
                b=(b/10);
                cnt++;
            }
            else if((b%10)%2==0){
                b=(b/2);
                cnt++;
            }
            else{
                System.out.print(-1);
                return;
            }
        }
        System.out.print((a==b)?cnt:-1);
    }
}