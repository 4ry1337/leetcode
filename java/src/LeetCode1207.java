import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.TreeMap;

public class LeetCode1207 {
    public static boolean uniqueOccurrences(int[] arr) {
        Map<Integer, Integer> map = new TreeMap<>();
        for (int i = 0; i < arr.length; i++) {
            map.put(arr[i], map.getOrDefault(arr[i], 0)+1);
        }
        HashSet<Integer> set = new HashSet<>();
        for (int num : map.values()) {
            if (set.contains(num)) {
                return false;
            }
            set.add(num);
        }
        return true;
    }
}
