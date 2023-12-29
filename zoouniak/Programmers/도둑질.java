package Programmers;

public class 도둑질 {
    class Solution {
        public int solution(int[] money) {
            int[] answers = new int[money.length];
            int[] noFirstHouse = new int[money.length];
            answers[0] = money[0];
            noFirstHouse[0] = 0;
            answers[1] = Math.max(money[0], money[1]);
            noFirstHouse[1] = money[1];
            for (int i = 2; i < money.length; i++) {
                if (i == money.length - 1) {
                    //마지막 집이 선택되면 첫번째 집은 선택되지 않아야함
                    answers[i] = Math.max(noFirstHouse[i - 2] + money[i], answers[i - 1]);
                } else {
                    answers[i] = Math.max(answers[i - 2] + money[i], answers[i - 1]);
                    noFirstHouse[i] = Math.max(noFirstHouse[i - 2] + money[i], noFirstHouse[i - 1]); //첫번째 집 선택안하는 경우
                }
            }
            return answers[money.length - 1];
        }
    }
}
