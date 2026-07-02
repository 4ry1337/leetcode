#include <bits/stdc++.h>
using namespace std;

/* URLify: Write a method to replace all spaces in a string with '%20'. You may
 * assume that the string has sufficient space at the end to hold the additional
 * characters,and that you are given the "true" length of the string. (Note: If
 * implementing in Java, please use a character array so that you can perform
 * this operation in place.) EXAMPLE Input: "Mr John Smith ", 13 Output:
 * "Mr%20John%20Smith"
 *
 *
 * */

class Solution {
  const string& replaceSpace(string& s1) {
    size_t r = s1.size() - 1;
    for (size_t l = r; l >= 0; --l) {
      if (s1[l] == ' ') {
        continue;
      } else {
        s1[r++] = s1[l];
      }
    }
  }
};
