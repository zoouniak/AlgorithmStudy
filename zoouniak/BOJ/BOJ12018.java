package BOJ;

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
        Class[] classes = new Class[n];
        int[] need = new int[n];
        int m = Integer.parseInt(s[1]);
        for (int i = 0; i < n; i++) {
            String[] s2 = br.readLine().split(" ");
            //신청인원을 마일리지 순으로 정렬하고 수강인원 l번째 사람과 같은 마일리지를 가지면된다
            int p = Integer.parseInt(s2[0]);
            int l = Integer.parseInt(s2[1]);
            classes[i] = new Class(p, l);

            String[] mileage = br.readLine().split(" ");
            for (String value : mileage) classes[i].people.add(Integer.valueOf(value));
            classes[i].sortByMileage();
            need[i] = classes[i].needMileage();//각 클래스마다 필요한 마일리지 구하기
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

    public static class Class {
        int register;
        int limit;

        ArrayList<Integer> people = new ArrayList<>();

        public Class(int register, int limit) {
            this.register = register;
            this.limit = limit;
        }

        public void sortByMileage() {
            people.sort(Comparator.reverseOrder());
        }

        public int needMileage() {
            if (limit > register) return 1;
            return people.get(this.limit - 1);
        }
    }
}
