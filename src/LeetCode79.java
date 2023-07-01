import java.util.Arrays;

public class LeetCode79 {
    public static boolean exist(char[][] board, String word) {
        boolean result = false;
        for(int i=0; i<board.length; i++)
        {
            for(int j=0; j<board[0].length; j++)
            {
                if(existHelper(board,word,i,j,0))
                {
                    result = true;
                }
            }
        }
        return result;
    }
    private static boolean existHelper(char[][] board, String word, int x, int y, int i) {
        if(x >= board.length || y >= board[0].length || x < 0 || y < 0){
            return false;
        }
        if(board[x][y] == word.charAt(i)){
            char temp = board[x][y];
            board[x][y]='#';
            if(i == word.length() - 1){
                return true;
            } else if(existHelper(board, word, x, y + 1, i + 1) || existHelper(board, word, x, y - 1, i + 1) || existHelper(board, word, x - 1, y, i + 1) || existHelper(board, word, x + 1, y, i + 1)){
                return true;
            }
            board[x][y]=temp;
        }
        return false;
    }
}
