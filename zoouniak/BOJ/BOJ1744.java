package BOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class BOJ1744 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        ArrayList<Integer> m = new ArrayList<>();
        ArrayList<Integer> p = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int x = Integer.parseInt(br.readLine());
            if (x >= 0)
                p.add(x);
            else m.add(x);
        }

        Collections.sort(p);
        Collections.sort(m);
        int sum = 0;
        for (int i = 0; i < m.size() - 1; i += 2) {
            int tie = m.get(i) * m.get(i + 1);
            sum += tie;
        }
        if (m.size() % 2 != 0) {
            if (p.size() != 0 && p.get(0) == 0) {
                int tie = m.get(m.size() - 1) * p.get(0);
                sum += tie;
                p.remove(0);
            } else sum += m.get(m.size() - 1);
        }
        //음수에 대한 처리


        for (int i = p.size() - 1; i > 0; i -= 2) {
            if (p.get(i) == 1 || p.get(i) == 0 || p.get(i - 1) == 1 || p.get(i - 1) == 0) {
                sum += p.get(i) + p.get(i - 1);
            } else {
                int tie = p.get(i) * p.get(i - 1);
                sum += tie;
            }
        }
        if (p.size() % 2 != 0) {
            sum += p.get(0);
        }
        //양수에 대한 처리
        System.out.println(sum);
    }
}