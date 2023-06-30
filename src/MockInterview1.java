import java.util.Arrays;

public class MockInterview1 {
    public static int Duplicate(int[] arr) {
        Arrays.sort(arr);
        int ans = arr[0];
        for (int i = 0; i < arr.length; i+=2) {
            if(i == arr.length - 1){
                return arr[i];
            } else {
                if(arr[i] != arr[i+1]) {
                    ans = arr[i];
                    break;
                }
            }
        }
        return ans;
    }
}
