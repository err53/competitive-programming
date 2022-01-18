#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, a[16][16];
ll dp[1 << 16], val[1 << 16];

// https://codeforces.com/blog/entry/45223
int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int mask = 1; mask < (1 << N); mask++) {
    for (int i = 0; i < N; i++) {
      if (mask >> i & 1) {
        for (int j = i + 1; j < N; j++) {
          if (mask >> j & 1)
            val[mask] += a[i][j];
        }
      }
    }
  }
  for (int mask = 1; mask < (1 << N); mask++) {
    dp[mask] = val[mask];
    for (int k = (mask - 1) & mask; k > 0; k = (k - 1) & mask) {
      dp[mask] = max(dp[mask], dp[k] + dp[mask ^ k]);
    }
  }
  printf("%lld\n", dp[(1 << N) - 1]);
}