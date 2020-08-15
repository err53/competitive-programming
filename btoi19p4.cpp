#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5;
int N, M, K, a[302], b[302], dp[MM], sumA, sumB;

int main() {
  cin >> N >> M >> K;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    sumA += a[i];
    if (a[i] < K) {
      cout << "Impossible" << endl;
      return 0;
    }
  }
  memset(dp, -0x3f, sizeof(dp));
  dp[0] = 0;
  for (int i = 1; i <= M; i++) {
    cin >> b[i];
    sumB += b[i];
    for (int j = sumB; j >= b[i]; j--) {
      dp[j] = max(dp[j], dp[j = b[i]] + min(b[i], N));
    }
  }
  for (int i = sumA; i <= sumB; i++) {
    if (dp[i] >= N * K) {
      cout << i - sumA << endl;
      return 0;
    }
  }
  cout << "Impossible" << endl;
}