import java.util.Arrays;

public class Main {
    public static void main(String[] args){
        long start1 = System.currentTimeMillis();
        System.out.println(LeetCode306.isAdditiveNumber("199100199"));
        long end1 = System.currentTimeMillis();
        System.out.println((end1-start1) + " ms");
    }
}
