#include <bits/stdc++.h>

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

/* class Solution {
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
}; */

class Solution {
public:
  vector<int> topKFrequent(vector<int> &n, int k) {
    unordered_map<int, int> mp;
    for (int x : n) {
      mp[x]++;
    }
    vector<vector<int>> buck(n.size() + 1);
    for (const auto &p : mp) {
      buck[p.second].push_back(p.first);
    }

    vector<int> res;
    for (int i = buck.size() - 1; i > 0; i--) {
      for (int f : buck[i]) {
        res.push_back(f);
        if (res.size() == k) {
          return res;
        }
      }
    }
    return res;
  }
};
