public class LeetCode2574 {
    public static int[] leftRightDifference(int[] nums) {
        int [] ans = new int[nums.length];
        int sum =0;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            ans[i] = sum;
        }
        sum = 0;
        for (int i = nums.length - 1; i >= 0; i--) {
            sum += nums[i];
            ans[i] = Math.abs(ans[i] - sum);
        }
        return ans;
    }
}
