public class MockInterview2 {
    public static boolean palindrome(int num){
        int i = 0;
        int num1 = num;
        int num2 = 0;
        while(num1 != num1%10){
            num2 *= Math.pow(10, i);
            num2 += num1%10;
            num1 /= 10;
            i++;
        }
        num2 *= 10;
        num2 += num1;
        return num == num2;
    }
}
