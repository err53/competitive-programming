#include <bits/stdc++.h>
using namespace std;

const int MM = 10e6;
int N, seq[MM], dpa[MM], dpb[MM], ans = 1;

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> seq[i];
  }
  fill(dpa, dpa+N, 1);
  fill(dpb, dpb+N, 1);
  for (int i = 1; i < N; i++) {
    for (int j = 0; j < i; j++) {
      if (seq[j] < seq[i]) {
        dpa[i] = max(dpa[i], dpb[j] + 1);
      }
      if (seq[j] > seq[i]) {
        dpb[i] = max(dpb[i], dpa[j] + 1);
      }
    }
    ans = max({ans, dpa[i], dpb[i]});
  }
  cout << ans << endl;
}