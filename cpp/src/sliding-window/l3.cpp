#include <bits/stdc++.h>

using namespace std;

/* link:
 * https://leetcode.com/problems/longest-substring-without-repeating-characters
 *
 * solution 1 - brute force
 * start nested loops
 * first is begining second is end
 * check if there no repeating characters save the result
 * time: O(N^2) space: O(1)
 *
 * solution 2 - sliding window
 * we use set to keep track of elements in window
 * if curr char is in set we shrink it by moving left and erasing its chars
 * time: O(N) space: O(N)
 */

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int res = 0, l = 0, r = 0;
    unordered_set<char> st;
    while (r < s.size()) {
      if (st.find(s[r]) != st.end()) {
        st.erase(s[l++]);
      } else {
        res = max(res, r - l);
        st.insert(s[r++]);
      }
    }
    return res;
  }
};
