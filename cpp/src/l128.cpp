#include <bits/stdc++.h>

using namespace std;

/*
 * link: https://leetcode.com/problems/longest-consecutive-sequence
 * BCR(O(N))
 *
 * solution 1 - hash set
 * 1. create hash set out of numbers
 * 2. init longest, iterate through numbers
 *  - if n-1 exists in hash set then
 *  - init temp variable 1 for length
 *  - start while n-1 exists in set increment temp
 *  - after if it is larger than longest write to it.
 *
 * time: O(n^2) space: O(N)
 * problem: bottleneck is the second while loop. In worst case it can foes
 * through all of N again but in set.
 *
 * solution 2 - priority queue (max-heap)
 * 1. push all numbers into a max-heap
 * 2. pop elements one at a time (comes out in descending order)
 * 3. track current run length m and best result res
 *  - if top == next - 1, we're continuing a consecutive run downward -> m++
 *  - else if top != next (and not consecutive), run broke -> res = max(res, m),
 * reset m = 1
 *  - if top == next, it's a duplicate -> do nothing (skip without breaking
 * streak)
 * 4. after loop, one final res = max(res, m) to catch the last run
 *
 * time: O(N log N) — N pushes + N pops, each O(log N)
 * space: O(N) for the heap
 * problem: not linear time — heap push/pop costs log N, so this doesn't
 * hit the BCR.
 *
 * solution 3 hashmap
 * 1. Create a hash map mp that stores sequence lengths at boundary positions.
 * 2. Initialize res = 0 to store the longest sequence found.
 * 3. For each number num in the input:
 *   - If num is already in mp, skip it.
 *   - Compute the new sequence length: length = mp[num - 1] + mp[num + 1] + 1
 *   - Store this length at num.
 *   - Update the boundaries:
 *     - Left boundary: mp[num - mp[num - 1]] = length
 *     - Right boundary: mp[num + mp[num + 1]] = length
 *   - Update res to keep track of the longest sequence.
 * 4. Return res after processing all numbers.
 * */

class Solution {
 public:
  /* int longestConsecutive(vector<int>& nums) {
    if(nums.empty()) return 0;
    priority_queue<int> mp;
    for(auto & n : nums) {
        mp.push(n);
    }
    int res = 1, m = 1, next = mp.top(); mp.pop();
    while(!mp.empty()) {
        if(mp.top() == next - 1) {
            m++;
        } else if(mp.top() != next) {
            res = max(m, res);
            m = 1;
        }
        next = mp.top();
        mp.pop();
    }
    return max(m, res);
} */
  int longestConsecutive(vector<int>& nums) {
    int res = INT_MIN;
    unordered_map<int, int> mp;
    for (auto& n : nums) {
      if (mp[n]) continue;
      mp[n] = mp[n - 1] + mp[n + 1] + 1;
      mp[n - mp[n - 1]] = mp[n];
      mp[n + mp[n + 1]] = mp[n];
      res = max(res, mp[n]);
    }
    return res;
  }
};
