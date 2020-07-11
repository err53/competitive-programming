#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 10003;
int N, S, sumT[MM], sumF[MM], dp[MM];
deque<int> dq;
double slope(int j, int k) {
  return (double)(dp[k] - dp[j]) / (sumT[k] - sumT[j]);
}
int main() {
  cin >> N >> S;
  for (int i = 1; i <= N; i++) {
    cin >> sumT[i] >> sumF[i];
  }
  for (int i = N; i >= 1; i--) {
    sumT[i] += sumT[i + 1];
    sumF[i] += sumF[i + 1];
  }
  memset(dp, 0x3f, sizeof dp);
  dp[N + 1] = 0;
  dq.push_back(N + 1);
  for (int i = N; i >= 1; i--) {
    while (dq.size() > 1 && slope(dq[0], dq[1]) <= sumF[i])
      dq.pop_front();
    int k = dq[0];
    dp[i] = dp[k] + (S + sumT[i] - sumT[k]) * sumF[i];
    while (dq.size() > 1 &&
           slope(dq[dq.size() - 2], dq.back()) >= slope(dq.back(), i))
      dq.pop_back();
    dq.push_back(i);
  }
  cout << dp[1];
}