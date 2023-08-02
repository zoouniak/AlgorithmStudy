package TCT;

import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;

public class 단어_정렬 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        String[] array = new String[n];
        HashSet<String> set = new HashSet<>();
        for (int i = 0; i < n; i++) {
            set.add(br.readLine());
        }
        array = set.toArray(new String[0]);
        Arrays.sort(array, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                if (o1.length() > o2.length())
                    return 1;
                else if (o1.length() < o2.length())
                    return -1;
                else {//길이 같을 때
                    for (int i = 0; i < o1.length(); i++) {
                        if (o1.charAt(i) > o2.charAt(i))
                            return 1;
                        else if (o1.charAt(i) < o2.charAt(i)) return -1;
                    }
                    o1.compareTo(o2);
                }
                return 0;
            }
        });
        for (String s : array) {
            System.out.println(s);
        }
        bw.flush();
    }
}