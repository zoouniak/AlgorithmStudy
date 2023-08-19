package BOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ1541 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        int sum = 0;
        String num = "0";
        boolean minus = false;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != '+' && s.charAt(i) != '-') {
                num += s.charAt(i);
            }
            if (s.charAt(i) == '+'||i==s.length()-1||s.charAt(i)=='-') {
                if (minus) sum -= Integer.parseInt(num);
                else sum += Integer.parseInt(num);
                num = "";
                if(s.charAt(i)=='-') minus=true;
            }

        }
        System.out.println(sum);

    }
}
