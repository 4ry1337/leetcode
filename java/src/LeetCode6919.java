import java.util.Arrays;

public class LeetCode6919 {
    public static boolean checkArray(int[] nums, int k) {
        int n = nums.length;
        for (int i = 0; i < n - k + 1; i++) {
            if(nums[i] >= 0 && nums[i] > 0){
                int temp = nums[i];
                for (int j = 0; j < k; j++) {
                    nums[i+j] -= temp;
                    if(nums[i+j] < 0){
                        return false;
                    }
                }
            }
        }
        return Arrays.equals(nums, new int[n]);
    }
}
