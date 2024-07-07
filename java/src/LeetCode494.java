public class LeetCode494 {
    static int count;
    public static int findTargetSumWays(int[] nums, int target) {
        count = 0;
        findTargetSumWaysHelper(nums, target, 0);
        return count;
    }
    private static void findTargetSumWaysHelper(int[] nums, int target, int i) {
        if(i >= nums.length){
            if(target == 0){
                count++;
            }
            return;
        }
        findTargetSumWaysHelper(nums, target - nums[i], i+1);
        findTargetSumWaysHelper(nums, target + nums[i], i+1);
    }
}
