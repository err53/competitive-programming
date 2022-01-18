#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2002;
int N, M, h[MM], stk[MM], tp;
ll ans;
char g[MM];
ll calc(int n) { return 1LL * n * (n + 1) / 2; }
int main() {
  scanf("%d %d", &N, &M);
  for (int i = 1; i <= N; i++) {
    scanf("%s", g + 1);
    tp = 0;
    for (int j = 1; j <= M+1; j++) {
      if (g[j] == '.')
        h[j]++;
      else
        h[j] = 0;
      while (tp && h[j] < h[stk[tp]]) {
        int idx = stk[tp--], rit = j - idx, lft = idx - (tp > 0 ? stk[tp] : 0);
        ans += calc(h[idx]) * (lft * calc(rit) + rit * calc(lft) - lft * rit);
      }
      stk[++tp] = j;
    }
  }
  printf("%lld\n", ans);
}