#include <bits/stdc++.h>

using namespace std;

/*
// My answer
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {\
        vector<vector<string>> res;
        vector<unordered_map<int, int>> vm;
        for(int i = 0; i < strs.size(); i++) {
            unordered_map<int, int> temp;
            for(char c : strs[i]) {
                temp[(unsigned char)c]++;
            }
            int j = 0;
            while(j < vm.size()) {
                if(vm[j] == temp) {
                    res[j].push_back(strs[i]);
                    break;
                }
                j++;
            }
            if(j == vm.size()) {
                res.push_back(vector<string>{strs[i]});
                vm.push_back(temp);
            }
        }
        return res;
    }
};
*/
// Faster, idk why takes n*n*log(n) worst case
// reviewed and solved in same way, because sorting takes n*log(n)
// can be improved by iterating over string and saving into staticly sized
// vector
class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &s) {
    unordered_map<string, vector<string>> mp;
    for (int i = 0; i < s.size(); i++) {
      string temp = s[i];
      sort(temp.begin(), temp.end());
      mp[temp].push_back(s[i]);
    }
    vector<vector<string>> res;
    for (const auto &p : mp) {
      res.push_back(p.second);
    }
    return res;
  }
};

// class Solution {
// public:
//   vector<vector<string>> groupAnagrams(vector<string> &strs) {
//     unordered_map<string, vector<string>> mp;
//     for (const string &str : strs) {
//       vector<int> v(26, 0);
//       for (const unsigned char &c : str) {
//         v[c - 'a']++;
//       }
//       string key = to_string(v[0]);
//       for (int i = 1; i < 26; i++) {
//         key += ',' + to_string(v[i]);
//       }
//       mp[key].push_back(str);
//     }
//     vector<vector<string>> res;
//     for (const auto &pair : mp) {
//       res.push_back(pair.second);
//     }
//     return res;
//   }
// };
