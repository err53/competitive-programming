#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long ll;
const int MM = 2e5 + 5, mod = 1e9 + 7;
int H, W, N;
ll f[MM], inv[MM], dp[3003];
vector<pi> p;

ll quick_pow(ll x, int exp) {
  if (exp == 0)
    return 1;
  ll t = quick_pow(x, exp / 2);
  t = t * t % mod;
  return (exp & 1) ? t * x % mod : t;
}

ll comb(int n, int k) { return f[n] * inv[k] % mod * inv[n - k] % mod; }

int main() {
  scanf("%d%d%d", &H, &W, &N);
  f[0] = inv[0] = 1;
  for (int i = 1; i <= H + W; i++)
    f[i] = f[i - 1] * i % mod;
  inv[H + W] = quick_pow(f[H + W], mod - 2);
  for (int i = H + W - 1; i >= 1; i--) {
    inv[i] = (i + 1) * inv[i + 1] % mod;
  }
  for (int i = 1, x, y; i <= N; i++) {
    scanf("%d%d", &x, &y);
    p.push_back({x - 1, y - 1});
  }
  p.push_back({H - 1, W - 1});
  sort(p.begin(), p.end());
  for (int i = 0; i < p.size(); i++) {
    int x = p[i].first, y = p[i].second;
    dp[i] = comb(x + y, x);
    for (int j = 0; j < i; j++) {
      int xj = p[j].first, yj = p[j].second;
      if (yj <= y)
        dp[i] =
            (dp[i] - dp[j] * comb(x - xj + y - yj, x - xj) % mod + mod) % mod;
    }
  }
  printf("%lld\n", dp[N]);
}