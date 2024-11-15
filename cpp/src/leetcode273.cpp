#include <string>
#include <vector>

class Solution {
public:
  static const std::vector<std::pair<int, std::string>> pairs;

  static std::string numberToWords(int num) {
    if (num == 0) {
      return "Zero";
    }
    for (auto &[value, word] : pairs) {
      if (num >= value) {
        std::string prefix =
            (num >= 100) ? numberToWords(num / value) + " " : "";
        std::string unit = word;
        std::string suffix =
            (num % value == 0) ? "" : " " + numberToWords(num % value);

        return prefix + unit + suffix;
      }
    }
    return "";
  }
};

const std::vector<std::pair<int, std::string>> Solution::pairs = {
    {1000000000, "Billion"},
    {1000000, "Million"},
    {1000, "Thousand"},
    {100, "Hundred"},
    {90, "Ninety"},
    {80, "Eighty"},
    {70, "Seventy"},
    {60, "Sixty"},
    {50, "Fifty"},
    {40, "Forty"},
    {30, "Thirty"},
    {20, "Twenty"},
    {19, "Nineteen"},
    {18, "Eighteen"},
    {17, "Seventeen"},
    {16, "Sixteen"},
    {15, "Fifteen"},
    {14, "Fourteen"},
    {13, "Thirteen"},
    {12, "Twelve"},
    {11, "Eleven"},
    {10, "Ten"},
    {9, "Nine"},
    {8, "Eight"},
    {7, "Seven"},
    {6, "Six"},
    {5, "Five"},
    {4, "Four"},
    {3, "Three"},
    {2, "Two"},
    {1, "One"}};
