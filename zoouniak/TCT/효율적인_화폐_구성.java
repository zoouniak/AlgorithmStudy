package TCT;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class 효율적인_화폐_구성 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s = br.readLine().split(" ");
        int n = Integer.parseInt(s[0]);
        int m = Integer.parseInt(s[1]);
        int[] money = new int[n];
        for (int i = 0; i < n; i++) {
            money[i] = Integer.parseInt(br.readLine());
        }
        /*Arrays.sort(money);
        int min = money[0];
        int[] result = new int[10000];
        for (int i = 0; i < n; i++) {
            result[money[i]] = 1;
        }
        for (int i = min + 1; i <= m; i++) {
            int less = 10001;
            if (result[i]==1) continue;
            for (int j = 0; j < n; j++) {
                if (i>money[j]&&result[i - money[j]] != 0) {
                   less= Math.min(result[i - money[j]], less);
                }
            }
            result[i] = less >=10001?-1:less+1;
        }

        System.out.println(result[m]);*/
        int[] result = new int[m + 1];
        Arrays.fill(result, 10001);

        result[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = money[i]; j <= m; j++) {
                if (result[j - money[i]] != 10001) {
                    result[j] = Math.min(result[j], result[j - money[i]] + 1);
                }
            }
        }
        System.out.println(result[m] == 10001 ? -1 : result[m]);
    }
}
