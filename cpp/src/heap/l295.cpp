#include <bits/stdc++.h>

using namespace std;

/* https://leetcode.com/problems/find-median-from-data-stream */

class MedianFinder {
 private:
  priority_queue<int> pq;

 public:
  MedianFinder() {}

  void addNum(int num) { pq.push(num); }

  double findMedian() {}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
