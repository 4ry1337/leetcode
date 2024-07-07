public class LeetCode1528 {
    public static String restoreString(String s, int[] indices) {
        char[] t = new char[indices.length];
        for (int i = 0; i < indices.length; i++) {
            t[indices[i]] = s.charAt(i);
        }
        System.gc();
        return new String(t);
    }
}
