#include <bits/stdc++.h>
using namespace std;

#define ll long long

int task3() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  ll l, s;
  cin >> n >> l >> s;
  vector<pair<ll, ll>> taxis(n, {-1, 0}); // {last_time, last_position}
  vector<int> res;

  for (int i = 0; i < n; i++) {
    string event;
    cin >> event;
    if (event == "TAXI") {
      ll t, id, pos;
      cin >> t >> id >> pos;
      taxis[id] = {t, pos};
    } else {
      ll t, id, pos, time;
      cin >> t >> id >> pos >> time;
      res.clear();
      for (int j = 0; j < n; j++) {
        if (taxis[j].first == -1 || taxis[j].first > t)
          continue;
        ll dis = (pos - taxis[j].second + l) % l;
        if (dis <= time * s)
          res.push_back(j);
      }

      if (res.empty()) {
        cout << -1 << endl;
      } else {
        for (int j = 0; j < min((int)res.size(), 5); ++j) {
          cout << res[j];
          if (j < min((int)res.size(), 5) - 1)
            cout << " ";
        }
        cout << endl;
      }
    }
  }
  return 0;
}
