#include <bits/stdc++.h>
#include <string>

class Solution {
private:
  static constexpr int n[13] = {1000, 900, 500, 400, 100, 90, 50,
                                40,   10,  9,   5,   4,   1};
  static constexpr std::string_view s[13] = {
      "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

public:
  static std::string intToRoman(int num) {
    std::string result = "";
    int i = 0;
    while (num > 0) {
      if (num >= n[i]) {
        result += s[i];
        num -= n[i];
      } else {
        i++;
      }
    }
    return result;
  }
};
