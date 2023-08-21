package BOJ.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class BOJ2470 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] liquid = new int[n];
        String[] input = br.readLine().split(" ");
        for(int i=0;i<n;i++){
            liquid[i] = Integer.parseInt(input[i]);
        }
        Arrays.sort(liquid);

        int left=0;
        int right = n-1;
        int i=0,j=0;
        int result= 2000000001;
        while(left<right){
            int valueAbs = Math.abs(liquid[left]+liquid[right]);
            int value =liquid[left]+liquid[right];
            if(valueAbs==0){
                System.out.println(liquid[left]+" "+liquid[right]);
                return;
            }
            else if(result>valueAbs){
                result=valueAbs;
                i=left; j=right;
            }
            else if(value>0) right--;
            else if(value<0) left++;
        }
        System.out.println(liquid[i]+" "+liquid[j]);
    }
}
