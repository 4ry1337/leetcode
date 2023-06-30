import java.util.Arrays;

public class LeetCode79 {
    public static boolean exist(char[][] board, String word) {
        for (int i = 0; i < board.length; i++) {
            System.out.println(Arrays.toString(board[i]));
        }
        return existHelper(board, new boolean[board.length][board[0].length], word, 0, 0, 0);
    }
    private static boolean existHelper(char[][] board, boolean[][] used, String word, int x, int y, int i) {
        if(i == word.length()){
            return true;
        }
        if(x < board.length && y < board[0].length && x >= 0 && y >= 0 && board[x][y] == word.charAt(i) && !used[x][y]){
            used[x][y] = true;
            return existHelper(board, used, word, x, y + 1, i + 1) || existHelper(board, used, word, x, y - 1, i + 1) || existHelper(board, used, word, x - 1, y, i + 1) || existHelper(board, used, word, x + 1, y, i + 1);
        } else {
            if(x >= board.length){
                return existHelper(board, new boolean[board.length][board[0].length], word, x, y + 1, 0);
            } else {
                y = 0;
                return existHelper(board, new boolean[board.length][board[0].length], word, x + 1, y, 0);
            }
            return false;
        }
    }
}
