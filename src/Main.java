import java.util.Arrays;

public class Main {
    public static void main(String[] args){
        long start1 = System.currentTimeMillis();
        char[][] board = new char[][]{
                {'A','B','C','E'},
                {'S','F','C','S'},
                {'A','D','E','E'}
        };
        System.out.println(LeetCode79.exist(board,"SEE"));
        long end1 = System.currentTimeMillis();
        System.out.println((end1-start1) + " ms");
    }
}
