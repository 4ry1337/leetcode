import java.util.ArrayList;
import java.util.List;

public class LeetCode78 {
    static List<List<Integer>> ans;
    public static List<List<Integer>> subsets(int[] nums) {
        ans = new ArrayList<>();
        subsetsHelper(nums, 0, new ArrayList<>());
        return ans;
    }

    public static void subsetsHelper(int[] nums, int i, List<Integer> cur) {
        if(i == nums.length){
            List<Integer> temp = new ArrayList<>(cur);
            ans.add(temp);
            return;
        }
        subsetsHelper(nums, i+1, cur);
        cur.add(nums[i]);
        subsetsHelper(nums, i+1, cur);
        cur.remove(cur.size()-1);
    }
}
