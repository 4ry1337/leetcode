public class LeetCode14 {
    public static String longestCommonPrefix(String[] strs) {
        String result = "";
        int k=0;
        for (int i = 0; i < strs.length; i++) {
            if(strs[k].length() > strs[i].length()){
                k = i;
            }
        }
        for (int i = 0; i < strs[k].length(); i++) {
            int count = 0;
            for (int j = 0; j < strs.length; j++) {
                if(strs[k].charAt(i) == strs[j].charAt(i)){
                    count ++;
                }
            }
            if(count == strs.length){
                result += strs[k].charAt(i);
            } else {
                break;
            }
        }
        return result;
    } // 8ms

    public String longestCommonPrefixAnswer(String[] strs) {
        String prefix = strs[0]; // initialize prefix as first string in array
        for(int index=1;index<strs.length;index++){ // compare with others
            while(strs[index].indexOf(prefix) != 0){ //if prefix is not in first decrease by 1 and run again
                prefix=prefix.substring(0,prefix.length()-1);
            }
        }
        return prefix;
    }
}
