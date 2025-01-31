#include <iostream>

using namespace std;

#define ll long long

int main() {
  ll p, q;
  cin >> p >> q;
  if (q % p != 0) {
    cout << 0 << endl;
    return 0;
  }

  q /= p;

  ll ans = 0;
  for (ll i = 2; i * i <= q; ++i) {
    if (q % i == 0) {
      ++ans;
      while (q % i == 0) {
        q /= i;
      }
    }
  }
  ans += (q != 1);

  cout << (1ll << ans) << endl;
  return 0;
}
