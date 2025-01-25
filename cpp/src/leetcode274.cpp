#include <iostream>
#include <vector>

using namespace std;

/*
class Solution {
public:
  int hIndex(vector<int> &citations) {
    int max_c = 0;
    sort(citations.begin(), citations.end(), greater<int>());
    for (int i = 0; i < citations.size(); i++) {
      cout << i << endl;
      if (citations[i] >= i + 1) {
        max_c = i + 1;
      } else {
        break;
      }
    }
    return max_c;
  }
};

3 0 6 1 5
5
0 1 2 3 4 5
0 0 0 0 0 0
1 1 0 1 0 2
hIndex = 5
3
*/

class Solution {
public:
  int hIndex(vector<int> &citations) {
    int length = citations.size();
    vector<int> freq(length + 1, 0);
    for (int citation : citations) {
      freq[min(citation, length)]++;
    }
    int res = 0;
    for (int h = length; h >= 0; h--) {
      res += freq[h];
      if (res >= h) {
        return h;
      }
    }
    return 0;
  }
};

/*
int main(int argc, char *argv[]) {
  vector<int> citations = {1, 3, 1};
  Solution s;
  cout << endl << s.hIndex(citations);
  return 0;
}
*/
