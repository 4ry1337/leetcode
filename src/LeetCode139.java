import java.util.List;

public class LeetCode139 {
    public static boolean wordBreak(String s, List<String> wordDict) {
        int[] a = new int[s.length()+1];
        a[0] = 1;
        for (int i = 0; i < s.length(); i++) {
            if(a[i] == 1){
                for (int j = 0; j < wordDict.size(); j++) {
                    if(s.startsWith(wordDict.get(j), i)){
                        a[i + wordDict.get(j).length()] = 1;
                    }
                }
            }
        }
        return a[s.length()] == 1;
    }
}
