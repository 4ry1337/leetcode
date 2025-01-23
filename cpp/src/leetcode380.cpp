#include <cstdlib>
#include <unordered_map>
#include <vector>

using namespace std;

class RandomizedSet {
private:
  vector<int> vals;
  unordered_map<int, int> idx;

public:
  RandomizedSet() {}

  bool insert(int val) {
    if (idx.find(val) != idx.end()) {
      return false;
    }
    idx[val] = vals.size();
    vals.push_back(val);
    return true;
  }

  bool remove(int val) {
    if (idx.find(val) == idx.end()) {
      return false;
    }
    const int index = idx[val];
    idx[vals.back()] = index;
    idx.erase(val);
    vals[index] = vals.back();
    vals.pop_back();
    return true;
  }

  int getRandom() { return vals[rand() % vals.size()]; }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
