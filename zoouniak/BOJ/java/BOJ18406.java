package BOJ.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ18406 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        int front = 0, back = 0;
        for (int i = 0; i < s.length() / 2; i++) {
            front += s.charAt(i) - '0';
            back += s.charAt(s.length() - i - 1) - '0';
        }
        System.out.println(front == back ? "LUCKY" : "READY");
    }
}