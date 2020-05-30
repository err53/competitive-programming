#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5 + 5, LOG = 17;
int q, n, rt[MM], x[MM], y[MM], dia[MM], dep[MM], anc[LOG][MM];
char op;
int lca(int u, int v) {
  if (dep[u] < dep[v])
    swap(u, v);
  for (int i = LOG - 1; i >= 0; i--) {
    if (dep[anc[i][u]] >= dep[v])
      u = anc[i][u];
  }
  if (u == v)
    return u;
  for (int i = LOG - 1; i >= 0; i--)
    if (anc[i][u] != anc[i][v])
      u = anc[i][u], v = anc[i][v];
  return anc[0][u];
}
int dist(int u, int v) { return dep[u] + dep[v] - 2 * dep[lca(u, v)]; };
int main() {
  cin >> q;
  for (int i = 1, v; i <= q; i++) {
    cin >> op >> v;
    if (op == 'B') {
      n++;
      if (v == -1) {
        rt[n] = x[n] = y[n] = n;
        dep[n] = dia[n] = 0;
      } else {
        rt[n] = rt[v];
        dep[n] = dep[v] + 1;
        anc[0][n] = v;
        for (int j = 1; j < LOG; j++) {
          anc[j][n] = anc[j - 1][anc[j - 1][n]];
        }
        int r = rt[n], dx = dist(x[r], n), dy = dist(y[r], n);
        if (dx > dia[r]) {
          dia[r] = dx;
          y[r] = n;
        }
        if (dy > dia[r]) {
          dia[r] = dy;
          x[r] = n;
        }
      }
    } else
      cout << max(dist(v, x[rt[v]]), dist(v, y[rt[v]])) << "\n";
  }
}