#include <bits/stdc++.h>

using namespace std;

/*
 * link: https://leetcode.com/problems/contains-duplicate/
 * bcr: o(n)
 * To guarantee correctness, each element should be inspected at least once -
 * because if element is skipped even one, that element could be the duplicate.
 *
 * solution 1 - brute force:
 * 1. compare each pair
 * 2. if we get equal pairs we stop and return true.
 * 3. if we dont find any pair stop return false
 * time: n^2 space: constant
 *
 * solution 2 - sort
 * bottleneck is comparing each pair and going through whole array for each
 * index.
 * 1. sort an array O(n logn)
 * 2. compare neighbors O(n)
 * 3. return true if found similar
 * time: n log n space: constant
 *
 * solution 3 - set
 * bottleneck is sorting, but why sort at all? we dont need to return duplicate
 * number, we just need to check if it exists.
 *
 * 1. we input all values into the set
 * 2. we compare sizes of set and array
 * 3. if equal we return false, otherwise true
 * time: n space: n
 *
 * can we get space constant?
 * no. when I reach some X. I need to know have I see this X before? if we dont
 * store each we dont know that in constant time, otherwise we will need to
 * rescan whole array again
 *
 * */

class Solution {
 public:
  // bool containsDuplicate(vector<int>& nums) {
  //   std::unordered_set<int> s(nums.begin(), nums.end());
  //   return s.size() != nums.size();
  // }
  // problem: no early return

  // bool containsDuplicate(vector<int>& nums) {
  //   std::unordered_set<int> s;
  //   for (auto& n : nums) {
  //     if (s.contains(n)) {
  //       return true;
  //     }
  //     s.insert(n);
  //   }
  //   return false;
  // }
  // problem: two lookups instead of one

  bool containsDuplicate(vector<int>& nums) {
    std::unordered_set<int> s;
    for (auto& n : nums) {
      if (!s.insert(n).second) {
        return true;
      }
    }
    return false;
  }
};
