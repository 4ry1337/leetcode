import java.util.Arrays;

public class LeetCode389 {
    public static char findTheDifference(String s, String t) {
        char s1[] = s.toCharArray();
        char t1[] = t.toCharArray();
        int ans = 0;
        for(int i=0;i<s1.length;i++){
            ans = ans + t1[i] - s1[i];
            System.out.println(ans);
        }
        ans = ans + t1[t1.length - 1];
        return (char)ans;
    }
}
