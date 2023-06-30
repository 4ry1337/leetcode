public class LeetCode2073 {
    public int timeRequiredToBuy(int[] tickets, int k) {
        int ans = 0;
        for (int i = 0; i < tickets.length; i++) {
            if(tickets[i] >= tickets[k]){
                ans+=tickets[k];
            } else {
                ans+=tickets[i];
            }
            if(i>k && tickets[i] >= tickets[k]){
                ans -= 1;
            }
        }
        return ans;
    }
}
