#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5 + 5, LOG = 18;
int N, Q;
ll st[LOG][MM], val;

ll rmq(int l, int r) {
  int lvl = log2(r - l + 1);
  return min(st[lvl][l], st[lvl][r - (1 << lvl) + 1]);
}

int main() {
  cin >> N >> Q;
  for (int i = 1; i <= N; i++) {
    cin >> st[0][i];
  }
  for (int i = 1; i < LOG; i++) {
    for (int j = 1; j + (1 << i) - 1 <= N; j++) {
      st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    }
  }
  for (int i = 1, lft, rit; i <= Q; i++) {
    cin >> val >> lft >> rit;
    while (lft <= rit) {
      int lo = lft, hi = rit, pos = 0;
      while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (rmq(lo, mid) <= val) {
          pos = mid;
          hi = mid - 1;
        } else {
          lo = mid + 1;
        }
      }
      if (pos == 0) {
        break;
      }
      val %= st[0][pos];
      lft = pos + 1;
    }
    cout << val << "\n";
  }
  return 0;
}