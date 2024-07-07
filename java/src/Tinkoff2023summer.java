public class Tinkoff2023summer {
    //task6
        /*Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int s = sc.nextInt();
        int[] values = new int[n];
        int[] maxValues = new int[n];
        for(int i=0; i<n; i++){
            values[i] = sc.nextInt();
            maxValues[i] = sc.nextInt();
        }
        int left = 0;
        int right = s;
        int maxMedian = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            int[] count = new int[s + 1];
            for (int i = 0; i < n; i++) {
                if (values[i] > mid) {
                    continue;
                }
                count[Math.min(maxValues[i], mid)]++;
            }
            int sum = 0;
            int median = 0;
            for (int i = s; i >= 0; i--) {
                sum += count[i];
                if (sum > n / 2) {
                    median = i;
                    break;
                }
                if (sum == n / 2 && n % 2 == 0) {
                    for (int j = i - 1; j >= 0; j--) {
                        if (count[j] > 0) {
                            median += j;
                            break;
                        }
                    }
                    median /= 2;
                    break;
                }
            }
            if (median > maxMedian) {
                maxMedian = median;
            }
            if (sum > n / 2) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        System.out.println(maxMedian);*/
    //task5
        /*Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        int res = 0;
        int lines = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            lines++;
            for (int j = i; j < n; j++) {
                sum += a[j];
                if(sum == 0){
                    res += (n-j)*lines;
                    lines = 0;
                    break;
                }
            }
        }
        System.out.println(res);*/
    //task4
        /*Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        int res = 1;
        Hashtable<Integer, Integer> ht = new Hashtable<>();
        for(int i =0; i<n; i++){
            a[i] = sc.nextInt();
            ht.put(a[i], ht.getOrDefault(a[i], 0) + 1);
            int min = Collections.min(ht.values());
            int max = Collections.max(ht.values());
            if(max - min <= 1 && (Collections.frequency(ht.values(), min) == n || Collections.frequency(ht.values(), min) == 1 || Collections.frequency(ht.values(), max) == 1) && res < i+1){
                res = i+1;
            }
        }
        System.out.println(res);*/
    //task3
        /*Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        String s = sc.nextLine();
        int res = -1;
        if(s.contains("a") && s.contains("b") && s.contains("c") && s.contains("d")){
            if(n==4){
                res = 4;
            } else {
                int i=0, j= s.length();
                res = j;
                while(i<j){
                    String ss = s.substring(i, j);
                    if(ss.contains("a") && ss.contains("b") && ss.contains("c") && ss.contains("d") && res > ss.length()){
                        res = ss.length();
                    }
                    i++;
                    if(i==j-1){
                        i=0;
                        j--;
                    }
                }
            }
        }
        System.out.println(res);*/
    // task 1
        /* Scanner sc = new Scanner(System.in);
        int[] a = new int[4];
        for(int i=0; i<4; i++){
            a[i] = sc.nextInt();
        }
        if(a[0]<=a[1] && a[1]<=a[2] && a[2]<=a[3]){
            System.out.println("YES");
        } else if(a[0]>=a[1] && a[1]>=a[2] && a[2]>=a[3]){
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }*/
    //task2
        /*Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int m = sc.nextInt();
        System.out.println((int) Math.ceil((double) (n * k) /m));*/
}
