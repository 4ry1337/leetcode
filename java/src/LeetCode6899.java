public class LeetCode6899 {
    public static int maximumJumps(int[] nums, int target) {
        return backtrack(nums, target, -1, 0, 0);
    }

    public static int backtrack(int[] nums, int target, int max, int i, int j) {
        if(i == nums.length){
            return max;
        }
        if(j == nums.length){
            return backtrack(nums, target, max, i+1, i+1);
        }
        if(target >= Math.abs(nums[i] - nums[j]) && i != j){
            return Math.max(backtrack(nums, target, max+1, i, j+1), backtrack(nums, target, max, i, j+1));
        }
        return Math.max(backtrack(nums, target, max, i, j+1), max);
    }
}
