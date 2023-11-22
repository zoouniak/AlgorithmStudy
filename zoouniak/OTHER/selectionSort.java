package OTHER;

public class selectionSort {
    public static void main(String[] args) {
        int[] arr = {5, 3, 2, 7, 1};
        for (int i = 0; i < arr.length - 1; i++) {
            int min = Integer.MAX_VALUE;
            int index = 0;
            for (int j = i; j < arr.length; j++) { //배열 중 가장 작은 원소 구하기
                if (min > arr[j]) {
                    min = arr[j];
                    index = j;
                }
            }
            swap(arr, i, index);
        }
        for (int i : arr) {
            System.out.print(i + " ");
        }
    }

    public static void swap(int[] arr, int a, int b) { //가장 작은 원소와 swap
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
}
