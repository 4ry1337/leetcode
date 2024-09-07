#include <algorithm>
#include <cmath>

int generateKey(int num1, int num2, int num3) {
  int result = 0;
  for (int i = 3; i > -1; i--) {
    int x = pow(10, i);
    int min = std::min(num1 / x, std::min(num2 / x, num3 / x));
    result += min * x;
    num1 %= x;
    num2 %= x;
    num3 %= x;
  }
  return result;
}
