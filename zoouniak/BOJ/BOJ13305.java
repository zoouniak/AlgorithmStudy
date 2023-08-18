package BOJ;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class BOJ13305 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Long[] distance = new Long[n];
        Long[] price = new Long[n];
        String[] s = br.readLine().split(" ");
        for(int i=1;i<n;i++){//distance[i]== i-1에서 i까지 도로 길이
            distance[i]=Long.parseLong(s[i-1]);
        }
        s=br.readLine().split(" ");

        for(int i=0;i<n;i++){//price[i] == i도시 리터 당 가격
            price[i]=Long.parseLong(s[i]);
        }
        Long min = price[0];
        Long cost =0L;
        for(int i=0;i<n-1;i++){
            if(min>price[i])
                min = price[i];
             cost +=(distance[i+1])*min;
        }
        System.out.print(cost);
    }
}
