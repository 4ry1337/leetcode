import java.util.*;

public class Main {
    public static void main(String[] args){
        long start1 = System.currentTimeMillis();
//        System.out.println(LeetCode6919.checkArray(new int[]{60,72,87,89,63,52,64,62,31,37,57,83,98,94,92,77,94,91,87,100,91,91,50,26}, 4));
//        System.out.println(LeetCode6919.checkArray(new int[]{60,78,96,97,97,97,49,7,97,97,97,99,97,97,97,97,85,97,97,97,37,5,1}, 20));
//        System.out.println(maxArrayValue(new int[]{2, 3, 7, 9, 3}));
//        System.out.println(maxIncreasingGroups(new ArrayList<>(Arrays.asList(2, 1, 2))));
//        System.out.println(LeetCode6919.checkArray(new int[]{2, 2, 2}, 3));
        /*List<Integer> arr = new ArrayList<>();
        arr.add(2);
        arr.add(2);
        arr.add(1);
        arr.add(2);
        arr.add(2);
        Integer[] a = arr.toArray(new Integer[0]);
        for (int i = 0; i < a.length / 2; i++) {
            if(a[i] != a[a.length -1 - i]){

            }
        }*/
        /*int[] arr = new int[10];
        Map<Integer, Integer> hm = new HashMap<>();
        hm.put(arr[0], hm.getOrDefault(arr[0], 0) + 1);
        hm.size();
        int[] copy = Arrays.copyOfRange(arr, 1, 9);
        System.out.println(Arrays.toString(copy));*/
        System.out.println(LeetCode1071.gcdOfStrings("ABCABC", "ABC"));
        long end1 = System.currentTimeMillis();
        System.out.println((end1-start1) + " ms");
    }
    /*public static List<String> splitWordsBySeparator(List<String> words, char separator) {
        List<String> ans = new ArrayList<String>();
        String substring = "";
        for (String word : words) {
            for (int j = 0; j < word.length(); j++) {
                if (word.charAt(j) == separator) {
                    if(!substring.isEmpty()){
                        ans.add(substring);
                    }
                    substring = "";
                } else {
                    substring += word.charAt(j);
                }
            }
            if(!substring.isEmpty()){
                ans.add(substring);
            }
            substring = "";
        }
        return ans;
    }*/

    /*public static long maxArrayValue(int[] nums) {
        long ans = nums[nums.length - 1];
        for(int i = nums.length - 2; i >= 0 ; i--){
            if(nums[i] <= ans){
                ans += nums[i];
            } else {
                ans = Math.max(ans, nums[i]);
            }
        }
        return ans;
    }*/

    /*public static int maxIncreasingGroups(List<Integer> usageLimits) {
        int ans = 0;
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (Integer usageLimit : usageLimits) {
            map.put(usageLimit, map.getOrDefault(map.get(usageLimit), 0) + 1);
        }
        while(map.size() >= ans){
            for (int i = 0; i < ans; i++) {
                if(map.get(map.size() - i) - 1 == 0){
                    map.remove(map.size() - i);
                } else {
                    map.put(map.size() - i, map.get(map.size() - i) - 1);
                    map.put(map.size() - i-1, map.get(map.size() - i -1) + 1);
                }
            }
            ans++;
        }
        return ans;
    }*/
    /*private void traverse(TreeNode root, List<Integer> arr){
        if(root == null){
            return;
        }
        traverse(root.left, arr);
        arr.add(root.val);
        traverse(root.right, arr);
    }*/
}