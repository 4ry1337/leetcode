import java.util.ArrayList;
import java.util.List;

public class LeetCode39 {
    static List<List<Integer>> ans;
    public static List<List<Integer>> combinationSum(int[] candidates, int target) {
        ans = new ArrayList<>();
        combinationSumHelper(candidates, target, new ArrayList<>(), 0);
        return ans;
    }
    private static void combinationSumHelper(int[] candidates, int target, List<Integer> cur, int i) {
        if(i == candidates.length){
            List<Integer> temp = new ArrayList<>(cur);
            ans.add(temp);
            return;
        }
        combinationSumHelper(candidates, target, cur, i);
        cur.add(candidates[i]);
        combinationSumHelper(candidates, target-candidates[i], cur, i);
        cur.remove(cur.size()-1);
    }
}
