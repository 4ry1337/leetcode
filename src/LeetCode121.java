class LeetCode121 {
    public static int maxProfit(int[] prices) {
        //int result=0;
        int min=100000;
        int max=0;
        for(int i=0; i<prices.length; i++){
            min = Math.min(min, prices[i]);
            if(prices[i] > min){
                max = Math.max(max, prices[i] - min);
            }
        }
        return max;
    }
}
