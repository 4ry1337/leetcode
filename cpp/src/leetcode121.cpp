#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int maxProfit = 0, maxLocal = 0;
    for (int i = 0; i < prices.size() - 1; i++) {
      prices[i] = prices[i + 1] - prices[i];
    }
    for (int i = 0; i < prices.size() - 1; i++) {
      maxLocal = max(prices[i], maxLocal + prices[i]);
      if (maxLocal > maxProfit) {
        maxProfit = maxLocal;
      }
    }
    return maxProfit;
  }
};
