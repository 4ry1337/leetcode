import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class LeetCode215 {
    public static int findKthLargest(int[] nums, int k) {
        Arrays.sort(nums);
        return nums[nums.length-k];
    }

    public static int findKthLargestAnswer(int[] nums, int k) {
        int min = nums[0];
        int max = nums[0];
        for(int i = 1; i < nums.length; i++){
            if (nums[i] < min){
                min = nums[i];
            }
            if(nums[i] > max){
                max = nums[i];
            }
        }
        int range = max - min + 1;
        int[] countArray = new int[range];
        for(int i = 0; i < nums.length; i++){
            countArray[nums[i]-min]++;
        }
        for(int i = range-1; i >= 0; i--){
            k = k - countArray[i];
            if(k <= 0){
                return i+min;
            }
        }
        return 0;
    }
}
