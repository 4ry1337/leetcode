import java.util.Arrays;

public class LeetCode242 {
    public static boolean isAnagram(String s, String t) {
        char[] s1 = s.toCharArray();
        Arrays.sort(s1);
        char[] t1 = t.toCharArray();
        Arrays.sort(t1);
        return new String(s1).equals(new String(t1));
    }
}
