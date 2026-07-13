#include <bits/stdc++.h>

#include <unordered_map>

using namespace std;

/*
 * link: https://leetcode.com/problems/time-based-key-value-store/
 * Design a time-based key-value data structure that can store multiple values
 * for the same key at different time stamps and retrieve the key's value at a
 * certain timestamp.
 *
 * Implement the TimeMap class:
 * TimeMap() Initializes the object of the data structure.
 *
 * void set(String key, String value, int timestamp) Stores the key key with the
 * value value at the given time timestamp.
 *
 * String get(String key, int timestamp) Returns a value such that set was
 * called previously, with timestamp_prev <= timestamp. If there are multiple
 * such values, it returns the value associated with the largest timestamp_prev.
 * If there are no values, it returns "".
 * */

class TimeMap {
 private:
  unordered_map<string, vector<pair<int, string>>> m_data;

 public:
  TimeMap() {}

  void set(string key, string value, int timestamp) {
    m_data[key].push_back({timestamp, value});
  }

  string get(string key, int timestamp) {
    auto& v = m_data[key];
    int base = 0, size = m_data.size();
    while (size > 1) {
      int half = size / 2;
      int mid = base + half;
      if (timestamp > v[mid].first) {
        base = mid;
      }
      size -= half;
    }
    return v[base].second;
  }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
