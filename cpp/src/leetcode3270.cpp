#include <algorithm>
#include <cmath>

using namespace std;

int generateKey(int num1, int num2, int num3) {
  int result = 0;
  for (int i = 3; i > -1; i--) {
    int x = pow(10, i);
    int m = min(num1 / x, min(num2 / x, num3 / x));
    result += m * x;
    num1 %= x;
    num2 %= x;
    num3 %= x;
  }
  return result;
}
