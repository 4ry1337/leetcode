import java.util.*;

public class LeetCode2363 {
    public static List<List<Integer>> mergeSimilarItems(int[][] items1, int[][] items2) {
        List<List<Integer>> ans = new ArrayList<>();
        Map<Integer, Integer> map = new TreeMap<>();
        for (int i = 0; i < items1.length; i++) {
            map.put(items1[i][0], items1[i][1]);
        }
        for (int i = 0; i < items2.length; i++) {
            map.put(items2[i][0],map.getOrDefault(items2[i][0], 0) +items2[i][1]);
        }
        map.forEach((key, value) -> {
            ans.add(new ArrayList<>(Arrays.asList(key, value)));
        });
        return ans;
    }
}
