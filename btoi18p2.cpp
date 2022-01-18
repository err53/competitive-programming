#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5 + 5;
int N, K, R, b[MM], a[MM], freq[MM], tot, ans = 1e9;
int main() {
  cin >> N >> K >> R;
  tot = R;
  for (int i = 1; i <= N; i++)
    cin >> a[i];
  for (int i = 1, x, y; i <= R; i++) {
    cin >> x >> y;
    b[x] = y;
  }
  for (int l = 1, r = 1; r <= N; r++) {
    if (++freq[a[r]] == b[a[r]])
      tot--;
    while (1 <= r && freq[a[l]] > b[a[l]]) {
      freq[a[l]]--;
      l++;
    }
    if (tot == 0)
      ans = min(ans, r - l + 1);
  }
  if (ans != 1e9)
    cout << ans << endl;
  else
    cout << "impossible" << endl;
}