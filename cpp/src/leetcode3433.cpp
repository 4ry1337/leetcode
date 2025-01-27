#include <algorithm>
#include <climits>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> countMentions(int numberOfUsers, vector<vector<string>> &events) {
    unordered_map<int, int> offline;
    vector<int> mentions(numberOfUsers, 0);

    sort(events.begin(), events.end(),
         [](const vector<string> &a, const vector<string> &b) {
           int timeA = stoi(a[1]);
           int timeB = stoi(b[1]);
           if (timeA != timeB) {
             return timeA < timeB;
           } else {
             return a[0] == "OFFLINE" && b[0] != "OFFLINE";
           }
         });

    for (auto message : events) {
      int timestamp = stoi(message[1]);
      if (message[0] == "MESSAGE") {
        if (message[2] == "ALL") {
          for (auto &m : mentions) {
            m++;
          }
        } else if (message[2] == "HERE") {
          for (int m = 0; m < numberOfUsers; m++) {
            auto it = offline.find(m);
            if (it != offline.end() && it->second > timestamp - 60) {
              continue;
            }
            mentions[m]++;
          }
        } else {
          int start = 0, end = 0;
          for (int c = 0; c < message[2].size(); c++) {
            if (isdigit(message[2][c])) {
              start = c;
              while (c < message[2].size() && message[2][c] != ' ') {
                c++;
              }
              end = c;
              int m = stoi(message[2].substr(start, end));
              mentions[m]++;
            }
          }
        }
      } else {
        offline[stoi(message[2])] = timestamp;
      }
    }
    return mentions;
  }
};
