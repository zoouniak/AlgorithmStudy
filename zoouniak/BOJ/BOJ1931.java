package BOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ1931 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        ArrayList<Meeting> meetings = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");
            meetings.add(new Meeting(Integer.parseInt(input[0]), Integer.parseInt(input[1])));
        }
        Collections.sort(meetings, new Comparator<Meeting>() {
            @Override
            public int compare(Meeting o1, Meeting o2) {
                if (o1.start == o2.start) {
                    //끝 시간이 빠를수록 앞으로
                    return o1.end-o2.end;
                } else {
                    return o1.start-o2.start;
                }
            }
        });
        //회의를 안 겹치게 구성
        Stack<Meeting> toMax = new Stack<>();
        toMax.add(meetings.get(0));
        for (int i = 1; i < n; i++) {
            //스택에서 하나 꺼내서 검사?
            Meeting compare = toMax.peek();
            Meeting meet = meetings.get(i);
            if (meet.start >= compare.start && meet.start < compare.end) {//회의시간 사이에 잇는 회의인 경우
                if (meet.end < compare.end) {
                    //더 짧은 회의 일경우
                    toMax.pop();
                    toMax.add(meet);
                    //회의시간 같으면 시작시간 빠른거 선택하는 게 굿
                }
            } else toMax.add(meet);
        }
        System.out.print(toMax.size());
    }

    public static class Meeting {
        private int start;
        private int end;

        public Meeting(int start, int end) {
            this.start = start;
            this.end = end;
        }
    }
}
