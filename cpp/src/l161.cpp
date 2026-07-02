#include <bits/stdc++.h>

/* link: https://neetcode.io/problems/one-edit-distance
 *
 * BCR()
 *
 * solution 1 - brute force:
 * 1. compare sizes if more than 2 return false;
 * 2. compare freq if they differ
 *  - if we one insert / remove away freq differences should be 0 but one place
 *  - if we one replace away
 *
 * pale
 * bake
 *
 *
 * a 0
 * b -1
 * k -1
 * l 1
 * p 1
 * e 0
 *
 * */
bool is_one_edit_distance(std::string& s, std::string& t) {
  if (s.size() < t.size()) std::swap(s, t);
  if (s.size() - t.size() > 1) return false;
  int res = 0;
  std::array<int, 26> freq{};
  for (char& c : s) freq[c - 'a']++;
  for (char& c : t) freq[c - 'a']--;
  for (int& i : freq) {
    res += i;
  }
  std::cout << res << std::endl;
  return res < 2 && res > -2;
}

int main() {
  std::string s;
  std::getline(std::cin, s);
  std::string t;
  std::getline(std::cin, t);
  bool res = is_one_edit_distance(s, t);
  std::cout << std::boolalpha << res << '\n';
}
