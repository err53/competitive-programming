#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 2000001;

int N;
ll L;
ll len[MM], dp[MM];

ll x(ll i, ll j) { return j - i + len[j] - len[i - 1]; }

ll cost(ll i, ll j) { return (x(i, j) - L) * (x(i, j) - L); }

int main() {
  scanf("%d%lld", &N, &L);

  for (int i = 1; i <= N; i++) {
    scanf("%lld", len + i);
    len[i] += len[i - 1];
  }

  int prv = 0;
  fill(begin(dp), end(dp), LONG_LONG_MAX);
  dp[0] = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = prv; j < i; j++) {
      ll tmp = cost(j + 1, i) + dp[j];
      if (tmp < dp[i]) {
        dp[i] = tmp;
        prv = j;
      }
    }
  }

  cout << dp[N] << endl;
}