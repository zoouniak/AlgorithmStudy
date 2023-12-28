package Programmers;

import java.util.LinkedList;
import java.util.Queue;

public class 올바른괄호 {
    public static void main(String[] args) {
        String s = ")(()";
        Queue<Character> q = new LinkedList<>();
        for(int i=0;i<s.length();i++){
            q.add(s.charAt(i));
        }
        int result=0;
        boolean answer = true;

        while(!q.isEmpty()){
            char c = q.poll();
            if(result<0){
                break;
            }
            if(c=='('){
                result+=1;
            }
            else{
                result-=1;
            }
        }
        if(result==0) answer=true;
        else answer=false;

        System.out.println(answer);
    }
}
