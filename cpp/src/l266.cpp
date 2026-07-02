#include <bits/stdc++.h>

#include <array>
using namespace std;

/*
 * link: https://leetcode.com/problems/palindrome-permutation
 * BCR(O(N))
 *
 * solution 1 - brute force
 * 1. create every permutation of s
 * 2. check them
 *
 * bad: too long feasible for n <= 10
 * time: O(N!) + search over it
 * space: O(1)
 *
 * solution 2 -
 * we dont need to construct any permutation we just need to check if from this
 * character permutation of polindrome is possible
 * A string can be rearranged into a palindrome
 * if and only if at most one character has an odd frequency.
 *
 * 1. count frequencies
 * 2. count odd frequencies
 * 3. if odd frequencies is larger than 1 then return false, also acts as early
 * return
 * 4. return true
 *
 * time: O(N)
 * space: use O(alphabet(s))
 * ask: is alphabet is english?
 *
 * examples:
 * ""
 * a
 * ba
 * bbbaaa
 * aab
 * aabccc
 * aabb
 * */

class Solution {
 public:
  bool canPermutePalindrome(string s) {
    std::array<int, 26> freq{};
    for (char& c : s) {
      freq[c - 'a']++;
    }
    int odd{};
    for (auto i : freq) {
      if (i % 2 == 1) {
        odd++;
        if (odd > 1) {
          return false;
        }
      }
    }
    return true;
  }
};
