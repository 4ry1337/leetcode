import java.util.ArrayList;

public class LeetCode60 {
    //TODO: https://leetcode.com/problems/permutation-sequence/
    static int count;
    static String ans = "";
    public static String getPermutation(int n, int k) {
        boolean[] vis = new boolean[n];
        count = k;
        getPermutationHelper("", n, vis);
        return ans;
    }

    public static void getPermutationHelper(String s, int n, boolean[] vis) {
        if(s.length() == n){
            count--;
            if(count==0){
                ans = s;
            }
            return;
        }
        for (int i = 0; i<n; i++) {
            if(!vis[i]){
                vis[i] = true;
                s+=(i+1);
                getPermutationHelper(s, n, vis);
                s = s.substring(0, s.length()-1);
                vis[i] = false;
            }
        }
    }
}
