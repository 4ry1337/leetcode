import java.util.Arrays;

public class LeetCode6890 {
    public static int findValueOfPartition(int[] nums) {
        Arrays.sort(nums);
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < nums.length - 1; i++) {
            min = Math.min(min, Math.abs(nums[i] - nums[i+1])); // partition from 0 to i is num1, and rest in num2
        }
        return min;

    }
}
