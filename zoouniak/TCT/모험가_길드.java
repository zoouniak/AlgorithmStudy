package TCT;

//오주은 코드

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

public class 모험가_길드 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] nums = br.readLine().split(" ");
        //int[] arr = new int[n];
        PriorityQueue<Integer> q = new PriorityQueue<>(n);
        for (int i = 0; i < n; i++)
            q.add(Integer.valueOf(nums[i]));
        int cnt = 0;
        while (true) {
            int x = q.poll();
            int num = 0;
            while (x > 1) {
                if (q.isEmpty()) {
                    System.out.println(cnt);
                    return;
                }
                num++;
                x = q.poll();
                x -= num;
            }
            if (q.isEmpty()) break;
            cnt++;
        }
        System.out.println(cnt);
    }
}
/*public class 모험가길드 {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n =sc.nextInt();
        int[] arr = new int[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        Arrays.sort(arr);
        int cnt=0;
        int result=0;
        for(int i=0;i<n;i++){//공포도를 낮은 것부터 확인하
            cnt++;
            if(cnt>=arr[i]){//현재 그룹에 포함된 모험가의 수가 현재 공포도 이상이라면 그룹생성
                result++;
                cnt=0; //모험가 수 초기화
            }
        }
        System.out.println(result);
    }
}*/