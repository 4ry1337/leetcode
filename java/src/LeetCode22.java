import java.util.ArrayList;
import java.util.List;

public class LeetCode22 {
    static List<String> ans;
    public static List<String> generateParenthesis(int n) {
        ans = new ArrayList<>();
        generateParenthesisHelper("", n, 0, 0);
        return ans;
    }

    public static void generateParenthesisHelper(String s, int n, int r, int l) {
        if(s.length() > 2*n){
            return;
        }
        if (r - l == 0 && s.length() == 2 * n) {
            ans.add(s);
            return;
        }
        if (r == n) {
            int remaining = n - l;
            for (int i = 0; i < remaining; i++) {
                s += ")";
            }
            ans.add(s);
            return;
        }
        if (r - l == 0) {
            s += "(";
            generateParenthesisHelper(s, n, r + 1, l);
            s = s.substring(0, s.length() - 1);
        }
        if (0 < r - l && r - l < n) {
            s += "(";
            generateParenthesisHelper(s, n, r + 1, l);
            s = s.substring(0, s.length() - 1);
            s += ")";
            generateParenthesisHelper(s, n, r, l+1);
            s = s.substring(0, s.length() - 1);
        }
    }
}
