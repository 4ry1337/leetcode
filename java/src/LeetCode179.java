import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;

public class LeetCode179 {
    public static String largestNumber(int[] nums) {
        String[] numsAsString = new String[nums.length];
        int count = 0;
        for (int i = 0; i < nums.length; i++) {
            numsAsString[i]= String.valueOf(nums[i]);
        }
        Arrays.sort(numsAsString, Collections.reverseOrder());
        if(numsAsString[0].equals("0") && numsAsString[numsAsString.length - 1].equals("0")){
            return "0";
        }
        System.out.println(Arrays.toString(numsAsString));
        for(int i=0; i< numsAsString.length-1; i++) {
            int l = Math.min(numsAsString[i].length(),numsAsString[i+1].length());
            if(numsAsString[i].substring(0,l).equals(numsAsString[i+1].substring(0,l))) {
                String s1 = numsAsString[i] + numsAsString[i+1];
                String s2 = numsAsString[i+1] + numsAsString[i];
                System.out.println(s1 + " " + s2);
                for (int j = 0; j < s1.length(); j++){
                    System.out.print(s1.charAt(j) + " " + s2.charAt(j));
                    System.out.println();
                    if(s2.charAt(j) > s1.charAt(j)){
                        String t=numsAsString[i];
                        numsAsString[i]=numsAsString[i+1];
                        numsAsString[i+1]=t;
                        i=-1;
                        System.out.println("swap");
                        break;
                    } else if(s2.charAt(j) < s1.charAt(j)) {
                        System.out.println("not swap");
                        break;
                    }
                }
            }
        }
        System.out.println(Arrays.toString(numsAsString));
        String res = "";
        for (int i = 0; i < numsAsString.length; i++) {
            res += numsAsString[i];
        }
        return res;
    }
}
