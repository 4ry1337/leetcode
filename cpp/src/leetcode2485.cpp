class Solution {
public:
  int pivotInteger(int n) {
    int right_sum = n * (n + 1) / 2, left_sum = 0;
    for (int i = 1; i <= n; i++) {
      left_sum += i;
      right_sum -= i;
      if (left_sum == right_sum + i) {
        return i;
      }
    }
    return -1;
  }
};
