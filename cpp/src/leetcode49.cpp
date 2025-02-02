#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

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
class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> mp;
    for (auto &s : strs) {
      string temp = s;
      sort(temp.begin(), temp.end());
      mp[temp].emplace_back(s);
    }
    vector<vector<string>> res;
    for (auto &[_, val] : mp)
      res.emplace_back(val);
    return res;
  }
};
