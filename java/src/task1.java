import java.util.ArrayList;
import java.util.List;

public class task1 {
    public static int longestAlternatingSubarray(int[] nums, int threshold) {
        int maxLength = 0;
        int length = 0;
        int prevRem = -1;
        int firstEven = -1;
        List<Integer> more = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            if(nums[i] > threshold){
                more.add(i);
            }
        }
        for (int i = 0; i < nums.length; i++) {
            if(firstEven < 0 && nums[i]%2 == 0){
                firstEven = i;
            }
            System.out.print(nums[i] + " " + prevRem + " " + (prevRem != nums[i] % 2) + " ");
            if(more.contains(i)){
                maxLength = Math.max(maxLength, length);
                length = 0;
                firstEven = -1;
                prevRem = -1;
            } else {
                if(firstEven > -1){
                    if (prevRem != nums[i] % 2) {
                        prevRem = nums[i] % 2;
                        length = i - firstEven + 1;
                        maxLength = Math.max(maxLength, length);
                    } else {
                        if(nums[i] % 2 == 0){
                            firstEven = i;
                        } else {
                            firstEven = -1;
                        }
                    }
                }
            }
            //System.out.println(firstEven + " " + length + " " + maxLength);
        }
        //System.out.println();
        return maxLength;
    }
}
