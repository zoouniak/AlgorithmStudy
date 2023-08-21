package BOJ.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class BOJ11399 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] time = new int[n];
        String[] input = br.readLine().split(" ");
        for(int i=0;i<n;i++){
            time[i]= Integer.parseInt(input[i]);
        }
        //필요시간이 적은 사람부터 인출하자!
        Arrays.sort(time);
        for(int i=0;i<n-1;i++){
            //기다린 시간+ 내 필요시간
            time[i+1]+=time[i];
        }
        int result=0;
        for (int i : time) {
            result+=i;
        }
        System.out.print(result);
    }
}
