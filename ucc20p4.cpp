#include <bits/stdc++.h>
using namespace std;

const int MM = 10e6+3;
int N, ans = INT_MAX, arr[MM], dp[MM];

int two(int a, int b) {
  return a + b - min({a, b}) * 0.25;
}
int three(int a, int b, int c) {
  return a + b + c - min({a, b, c}) * 0.5;
}

int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
  }
  memset(dp, 0x3f, sizeof dp);
  dp[0] = 0;
  for (int i = 1; i <= N; i++) {
    dp[i] = dp[i-1] + arr[i];
    if (i >= 2) {
      dp[i] = min(dp[i], dp[i-2] + two(arr[i-1], arr[i]));
    }
    if (i >= 3) {
      dp[i] = min(dp[i], dp[i-3] + three(arr[i-2], arr[i-1], arr[i]));
    }
  }
  cout << dp[N] << endl;
}