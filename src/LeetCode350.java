import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class LeetCode350 {
    public static int[] intersect(int[] nums1, int[] nums2) {
        List<Integer> result = new ArrayList<>();
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        int i = 0, j = 0;
        while(i < nums1.length && j < nums2.length) {
            if(nums1[i] == nums2[j]){
                result.add(nums1[i]);
                i++;
                j++;
            } else if(nums1[i] < nums2[j]){
                i++;
            } else {
                j++;
            }
        }

        int[] ans = new int[result.size()];
        for (int k = 0; k < result.size(); k++) {
            ans[k] = result.get(k);
        }
        return ans;
    }
}
