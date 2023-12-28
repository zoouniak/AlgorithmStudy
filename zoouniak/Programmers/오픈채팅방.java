package Programmers;

import java.util.ArrayList;
import java.util.HashMap;

public class 오픈채팅방 {
    public static void main(String[] args) {
        String[] record = {"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"};
        ArrayList<String> list = new ArrayList<>();
        HashMap<String,String> map = new HashMap<>();
        for(String r : record){
            String[] input = r.split(" ");
            if(r.charAt(0)=='E'){
                list.add("E "+input[1]);
                map.put(input[1],input[2]);
            }
            else if(r.charAt(0)=='L'){
                list.add("L "+input[1]);
            }
            else{
                //change
                map.put(input[1],input[2]);
            }
        }
        String[] answer = new String[list.size()];
        for(int i=0;i<list.size();i++){
            String[] result =list.get(i).split(" ");
            System.out.println(result[0]);
            String nickname = map.get(result[1]);
            if(result[0].equals("E")){
                answer[i] = nickname+"님이 들어왔습니다.";
            }
            else{
                answer[i]= nickname+"님이 나갔습니다.";
            }
        }
        for (String s : answer) {
            System.out.println(s);
        }
    }
}
