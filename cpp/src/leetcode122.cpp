#include <vector>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int profit = 0;
    for (int i = 0; i < prices.size() - 1; i++) {
      prices[i] = prices[i + 1] - prices[i];
      if (prices[i] > 0) {
        profit += prices[i];
      }
    }
    return profit;
  }
};
