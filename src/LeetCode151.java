public class LeetCode151 {
    //Reverse Words in a String
    public static String reverseWords(String s) {
        String ans = "";
        for (int i = 0; i < s.length(); i++) {
            if(s.charAt(i) != ' '){
                for (int j = i; j < s.length(); j++) {
                    if(s.charAt(j) == ' '){
                        ans = s.substring(i, j) + " " + ans;
                        i = j;
                        break;
                    } else if(j == s.length()-1){
                        ans = s.substring(i) + " " + ans;
                        i = j;
                        break;
                    }
                }
            }
        }
        return ans.substring(0, ans.length()-1);
    }
}
