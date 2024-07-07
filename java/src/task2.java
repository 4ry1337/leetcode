import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class task2 {
    public static List<List<Integer>> findPrimePairs(int n) {
        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 2;  i <= n / 2; i++) {
            if(isPrime(i) && isPrime(n-i)){
                ans.add(Arrays.asList(i, n-i));
            }
        }
        return ans;
    }

    private static boolean isPrime(int x) {
        for (int i = 2; i <= Math.sqrt(x); i++) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }
}
