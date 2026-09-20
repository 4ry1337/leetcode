#include <array>
#include <string>

using namespace std;

/* link: https://leetcode.com/problems/permutation-in-string */

class Solution {
 public:
  static auto checkInclusion(const string& s1, string s2) -> bool {
    if (s1.size() > s2.size()) {
      return false;
    }
    array<int, 26> f1{};
    array<int, 26> f2{};
    for (const auto& c : s1) {
      f1[c - 'a']++;
    }
    for (int i{}; i < s2.size(); ++i) {
      f2[s2[i] - 'a']++;
      if (s1.size() <= i) {
        f2[s2[i - s1.size()] - 'a']--;  // exceed condition
      }
      if (s1.size() - 1 <= i && f1 == f2) {
        return true;  // check condition
      }
    }
    return false;
  }
};
