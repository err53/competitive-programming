#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
int A, B, C;
ll eff[1000005], dp[1000005];

ll com(ll x) { return (A * x * x + B * x + C); }

int main() {
  cin >> N >> A >> B >> C;
  for (int i = 1; i <= N; i++) {
    ll tmp;
    cin >> tmp;
    eff[i] = eff[i - 1] + tmp;
  }
  int lst = 1;
  for (int i = 1; i <= N; i++) {
    dp[i] = com(eff[i] - eff[i - 1]) + dp[i - 1];
    for (int j = lst; j < i; j++) {
      ll tmp = com(eff[i] - eff[j - 1]) + dp[j - 1];
      if (tmp > dp[i]) {
        dp[i] = tmp;
        lst = j;
      }
    }
  }
  cout << dp[N] << endl;
}