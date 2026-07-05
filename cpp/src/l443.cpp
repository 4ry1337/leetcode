#include <bits/stdc++.h>

#include <string>
#include <vector>
using namespace std;

/*
 * link: https://leetcode.com/problems/string-compression/
 * BCR(O(N))
 *
 * solution 1 - rute force
 * 1. create separate vector
 * 2. run for loop
 *  - write down the letter, place a pointer
 *  - move right untill other letter is encountered
 *  - write the length into new vector, and reset the first pointer
 * 3. return length of new vector
 *
 * time: O(N)
 * space: O(N)
 *
 * solution 2 - in place
 * 1. create two pointers
 * 2. run a loop until r < size
 * 3. in a loop start a group len variable
 * 4. while we see same varaible increase len
 * 5. then write current varaible to l, inrement l
 * 6. if len > 1 run for loop and write down len variable and keep track of left
 * 7. move r to start of next group, r += len;
 *
 * */

class Solution {
 public:
  int compress(vector<char>& c) {
    int l{}, r{};
    while (r < c.size()) {
      int len = 1;
      while (r + len < c.size() && c[r] == c[r + len]) len++;
      c[l++] = c[r];
      if (len > 1) {
        for (auto& ch : to_string(len)) {
          c[l++] = ch;
        }
      }
      r += len;
    }
    return l;
  }
  // Example:
  // aabb
  // 0123
  // l
  //   r
  // a2bc5a
};

/* int main() {
  Solution sol;
  std::string s;
  std::getline(std::cin, s);
  auto chars = vector<char>(s.begin(), s.end());
  auto l = sol.compress(chars);
  for (int i = 0; i < chars.size(); i++) std::cout << chars[i];
  std::cout << '\n';
} */
