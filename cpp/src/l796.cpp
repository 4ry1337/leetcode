#include <bits/stdc++.h>
using namespace std;

/*
 * https://leetcode.com/problems/rotate-string/ */

class Solution {
 public:
  bool rotateString(string s, string goal) {
    goal += goal;
    return goal.find(s) != goal.npos;
  }
};
