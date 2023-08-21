package BOJ.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;

public class BOJ12018 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s = br.readLine().split(" ");
        int n = Integer.parseInt(s[0]);
        ArrayList<Integer>[] classes = new ArrayList[n];
        int[] need = new int[n];
        int m = Integer.parseInt(s[1]);
        for (int i = 0; i < n; i++) {
            String[] s2 = br.readLine().split(" ");
            //신청인원을 마일리지 순으로 정렬하고 수강인원 l번째 사람과 같은 마일리지를 가지면된다
            int p = Integer.parseInt(s2[0]);
            int l = Integer.parseInt(s2[1]);

            String[] mileage = br.readLine().split(" ");
            classes[i] = new ArrayList<>();
            for (String value : mileage) {
                classes[i].add(Integer.parseInt(value));
            }
            classes[i].sort(Comparator.reverseOrder());
            if(l>p) need[i]=1;
            else{
                need[i]=classes[i].get(l-1);
            }
        }
        Arrays.sort(need);//필요한 마일리지가 적은 거부터
        int result = 0;
        for (int i : need) {
            if (i <= m) {//현재 갖고있는 마일리지보다 작다(수강가능)
                result++;
                m -= i;
            }
        }
        System.out.println(result);
    }

}
