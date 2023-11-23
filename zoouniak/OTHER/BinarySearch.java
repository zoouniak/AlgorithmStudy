package OTHER;

public class BinarySearch {
    static int[] arr = {1, 3, 5, 7, 8, 10, 20, 35, 99, 100};

    public static void main(String[] args) {
        System.out.println("없는 데이터 탐색");
        System.out.println(binarysearch(0, arr.length - 1, 6));
        System.out.println(binarysearch2(0, arr.length - 1, 6));

        System.out.println("있는 데이터 탐색");
        System.out.println(binarysearch(0, arr.length - 1, 10));
        System.out.println(binarysearch2(0, arr.length - 1, 10));
    }

    /*
    재귀적으로 구현한 이진 탐색.
     */
    public static int binarysearch(int start, int end, int val) {
        if (start <= end) {
            int mid = (start + end) / 2;
            if (arr[mid] == val) {
                return mid;
            } else if (arr[mid] < val) {
                return binarysearch(mid + 1, end, val);
            } else {
                return binarysearch(start, mid - 1, val);
            }
        }
        return -1;
    }

    /*
    반복을 이용해 구현한 이진 탐색.
     */
    public static int binarysearch2(int start, int end, int val) {
        while (start <= end) {
            int mid = (start + end) / 2;
            if (arr[mid] == val) {
                return mid;
            } else if (arr[mid] < val) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }
}
