import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class LeetCode39 {
    static List<List<Integer>> ans;
    public static List<List<Integer>> combinationSum(int[] candidates, int target) {
        ans = new ArrayList<>();
        combinationSumHelper(candidates, target, new ArrayList<>());
        return ans;
    }
    private static void combinationSumHelper(int[] candidates, int target, List<Integer> cur) {
        if(target <= 0){
            if(target == 0){
                List<Integer> temp = new ArrayList<>(cur);
                Collections.sort(temp);
                if(!ans.contains(temp)){
                    ans.add(temp);
                }
            }
            return;
        }
        for (int i = 0; i < candidates.length; i++) {
            cur.add(candidates[i]);
            combinationSumHelper(candidates, target-candidates[i], cur);
            cur.remove(cur.size()-1);
        }
    }
}
