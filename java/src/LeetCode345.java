import java.util.Arrays;

public class LeetCode345 {
    public static String reverseVowels(String str) {
        char[] s = str.toCharArray();
        int r = 0;
        int l = s.length - 1;
        while(r <= l){
            System.out.println(r + " " + l);
            if(isVowel(s[r]) && isVowel(s[l])){
                System.out.println(s[r] + " " + s[l]);
                char temp = s[r];
                s[r] = s[l];
                s[l] = temp;
                r++;
                l--;
            } else if(isVowel(s[r]) && !isVowel(s[l])) {
                l--;
            } else if(!isVowel(s[r]) && isVowel(s[l])) {
                r++;
            } else {
                r++;
                l--;
            }
        }
        return String.valueOf(s);
    }

    public static boolean isVowel(char a){
        if(a == 'a' || a == 'A'){
            return true;
        }
        if(a == 'e' || a == 'E'){
            return true;
        }
        if(a == 'i' || a == 'I'){
            return true;
        }
        if(a == 'o' || a == 'O'){
            return true;
        }
        if(a == 'u' || a == 'U'){
            return true;
        }
        return false;
    }
}
