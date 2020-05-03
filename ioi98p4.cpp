#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e4 + 3;
struct event {
  int x, lo, hi, v;
};

int n, ans, cnt[2 * MM];
vector<event> ex, ey;

bool cmp(event a, event b) { return a.x < b.x || (a.x == b.x && a.v > b.v); }

void func() {
  sort(ex.begin(), ex.end(), cmp);
  for (event e : ex) {
    if (e.v > 0) {
      for (int i = e.lo; i < e.hi; i++) {
        if (++cnt[i] == 1) {
          ans++;
        }
      }
    } else {
      for (int i = e.lo; i < e.hi; i++) {
        if (--cnt[i] == 0) ans++;
      }
    }
  }
}

int main() {
  cin >> n;
  for (int i = 1, a, b, c, d; i <= n; i++) {
    cin >> a >> b >> c >> d;
    a += MM;
    b += MM;
    c += MM;
    d += MM;
    ex.push_back({a, b, d, 1});
    ex.push_back({c, b, d, -1});
    ey.push_back({b, a, c, 1});
    ey.push_back({d, a, c, -1});
  }
  func();
  swap(ex, ey);
  func();
  cout << ans << endl;
}