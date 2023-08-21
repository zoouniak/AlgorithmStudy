package TCT.java;//오주은 코드

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class 숫자_카드_게임 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);
        int[][] arr = new int[n][m];
        int[] result = new int[n];
        for (int i = 0; i < n; i++) {
            String[] nums = br.readLine().split(" ");
            for (int j = 0; j < m; j++) {
                arr[i][j] = Integer.parseInt(nums[j]);
            }
            Arrays.sort(arr[i]);
            result[i] = arr[i][0];
        }
        Arrays.sort(result);
        System.out.println(result[n - 1]);
    }
}

/*굳이 배열을 안쓰고 Math.min을 사용해 그때 그때마다 작은 걸 min값으로 넣고 그 min값 중 가장 큰 max를 구하면 된다
그러려면 Scanner를 사용해야한다.

    Scanner sc = new Scanner(System.in);
    int result=0;
 for(int i=0;i<n;i++){
        int min=1000001;
        for(int j=0;j<m;j++){
        int x = sc.nextInt();
        min=Math.min(min,x);
        }
        result=Math.max(result,min);
        }
*/