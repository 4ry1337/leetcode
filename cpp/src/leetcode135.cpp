#include <vector>

using namespace std;

class Solution {
public:
  int candy(vector<int> &ratings) {
    int length = ratings.size();
    vector<int> check(length, 1);
    for (int i = 1; i < length; i++) {
      if (ratings[i - 1] < ratings[i]) {
        check[i] = check[i - 1] + 1;
      }
    }
    for (int i = length - 2; i >= 0; i--) {
      if (ratings[i + 1] < ratings[i] && check[i + 1] >= check[i]) {
        check[i] = check[i + 1] + 1;
      }
    }
    int candy = 0;
    for (int i = 0; i < length; i++) {
      candy += check[i];
    }
    return candy;
  }
};
