public class LeetCode55 {
    public static boolean canJump(int[] nums) {
        int[] arr = new int[nums.length];
        arr[0] = 1;
        for (int i = 0; i < nums.length; i++) {
            if(arr[i] == 1){
                for(int j = 0; j <= nums[i]; j++) {
                    arr[i+j] = 1;
                    if(i+j == nums.length - 1){
                        break;
                    }
                }
            }
        }
        return arr[nums.length - 1] == 1;
    }
}
