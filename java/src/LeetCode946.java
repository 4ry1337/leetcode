import java.util.Stack;

public class LeetCode946 {
    public static boolean validateStackSequences(int[] pushed, int[] popped) {
        Stack<Integer> stack = new Stack<>();
        int i = 0, j = 0;
        while (j < pushed.length) {
            if(!stack.isEmpty() && stack.peek() == popped[j]){
                stack.pop();
                j++;
            } else if(i != popped.length) {
                stack.push(pushed[i]);
                i++;
            } else {
                return false;
            }
        }
        return j == popped.length;
    }
}

