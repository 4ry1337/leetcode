class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0)
      return false;
    long long temp = x, res = 0;
    while (temp != 0) {
      res *= 10;
      res += temp % 10;
      temp /= 10;
    }
    return res == x;
  }
};
