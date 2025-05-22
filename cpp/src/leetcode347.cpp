#include <bits/stdc++.h>
#include <queue>

using namespace std;

/* class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> count;
    for (const int &n : nums) {
      count[n]++;
    }

    vector<pair<int, int>> arr;
    for (const auto &p : count)
      arr.push_back({p.second, p.first});

    sort(arr.rbegin(), arr.rend());

    vector<int> res;
    for (int i = 0; i < k; ++i)
      res.push_back(arr[i].second);

    return res;
  }
}; */

class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> m;
    priority_queue<pair<int, int>> pq;
    vector<int> res;

    for (const int &n : nums)
      m[n]++;
    for (auto &x : m)
      pq.push({x.second, x.first});
    for (int i = 0; i < k; i++) {
      res.push_back(pq.top().second);
      pq.pop();
    }

    return res;
  }
};
