import java.util.ArrayList;
import java.util.List;

public class LeetCode17 {
    private static final char[][] letters = new char[][]{
            {'a', 'b', 'c'}, //2
            {'d', 'e', 'f'}, //3
            {'g', 'h', 'i'}, //4
            {'j', 'k', 'l'}, //5
            {'m', 'n', 'o'}, //6
            {'p', 'q', 'r', 's'}, //7
            {'t', 'u', 'v'}, //8
            {'w', 'x', 'y', 'z'}, //9
    };
    public static List<String> letterCombinations(String digits) {
        List<String> ans = new ArrayList<>();
        letterCombinationsHelper(digits, "", 0, ans);
        return ans;
    }

    private static void letterCombinationsHelper(String digits, String cur, int i, List<String> ans) {
        if(i == digits.length()){
            if(!cur.isEmpty()){
                ans.add(cur);
            }
            return;
        }
        for (int j = 0; j < letters[digits.charAt(i) - '0' - 2].length; j++) {
            letterCombinationsHelper(digits, cur + letters[digits.charAt(i) - '0' - 2][j], i+1, ans);
        }
    }
}
