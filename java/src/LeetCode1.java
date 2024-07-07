import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class LeetCode1 {
    public static int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            map.put(nums[i], i);
            System.out.println(map + " " + map.containsKey(target-nums[i]) + " " + i + " " +map.get(target-nums[i]));
            if(i != map.get(target-nums[i]) && map.containsKey(target-nums[i])){
                return new int[]{map.get(target-nums[i]), i};
            }
        }
        return new int[]{};
    }
}
