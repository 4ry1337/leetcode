#include <bits/stdc++.h>

using namespace std;

/* URLify: Write a method to replace all spaces in a string with '%20'. You may
 * assume that the string has sufficient space at the end to hold the additional
 * characters,and that you are given the "true" length of the string. (Note: If
 * implementing in Java, please use a character array so that you can perform
 * this operation in place.) EXAMPLE Input: "Mr John Smith ", 13 Output:
 * "Mr%20John%20Smith"
 *
 * BCR(N) we need to go through each character and space in string,
 * to guarantee that we replaced correctly.
 *
 * Solution 1 - brute force
 * 1. create a new string
 * 2. start looping through push characters
 * 3. if space is encountered skip it in main loop, and append "%20" into res
 * string
 * 4. return res;
 * time: O(N) space: O(N)
 *
 * Solution 2 - space optimized
 * Since we have space for in place modification, we can start from the end - r
 * and last character l
 * we write to last s[r] = s[l]
 * we move both left when encounter a space move r 3 indices and change those
 * incdices to "%20"
 * time: O(N) space: O(1)
 *
 * special case if space is in front
 * */

class Solution {
 public:
  const string& replaceSpace(string& s) {
    int r = s.size() - 1, l = r;
    while (s[l] == ' ') {
      l--;
    }
    while (l >= 0) {
      if (s[l] != ' ') {
        s[r--] = s[l];
      } else {
        s[r--] = '0';
        s[r--] = '2';
        s[r--] = '%';
      }
      l--;
    }
    return s;
  }
};

/* int main() {
  Solution sol;

  string s1 = "Mr John Smith    ";
  sol.replaceSpace(s1);
  assert(s1 == "Mr%20John%20Smith");

  string s2 = "a b c    ";
  sol.replaceSpace(s2);
  assert(s2 == "a%20b%20c");

  string s3 = " hello world    ";
  sol.replaceSpace(s3);
  assert(s3 == "%20hello%20world");

  return 0;
} */
