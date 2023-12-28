package Programmers;

import java.util.ArrayList;
import java.util.Comparator;

public class 모의고사 {
    public static void main(String[] args) {
        int[] answers = new int[10000]; //args
        ArrayList<Integer> list = new ArrayList<>();
        int[] p1 = {1, 2, 3, 4, 5};
        int[] p2 = {2, 1, 2, 3, 2, 4, 2, 5};
        int[] p3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
        int[] count = new int[3];
        for (int i = 0; i < answers.length; i++) {
            if (answers[i] == p1[i % p1.length]) count[0]++;
            if (answers[i] == p2[i % p2.length]) count[1]++;
            if (answers[i] == p3[i % p3.length]) count[2]++;
        }
        int max = Math.max(count[0], Math.max(count[1], count[2]));
        for (int i = 0; i < 3; i++) {
            if (count[i] == max) list.add(i + 1);
        }

        list.sort(Comparator.naturalOrder());
        list.stream().mapToInt(Integer::intValue).toArray();
    }
}
