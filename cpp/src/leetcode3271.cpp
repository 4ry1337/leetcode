#include <cstdio>
#include <string>

std::string stringHash(std::string s, int k) {
  int n = s.length();
  std::string result = "";
  for (int i = 0; i < n; i += k) {
    int pos = 0;
    for (int j = 0; j < k; j++) {
      pos += ((int)s.at(i + j) - 97);
    }
    pos %= 26;
    result += (char)(pos + 97);
  }
  return result;
}
