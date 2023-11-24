package OTHER;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.PriorityQueue;
import java.util.Scanner;

/*
두 개의 문자열 S1과 S2를 합친 새로운 문자열을 생성하는 알고리즘 A를 가정하라
A는 S1의 끝까지 가서 S2의 문자들을 하나씩 S1에 추가한다.
따라서 A의 비용은 (S1의 길이 + S2의 길이)로 정의된다. 여러 개의 문자열이 주어질 떄, 알고리즙 A를
차례대로 이용하여 순서에 상관없이 모든 문자열을 하나의 문자열로 합치고자 한다. 순서가 상관없다는 의미는
{"aa", "bbb", "ccc"}가 주어질 때, 합친 문자열이 "aabbbccc"거나 "ccccaabbb"혹은 "bbbccccaa" 등 어떤
문자열이 되어도 상관없다는 뜻이다. 단 "aabbbccc"를 생성하는 비용은 (2+3) + (5+4) = 14이지만 "ccccaabbb"를 생성하는
비용은 (4+2) + (6+3) =15로 차이가 난다. n 개의 문자열의 길이가 주어질 때, 이 문자열을 합치는 최소 비용을 구하시오.

테스트케이스의 수
문자열의 수 n(0<n<=10000)
n개 문자열의 길이

 */
public class HuffmanTree {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("D://코테 준비//zoouniak//OTHER//sol3.txt"));
        int t = Integer.parseInt(sc.nextLine());
        for (int x = 0; x < t; x++) {
            int n = Integer.parseInt(sc.nextLine());
            String[] s = sc.nextLine().split(" ");
            PriorityQueue<Integer> pq = new PriorityQueue();
            for (String num : s) {
                pq.add(Integer.valueOf(num));
            }
            int cost = 0;
            while (pq.size() > 1) {
                int a = pq.poll();
                int b = pq.poll();
                cost += (a + b);
                pq.add(a + b);
            }
            System.out.println(cost);
        }
    }
}
