import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class LeetCode451 {
    public static String frequencySort(String s) {
        char[] res = new char[s.length()];
        /*char[] s1 = s.toCharArray();
        Map<Integer, String> map = new HashMap<>();
        Arrays.sort(s1);
        char c = s1[0];
        int count = 1;
        for (int i = 1; i < s1.length; i++) {
            if(c == s1[i]){
                count++;
            }else{
                String temp = map.getOrDefault(count, "");
                temp += c;
                map.put(count, temp);
                c = s1[i];
                count = 1;
            }
            if(i == s1.length - 1){
                String temp = map.getOrDefault(count, "");
                temp += c;
                map.put(count, temp);
            }
        }
        Integer[] indeces = map.keySet().toArray(new Integer[0]);
        Arrays.sort(indeces);
        for (int i : indeces) {
            for (int j = 0; j < map.get(i).length(); j++) {
                for (int k = 0; k < i; k++) {
                    res = map.get(i).charAt(j) + res;
                }
            }
        }*/
        int[] s1 = new int[128];
        for (int i = 0; i < s.length(); i++) {
            s1[s.charAt(i)]++;
        }
        for(int i = 0; i < s.length();){
            int max = 0;
            int index = 0;
            for(int j = 0; j < 128;j++){
                if(s1[j]>max){
                    max = s1[j];
                    index = j;
                }
            }
            while(s1[index]>0){
                res[i++] += (char)index;
                s1[index]--;
            }
        }
        return new String(res);
    }
}
