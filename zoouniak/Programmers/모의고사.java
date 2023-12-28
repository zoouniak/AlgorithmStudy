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
        int c1 = 0;
        int c2 = 0;
        int c3 = 0;
        for (int i = 0; i < answers.length; i++) {
            if (answers[i] == p1[i % 5]) c1++;
            if (answers[i] == p2[i % 8]) c2++;
            if (answers[i] == p3[i % 10]) c3++;
        }
        int max = Math.max(c1, Math.max(c2, c3));
        if (c1 == max) list.add(1);
        if (c2 == max) list.add(2);
        if (c3 == max) list.add(3);

        list.sort(Comparator.naturalOrder());
        list.stream().mapToInt(Integer::intValue).toArray();
    }
}
