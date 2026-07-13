#include <bits/stdc++.h>

#include <algorithm>
#include <memory>

using namespace std;

/* link: https://leetcode.com/problems/median-of-two-sorted-arrays/ */

class Solution {
 public:
  /* double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
    int total_size = A.size() + B.size();
    int median = (total_size + 1) / 2;
    if (A.size() > B.size()) swap(A, B);
    int base = 0;
    int size = A.size() + 1;
    while (size > 0) {
      int half = size / 2;
      int mid = base + half;

      int al = mid > 0 ? A[mid - 1] : INT_MIN;
      int ar = mid < A.size() ? A[mid] : INT_MAX;
      int bl = median - mid > 0 ? B[median - mid - 1] : INT_MIN;
      int br = median - mid < B.size() ? B[median - mid] : INT_MAX;

      if (al <= br && bl <= ar) {
        if (total_size % 2 == 1) {
          return max(al, bl);
        }
        return (max(al, bl) + min(ar, br)) / 2.0;
      } else if (bl > ar) {
        base = mid + 1;
        size -= half + 1;
      } else {
        size = half;
      }
    }
    return -1;
  } */
  // hard to follow
  double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
    int total = A.size() + B.size();
    int half = (total + 1) / 2;
    if (A.size() > B.size()) swap(A, B);
    int l = 0, r = A.size() - 1;
    while (l <= r) {
      int am = l + (r - l) / 2;
      int bm = half - am;

      int al = am > 0 ? A[am - 1] : INT_MIN;
      int ar = am < (int)A.size() ? A[am] : INT_MAX;
      int bl = bm > 0 ? B[bm - 1] : INT_MIN;
      int br = bm < (int)B.size() ? B[bm] : INT_MAX;

      if (al <= br && bl <= ar) {
        if (total % 2 == 0) return (max(al, bl) + min(ar, br)) / 2.0;
        return max(al, bl);
      } else if (al > br) {
        am = l + 1;
      } else {
        am = r - 1;
      }
    }
    return -1;
  }
};
