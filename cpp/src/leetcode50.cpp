class Solution {
public:
  double myPow(double x, int n) {
    if (n == 0)
      return 1;
    if (n < 0)
      return (double)1.0 / x * myPow((double)1.0 / x, -(++n));
    else if (n % 2 == 1)
      return myPow(x * x, n / 2) * x;
    else
      return myPow(x * x, n / 2);
  }
};
