import java.util.Arrays;

public class LeetCode324 {
    public static void wiggleSort(int[] nums) {
        System.out.println(Arrays.toString(nums));
        int[] arr = nums.clone();
        Arrays.sort(arr);
        int n = nums.length;
        int i = (n - 1) >> 1, j = n - 1;
        for (int x = 0; x < n; ++x) {
            if (x % 2 == 0) {
                nums[x] = arr[i--];
            } else {
                nums[x] = arr[j--];
            }
        }
        System.out.println(Arrays.toString(nums));
    }
}
