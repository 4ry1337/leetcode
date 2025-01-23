#include <vector>

using namespace std;

class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int length = gas.size();
    for (int i = 0; i < length; i++) {
      if (gas[i] - cost[i] >= 0) {
        int tank = 0;
        for (int j = i; j <= length + i; j++) {
          tank += gas[j % length] - cost[j % length];
          if (tank < 0) {
            i = j;
            break;
          }
        }
        if (tank >= 0) {
          return i;
        }
      }
    }
    return -1;
  }
};

// better

class Solution2 {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int length = gas.size();
    int total = 0;
    int debt = 0;
    int start = 0;
    for (int i = 0; i < length; i++) {
      total += gas[i] - cost[i];
      debt += gas[i] - cost[i];
      if (debt < 0) {
        start = i + 1;
        debt = 0;
      }
    }
    return total < 0 ? -1 : start;
  }
};
