#include <bits/stdc++.h>

using namespace std;

/* link: https://leetcode.com/problems/sliding-window-maximum/
 *
 * solution 1 - brute force
 * for every possible window of size k, we simply look at all k elements and
 pick the maximum.
 * we slide the window one step at a time, and each time we scan all elements
 inside it to find the max.
 *
 * time: O(n*k) space: O(1) + extra space for output array
 *
 * solution 2 - sliding window queue
 *
 * idea is to keep the deque storing indices of elements in decreasing order of
 * their values.
 * - the front of the deque always holds the index of the current window’s
 *   maximum.
 * - smaller elements behind a bigger one are useless (they can never become the
 *   max later), so we remove them when pushing a new number.
 * - if the element at the front falls out of the window, we remove it.
 *
 * by maintaining this structure, each element is added and removed at most
 * once, giving an optimal solution.
 *
 * time: O(N) space: O(N)
 * */

class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& n, int k) {
    vector<int> res;
    int l = 0, r = 0;
    deque<int> max_i;
    while (r < n.size()) {
      while (!max_i.empty() && n[max_i.back()] < n[r]) max_i.pop_back();
      max_i.push_back(r);
      while (l > max_i.front()) max_i.pop_front();
      if (r - l + 1 == k) {
        res.push_back(n[max_i.front()]);
        l++;
      }
      r++;
    }
    return res;
  }
};
