import java.util.ArrayList;
import java.util.List;

public class LeetCode2708 {
    public static long maxStrength(int[] nums) {
        return maxStrengthHelper(nums, new ArrayList<>(), 0);
    }

    private static long maxStrengthHelper(int[] nums, List<Integer> ans, int i) {
        if(i == nums.length){
            if(ans.isEmpty()){
                return Integer.MIN_VALUE;
            }
            long max = ans.get(0);
            for (int j = 1; j < ans.size(); j++) {
                max *= ans.get(j);
            }
            return max;
        }
        long max1 = maxStrengthHelper(nums, ans, i+1);
        ans.add(nums[i]);
        long max2 = maxStrengthHelper(nums, ans, i+1);
        ans.remove(ans.size()-1);
        return Math.max(max1, max2);
    }
}
