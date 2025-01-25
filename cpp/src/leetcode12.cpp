#include <string>

using namespace std;

class Solution {
public:
  string intToRoman(int num) {
    int n[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string s[13] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                    "XL", "X",  "IX", "V",  "IV", "I"};
    string result = "";
    int i = 0;
    while (num > 0) {
      if (n[i] <= num) {
        num -= n[i];
        result += s[i];
      } else {
        i++;
      }
    }
    return result;
  }
};
