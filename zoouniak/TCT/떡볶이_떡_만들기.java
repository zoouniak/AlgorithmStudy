package TCT;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class 떡볶이_떡_만들기 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);

        String[] s = br.readLine().split(" ");
        int[] rice = new int[n];
        for(int i=0;i<n;i++){
            rice[i]= Integer.parseInt(s[i]);
        }
        Arrays.sort(rice);
        int start = 0;
        int end  = rice[n-1];

        int result=0;
        while(start<=end){
            int mid = (start+end)/2;
            int sum =0;
            for (int r : rice) {
                if(r>mid)
                    sum+=r-mid;
            }
            if(sum>=m){
                result=mid;
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        System.out.println(result);

    }
}
