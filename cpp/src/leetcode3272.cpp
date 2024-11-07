#include <cmath>
#include <iostream>
#include <iterator>

int reverse(int num) {
  int rev = 0;
  while (num > 0) {
    rev = rev * 10 + num % 10;
    num = num / 10;
  }
  return rev;
}

bool isPalindrome(int num) { return num == reverse(num); }

long long fac(int n) {
  if (n < 2) {
    return 1;
  }
  return n * fac(n - 1);
}

long long countGoodIntegers(int n, int k) {
  long long result = 0;
  int p = fac(n);
  int smallest = pow(10, n - 1);
  int largest = pow(10, n) - 1;
  for (int i = smallest; i <= largest; i++) {
    if (isPalindrome(i) && i % k == 0) {
      int digits[10] = {0};
      int x = i;
      for (int j = 0; j < n; j++) {
        digits[x % 10]++;
        x /= 10;
      }
      long long de = 1;
      for (int j = 0; j < 10; j++) {
        de *= fac(digits[j]);
      }
      result += (p / de);
      if (digits[0] != 0) {
        result -= (p * digits[0]) / (de * n);
      }
    }
  }
  return result;
}
