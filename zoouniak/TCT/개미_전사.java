//오주은
package TCT;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 개미_전사 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] storage = new int[n];
        String[] input = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            storage[i] = Integer.parseInt(input[i]);
        }
        int[] result = new int[n];
        result[0] = storage[0];
        result[1] = Math.max(storage[0], storage[1]);
        for (int i = 2; i < n; i++) {
            result[i] = Math.max(result[i - 1], result[i - 1] + storage[i]);
        }
        System.out.println(result[n - 1]);
    }
}