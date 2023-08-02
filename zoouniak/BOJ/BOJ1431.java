package BOJ;

import java.io.*;
import java.util.Arrays;
import java.util.Comparator;

public class BOJ1431 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        String[] serials = new String[n];
        for (int i = 0; i < n; i++) {
            serials[i] = br.readLine();
        }
        Arrays.sort(serials, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                if (o1.length() != o2.length()) {
                    return o1.length() - o2.length();
                } else {//같을때
                    int sum1 = 0;
                    int sum2 = 0;
                    for (int i = 0; i < o1.length(); i++) {
                        char c1 = o1.charAt(i);
                        char c2 = o2.charAt(i);
                        if (Character.isDigit(c1)) {
                            sum1 += Integer.parseInt(String.valueOf(c1));
                        }
                        if (Character.isDigit(c2)) {
                            sum2 += Integer.parseInt(String.valueOf(c2));
                        }
                    }
                    int result = sum1 - sum2;
                    if (result == 0) {
                        return o1.compareTo(o2);
                    } else return result;
                }
            }
        });
        for (String s : serials) {
            bw.write(s + "\n");
        }
        bw.flush();
    }
}