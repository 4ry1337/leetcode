#include <bits/stdc++.h>

using namespace std;

/* link: https://neetcode.io/problems/one-edit-distance
 *
 * BCR(O(max(M,N)) - every character must be inspected at least once, skipping
 * any could miss the edit
 *
 * solution 1 - brute force:
 * 1. generate all strings one edit away from s (insert, delete, replace)
 * 2. check if t is among them
 * time: O(N^2) space: O(N^2)
 *
 * solution 2 - two pointers:
 * 1. if size diff > 1 return false
 * 2. walk both strings with two pointers i, j
 * 3. on first mismatch: advance pointer of longer string (or both if equal)
 * 4. if more than one mismatch return false
 * 5. if no mismatch found strings are identical, return true
 * time: O(N) space: O(1)
 *
 * */
/* bool is_one_edit_distance(std::string& s, std::string& t) {
  int m = s.size(), n = t.size();
  if (n > m) {
    std::swap(s, t);
    std::swap(m, n);
  }
  if (m - n > 1) return false;
  for (int i = 0; i < m; ++i) {
    if (s[i] != t[i]) {
      if (m == n) {
        if (s.substr(i + 1) == t.substr(i + 1)) return true;
      } else {
        if (s.substr(i + 1) == t.substr(i)) return true;
      }
      return false;
    }
  }
  return false;
} */
// problems: swap, substr allocates space

bool is_one_edit_distance(std::string& s, std::string& t) {
  int m = s.size(), n = t.size();
  if (abs(m - n) > 1) return false;
  int i = 0, j = 0, mis = 0;
  while (i < m && j < n) {
    if (s[i] != t[j]) {
      if (++mis > 1) return false;
      if (m >= n) ++i;
      if (n >= m) ++j;
    } else {
      ++i;
      ++j;
    }
  }
  return true;
}

/* int main() {
  std::string s;
  std::getline(std::cin, s);
  std::string t;
  std::getline(std::cin, t);
  bool res = is_one_edit_distance(s, t);
  std::cout << std::boolalpha << res << '\n';
} */
