/*
// Attempt 1
int maxProfitHelper(int *prices, int pricesSize, int i, int current,
                    int bought) {
  if (i == pricesSize)
    return current;
  int buy;
  if (bought == 1) {
    buy = maxProfitHelper(prices, pricesSize, i + 1, current + prices[i], 0);
  } else {
    buy = maxProfitHelper(prices, pricesSize, i + 1, current - prices[i], 1);
  }
  int donothing = maxProfitHelper(prices, pricesSize, i + 1, current, bought);
  return buy > donothing ? buy : donothing;
}

int maxProfit(int *prices, int pricesSize) {
  return maxProfitHelper(prices, pricesSize, 0, 0, 0);
}
*/

// Attempt 2
#include <stdio.h>
int maxProfit(int *prices, int pricesSize) {
  int max = 0;
  for (int i = 0; i < pricesSize; i++) {
    int l = i, r = i + 1;
    int local_max = 0;
    while (r < pricesSize) {
      int curr = prices[r] - prices[l];
      /*printf("%d, %d, %d\n", l, r, curr);*/
      if (curr > 0) {
        local_max += curr;
        l = r;
      } else {
        l++;
      }
      r++;
    }
    /*printf("%d\n", local_max);*/
    max = max > local_max ? max : local_max;
  }
  return max;
}
/*
int main(int argc, char *argv[]) {
  int prices[6] = {7, 1, 5, 3, 6, 4};
  int res = maxProfit(prices, 6);
  printf("%d", res);
  return 0;
}
*/

/*
int maxProfit(int *prices, int pricesSize) {
  int profit = 0;
  for (int i = 1; i < pricesSize; i++) {
    if (prices[i] > prices[i - 1])
      profit += (prices[i] - prices[i - 1]);
  }
  return profit;
}
*/
