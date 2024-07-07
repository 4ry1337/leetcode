public class LeetCode2739 {
    public static int distanceTraveled(int mainTank, int additionalTank) {
        int i = 0;
        for (; i < mainTank; i++) {
            if(i%5 == 4 && additionalTank > 0){
                additionalTank--;
                mainTank++;
            }
        }
        return i*10;
    }
}
