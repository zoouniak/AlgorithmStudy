package TCT;

//오주은 코드

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;

public class 문자열_재정렬 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        ArrayList<Character> left = new ArrayList<>();
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            //int n = s.charAt(i)-'0';
            if (Character.isLetter(s.charAt(i))) {
                // 알파벳 확인해주는 메소드가 잇네
                left.add(s.charAt(i));
            } else {
                //숫자
                sum += s.charAt(i) - '0';
            }
        }
        left.sort(Comparator.naturalOrder());
        for (Character character : left) {
            System.out.print(character);
        }
        System.out.println(sum);
    }
}