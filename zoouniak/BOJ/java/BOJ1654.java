package BOJ.java;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class BOJ1654 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int k = Integer.parseInt(input[1]);
        int[] lan = new int[n];
        for(int i=0;i<n;i++){
            lan[i]= Integer.parseInt(br.readLine());
        }
        Arrays.sort(lan);
        //자료형 long사용
        long start = 1;
        long end = lan[n-1];
        long result=0;
        while(start<=end){
            long mid = (start+end)/2;
            long sum=0;
            for(int i=0;i<n;i++){
                sum+=(lan[i]/mid);
            }
            if(sum>=k){
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