#include <bits/stdc++.h>

using namespace std;

/* link: https://leetcode.com/problems/permutation-in-string/
 * BCR(O(M))
 * s2 must be >= s1 in length for a permutation to exist (checked upfront).
 * building freq map for s1 is O(N), sliding window over s2 is O(M),
 * each comparison is O(26)=O(1). total O(N+M) = O(M) since M >= N.
 *
 * solution 1 - brute force
 * 1. create all permutations of s1
 * 2. check if s2 conatins them
 * 3. early retrun if s2 contains atleast one.
 * time: O(n! m) space: constant
 * - creating permutations: O(n!)
 * - comparing O(m)
 *
 * N input size of s1
 * M input size of s2
 *
 * solution 2 - sliding window
 * 1. if s1 > s2 return false
 * 2. run sliding window across s2 for size of s1
 * 3. if we meet a character outside of s1, we can discard whole sliding window
 * containing that character
 * 4. comparing strings?
 *  - we could sort them locally O(N logN) and compare with string comparator
 *  O(N), total O(M * N logN) per slide
 *  - create a hash map with frequences in window! (unordered_map supports ==,
 *  but worse than fixed array since alphabet is known)
 *  time: O(M) space: O(N)
 *
 * can do constant space?
 * yes, ask if strings are english alphabet? if yes we can use constant array of
 * 26 elements. std::array supports == comparison (element-wise, O(26) = O(1))
 * */
class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    if (s1.empty()) return true;
    if (s1.size() > s2.size()) return false;

    std::array<int, 26> f1{}, f2{};
    for (auto& c : s1) f1[c - 'a']++;
    for (size_t i{}; i < s2.size(); ++i) {
      f2[s2[i] - 'a']++;
      if (i >= s1.size()) f2[s2[i - s1.size()] - 'a']--;
      if (i >= s1.size() - 1 && f1 == f2) return true;
    }
    return false;
  }
};
