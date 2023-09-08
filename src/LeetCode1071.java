public class LeetCode1071 {
    public static String gcdOfStrings(String str1, String str2) {
        String gcd = "";
        if((str1 + str2).equals(str2 + str1)) {
            gcd += str1.substring(0, GCD(str1.length(), str2.length()));
        }
        return gcd;
    }
    public static int GCD(int a, int b){
        if(a == 0){
            return b;
        } else if (b == 0) {
            return a;
        }
        if(b > a){
            return GCD(a, b-a);
        } else {
            return GCD(a-b, b);
        }
    }
}