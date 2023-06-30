import java.util.*;

public class LeetCode933 {
    public static void main(String[] arg){
        RecentCounter recentCounter = new RecentCounter();
        System.out.println(recentCounter.ping(1));
        System.out.println(recentCounter.ping(100));
        System.out.println(recentCounter.ping(3001));
        System.out.println(recentCounter.ping(3002));
    }
}

class RecentCounter {
    private Queue<Integer> r; // requests

    public RecentCounter() {
        r = new ArrayDeque<>();
    }
    public int ping(int t) {
        r.add(t);
        while(r.peek() < t-3000){
            r.remove();
        }
        return r.size();
    }
}
