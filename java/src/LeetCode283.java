public class LeetCode283 {
    public static void moveZeroes(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            if(nums[i] == 0){
                for (int j = i; j < nums.length; j++) {
                    if(nums[j] != 0){
                        nums[i] = nums[j];
                        nums[j] = 0;
                        break;
                    }
                }
            }
        }
    }

    public static void moveZeroesAnswer(int[] nums) {
        int point = 0;
        for (int i = 0; i < nums.length; i++) {
            if(nums[i] != 0){
                int temp = nums[point];
                nums[point] = nums[i];
                nums[i] = temp;
                point++;
            }
        }
    }
}
