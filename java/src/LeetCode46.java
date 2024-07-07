import java.util.ArrayList;
import java.util.List;

public class LeetCode46 {
    public static List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> cur = new ArrayList<>();
        boolean[] used = new boolean[nums.length];
        permuteHelper(nums, used, ans, cur);
        return ans;
    }
    public static void permuteHelper(int[] nums, boolean[] used, List<List<Integer>> ans, List<Integer> cur) {
        if(cur.size() == nums.length){
            List<Integer> temp = new ArrayList<>(cur);
            ans.add(temp);
            return;
        }
        for (int i = 0; i< nums.length; i++) {
            if(!used[i]){
                used[i] = true;
                cur.add(nums[i]);
                permuteHelper(nums, used, ans, cur);
                cur.remove(cur.size()-1);
                used[i] = false;
            }
        }
    }
}
