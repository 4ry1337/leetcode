#include <bits/stdc++.h>

using namespace std;

/* https://leetcode.com/problems/find-median-from-data-stream
 *
 * solution 1 - sort
 *
 * class. init vector
 * space: O(N)
 * addNum. store in vector
 * time: O(1) space: O(1)
 * findMedian. sort and retrieve medians
 * time: O(NlogN) space: O(1)
 *
 * solution 2 - one heap
 *
 * class. init heap
 * time: O(1) space: O(N)
 * addNum. store in heap
 * time: O(logN) space: O(1)
 * findMedian. copy and get to the mid of priority queue
 * time: O(NlogN) space: O(N)
 * */

/* class MedianFinder {
 private:
  priority_queue<int> pq;

 public:
  MedianFinder() {}

  void addNum(int num) { pq.push(num); }

  double findMedian() {
    priority_queue<int> temp = pq;
    int s = temp.size();
    for (int i{}; i < s / 2 - 1; ++i) temp.pop();
    if (s % 2 == 1) {
      temp.pop();
      return temp.top();
    }
    double m1 = temp.top();
    temp.pop();
    double m2 = temp.top();
    return (m1 + m2) / 2;
  }
}; */

/* solution 3 - two heaps
 * one for lesser half, one for greater half;
 *
 * class. init 2 heaps
 * time: O(1) space: O(N)
 * addNum. store in heap
 * time: O(logN) space: O(1)
 * findMedian. copy and get to the mid of priority queue
 * time: O(1) space: O(1)
 * */

class MedianFinder {
 private:
  priority_queue<int, vector<int>, less<int>> lesser;
  priority_queue<int, vector<int>, greater<int>> greater;

 public:
  MedianFinder() {}

  void addNum(int num) {
    lesser.push(num);
    if (!greater.empty() && lesser.top() > greater.top()) {
      greater.push(lesser.top());
      lesser.pop();
    }
    if (lesser.size() > greater.size() + 1) {
      greater.push(lesser.top());
      lesser.pop();
    }
    if (greater.size() > lesser.size() + 1) {
      lesser.push(greater.top());
      greater.pop();
    }
  }

  double findMedian() {
    if (lesser.size() == greater.size()) {
      return (lesser.top() + greater.top()) / 2.0;
    } else if (lesser.size() > greater.size()) {
      return lesser.top();
    } else {
      return greater.top();
    }
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
